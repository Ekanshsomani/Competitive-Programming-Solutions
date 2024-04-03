#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;

int main()
{
    int V, E;
    while(cin >> V >> E and (V or E))
    {
        V++;

        vii adj[V];
        while(E--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, -w);
        }

        vi dist(V, INF); 
        dist[1] = 0; // INF = 1e9 here
        for (int i = 0; i < V-1; ++i)  // total O(V*E)
        {
            bool modified = false; // optimization
            for (int u = 0; u < V; ++u) // these two loops = O(E)
                if (dist[u] != INF) // important check
                    for (auto &[v, w] : adj[u])  // C++17 style
                    {
                        if (dist[u]+w >= dist[v]) continue; // not improving, skip
                        dist[v] = dist[u]+w; // relax operation
                        modified = true; // optimization
                    }
            if (!modified) break; // optimization
        }

        bool hasNegativeCycle = false;
        for (int u = 0; u < V; ++u) // one more pass to check
            if (dist[u] != INF)
                for (auto &[v, w] : adj[u]) // C++17 style
                    if (dist[v] > dist[u]+w) // should be false
                        hasNegativeCycle = true; // if true => -ve cycle

        if(hasNegativeCycle)
            printf("Unlimited!\n");
        else
            printf("%d\n", -*min_element(dist.begin(), dist.end()));

    }
    return 0;
}