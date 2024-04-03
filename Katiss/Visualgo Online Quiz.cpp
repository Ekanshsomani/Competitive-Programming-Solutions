#include <bits/stdc++.h>

using namespace std;

// what's the suggestion:
    // do dijkstra to create dist
    // reverse the graph
    // now backtrack over all nodes that have dist[v]+w = dist[u]

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;

vii *backadj;
vi dist;
int start;

inline int backtrack(int node)
{
    if(node==start)
        return 1;
    
    int ans = 0;
    for(auto [v, w]: backadj[node])
        if((dist[v]+w)==dist[node])
            ans += backtrack(v);
    return ans;
}

int main()
{
    int V, E;
    cin >> V >> E;

    backadj = new vii[V];
    vii adj[V];
    while(E--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        backadj[v].emplace_back(u, w);
    }
    int target;
    cin >> start >> target;

    dist.assign(V, INF); dist[start] = 0; //
    set<ii> pq; // balanced BST version
    for (int u = 0; u < V; ++u) // dist[u] = INF
        pq.emplace(dist[u], u); // but dist[s] = 0

    // sort the pairs by non-decreasing distance from s
    while (!pq.empty())  // main loop
    {
        auto [d, u] = *pq.begin(); // shortest unvisited u
        pq.erase(pq.begin());
        
        for (auto &[v, w] : adj[u]) 
        { // all edges from u
            if (dist[u]+w >= dist[v]) continue; // not improving, skip
            pq.erase(pq.find({dist[v], v})); // erase old pair
            dist[v] = dist[u]+w; // relax operation
            pq.emplace(dist[v], v); // enqueue better pair
        }
    }

    printf("%d\n", backtrack(target));

    return 0;
}