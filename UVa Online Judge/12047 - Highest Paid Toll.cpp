#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;
int V;

inline vi dijkstra(vii adj[], int start)
{
    vi dist(V, INF); dist[start] = 0; //
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
            if (d+w >= dist[v]) continue; // not improving, skip
            pq.erase(pq.find({dist[v], v})); // erase old pair
            dist[v] = d+w; // relax operation
            pq.emplace(dist[v], v); // enqueue better pair
        }
    }

    return dist;
}
int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int E, start, target, p;
        cin >> V >> E >> start >> target >> p;
        V++;

        vii adj[V], reverseAdj[V];
        vector<iii> edgeList;

        while(E--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            reverseAdj[v].emplace_back(u, w);
            edgeList.emplace_back(u, v, w);
        }

        vi dist = dijkstra(adj, start);
        vi reverseDist = dijkstra(reverseAdj, target);

        int maxToll{-1};
        for(auto [u, v, w]: edgeList)
            if((dist[u]+reverseDist[v]+w) <= p)
                maxToll = max(maxToll, w);
        
        printf("%d\n", maxToll);
    }
    return 0;
}