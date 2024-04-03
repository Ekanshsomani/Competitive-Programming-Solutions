#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int, int> iiii;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;

// pq sort -> based on reach time, node;

int main()
{
    int test{0};
    int V, E, queries, start;
    while(cin >> V >> E >> queries >> start and (V or E or queries))
    {
        vector<iiii> adj[V];

        // can only traverse at a particular time
        while(E--)
        {
            int u, v, t0, P, d;
            cin >> u >> v >> t0 >> P >> d;
            adj[u].emplace_back(v, t0, P, d);
        }

        vi dist(V, INF); dist[start] = 0; //
        set<ii> pq; // balanced BST version
        for (int u = 0; u < V; ++u) // dist[u] = INF
            pq.emplace(dist[u], u); // but dist[s] = 0

        // sort the pairs by non-decreasing distance from s
        while (!pq.empty())  // main loop
        {
            auto [d, u] = *pq.begin(); // shortest unvisited u
            pq.erase(pq.begin());
            
            for (auto &[v, t0, p, w] : adj[u]) 
            {
                int reachTime;

                if(p==0 and d>t0) continue;
                else if(d<=t0)
                    reachTime = t0+w;
                else if((d-t0)%p!=0)
                    reachTime = ((d-t0)/p + 1)*p + t0 + w;
                else
                    reachTime = d+w;

                if (reachTime >= dist[v]) continue; // not improving, skip
                pq.erase(pq.find({dist[v], v})); // erase old pair
                dist[v] = reachTime; // relax operation
                pq.emplace(dist[v], v); // enqueue better pair
            }
        }

        if(test++) printf("\n");
        while(queries--)
        {
            int node;
            cin >> node;
            if(dist[node]==INF)
                printf("Impossible\n");
            else
                printf("%d\n", dist[node]);
        }
    }
    return 0;
}