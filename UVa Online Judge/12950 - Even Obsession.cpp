#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;

int main()
{
    int V, E;
    while(cin >> V >> E)
    {
        V++;
        vii adj[V];

        while(E--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        vi dist(V, INF); dist[1] = 0; //
        set<ii> pq; // balanced BST version
        for (int u = 0; u < V; ++u) // dist[u] = INF
            pq.emplace(dist[u], u); // but dist[s] = 0

        // sort the pairs by non-decreasing distance from s
        while (!pq.empty())  // main loop
        {
            auto [d, u] = *pq.begin(); // shortest unvisited u
            pq.erase(pq.begin());

            if(u==V-1 and d!=INF)
            {
                printf("%d\n", d);
                break;
            }

            
            for (auto &[u1, w1] : adj[u]) 
                for(auto &[v, w2]: adj[u1])
                { // all edges from u
                    if (d+w1+w2 >= dist[v]) continue; // not improving, skip
                    pq.erase(pq.find({dist[v], v})); // erase old pair
                    dist[v] = d+w1+w2; // relax operation
                    pq.emplace(dist[v], v); // enqueue better pair
                }
        }

        if(dist[V-1]==INF)
            printf("-1\n");
    }
}