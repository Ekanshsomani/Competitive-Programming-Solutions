#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int INF = 1e8;
bitset<10000> vis;

int main()
{
    int V, E, A, K;
    while(cin >> V >> E >> A >> K and (V or E or A or K))
    {
        vii adj[V];
        vis.reset();

        while(E--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        vi dist(V, INF);
        priority_queue<ii, vector<ii>, greater<ii>> pq; // balanced BST version
        while(A--)
        {
            int start;
            cin >> start; start--;
            dist[start] = 0;
            vis[start] = true;

            pq.emplace(0, start);

            // sort the pairs by non-decreasing distance from s
            while (!pq.empty())  // main loop
            {
                auto [d, u] = pq.top(); // shortest unvisited u
                pq.pop();
                
                if(d>=K or d>dist[u])
                    continue;

                for (auto &[v, w] : adj[u]) 
                { // all edges from u
                    if ((d+w) >= dist[v] or (d+w) >= K) continue; // not improving, skip
                    vis[v] = true;
                    dist[v] = dist[u]+w; // relax operation
                    pq.emplace(dist[v], v); // enqueue better pair
                }
            }

            // int count = count_if(next(dist.begin()), dist.end(), [K](int x){return x>=K;});
            printf("%d\n", V - vis.count());
        }
        printf("\n");
    }
    return 0;
}