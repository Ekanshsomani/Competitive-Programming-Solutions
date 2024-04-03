#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

const int INF = 0x3f3f3f3f;

inline int getDist(const int &ub, const int &vb)
{
    int a = vb-ub;
    return a*a*a;
}

int main()
{
    int test{1};
    int V;
    while(cin >> V)
    {
        printf("Set #%d\n", test++);

        if(V==0)
        {
            int E, u, v;
            cin >> E;
            while(E--)
                cin >> u >> v;
            cin >> E;
            while(E--)
                cin >> u;
            continue;
        }

        int busyness[V];
        for(int i=0; i<V; i++)
            cin >> busyness[i];

        vii adj[V];

        int E;
        cin >> E;
        while(E--)
        {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].emplace_back(v, getDist(busyness[u], busyness[v]));
        }

        vi dist(V, INF); 
        dist[0] = 0; // INF = 1e9 here
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

        vb vis(V, false);
        queue<int> q;
        for (int u = 0; u < V; ++u) // one more pass to check
            if (dist[u] != INF)
                for (auto &[v, w] : adj[u]) // C++17 style
                    if ((dist[v] > dist[u]+w) and not vis[v]) // should be false
                    {
                        dist[v] = -INF;
                        vis[v] = true;
                        q.push(v);
                        while(not q.empty())
                        {
                            int a = q.front();
                            q.pop();

                            for(auto &[b, d]: adj[a])
                                if(not vis[b])
                                {
                                    vis[b] = true;
                                    dist[b] = -INF;
                                    q.push(b);
                                }
                        }
                    }

        int queries;
        cin >> queries;
        while(queries--)
        {
            int node;
            cin >> node; node--;
            if(dist[node]<3 or dist[node]==INF)
                printf("?\n");
            else
                printf("%d\n", dist[node]);
        }
    }   
    return 0;
}