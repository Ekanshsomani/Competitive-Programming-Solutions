#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

const int INF = 1e9;

int main()
{
    int V, E, queries, start, test{0};
    while(cin >> V >> E >> queries >> start and (V or E or queries or start))
    {
        vector<ii> adj[V];
        while(E--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
        }

        vector<int> dist(V, INF); dist[start] = 0; // INF = 1e9 here
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

        if(test++)
            printf("\n");
        while(queries--)
        {
            int u;
            cin >> u;
            if(dist[u]<INF)
                printf("%d\n", dist[u]);
            else
                printf("Impossible\n");
        }
    }
    return 0;
}