#include <bits/stdc++.h>

using namespace std;

typedef pair<int, double> id;
typedef pair<double, int> di;
typedef vector<id> vid;
typedef vector<double> vd;


int main()
{
    int V, E;
    while(cin >> V >> E and (V or E))
    {
        vid adj[V];
        while(E--)
        {
            int u, v;
            double w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        vd dist(V, 0.0); dist[0] = 1.0; // INF = 1e9 here
        set<di> pq; // balanced BST version
        for (int u = 0; u < V; ++u) // dist[u] = INF
            pq.emplace(-dist[u], u); // but dist[s] = 0

        while (!pq.empty())  // main loop
        {
            auto [d, u] = *pq.begin(); // shortest unvisited u
            pq.erase(pq.begin());
            d *= -1;

            if(u==(V-1))
                break;
            
            for (auto &[v, w] : adj[u]) 
            { // all edges from u
                if (d*w <= dist[v]) continue; // not improving, skip
                pq.erase(pq.find({-dist[v], v})); // erase old pair
                dist[v] = d*w; // relax operation
                pq.emplace(-dist[v], v); // enqueue better pair
            }
        }

        printf("%.4f\n", dist[V-1]);
    }

    return 0;
}