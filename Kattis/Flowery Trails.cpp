#include <bits/stdc++.h>

using namespace std;

const int INF = 2e7;


typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

int V;

inline void dijkstra(int start, vi& dist, vii adj[])
{
    dist[start] = 0;
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
}

int main()
{
    int E;
    cin >> V >> E;

    vii adj[V];
    while(E--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if(w==0 and u==v)
            continue;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vi dist1(V, INF), dist2(V, INF);
    dijkstra(0, dist1, adj);
    dijkstra(V-1, dist2, adj);
    
    int flower{0};
    for(int u=0; u<V; u++)
        for(auto [v, w]: adj[u])
            if(dist1[u]+w+dist2[v] == dist1[V-1])
                flower += w;
    printf("%d\n", 2*flower);
    return 0;
}