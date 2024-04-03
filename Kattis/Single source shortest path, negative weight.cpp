#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;

const int INF = 3e7;

int main()
{
    int V, E, queries, start, test{0};
    while(cin >> V >> E >> queries >> start and (V or E or queries or start))
    {
        vector<iii> edges;
        while(E--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            edges.emplace_back(u, v, w);
        }

        vi dist(V, INF); 
        dist[start] = 0; // INF = 1e9 here
        for (int i = 0; i < V-1; ++i)  // total O(V*E)
        {
            bool modified{false};
            for(auto &[u, v, w]: edges)
                if(dist[u]!=INF and dist[u]+w < dist[v])
                {
                    dist[v] = dist[u]+w; // relax operation
                    modified = true; // optimization
                }
            if (not modified) break; // optimization
        }

        for (int i = 0; i < V; ++i) // one more pass to check
            for(auto &[u, v, w]: edges)
                if (dist[u]!=INF and dist[u]+w < dist[v]) // should be false
                    dist[v] = -INF;

        if(test++) printf("\n");
        while(queries--)
        {
            int u;
            cin >> u;
            if(dist[u]==INF)
                printf("Impossible\n");
            else if(dist[u]==-INF)
                printf("-Infinity\n");
            else
                printf("%d\n", dist[u]);
        }
    }
    return 0;
}