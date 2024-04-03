#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e6;

int V;
int energy[100];
bool vis[100];
vi adj[100];

inline bool isPath(int u)
{
    vis[u] = true;
    for(auto &v: adj[u])
        if(v==V-1)
            return true;
        else if(not vis[v] and isPath(v))
            return true;
    return false;
}

int main()
{
    memset(vis, false, sizeof vis);
    while(cin >> V and V>-1)
    {
        for(int i=0; i<V; i++)
        {
            cin >> energy[i];
            int E;
            cin >> E;
            while(E--)
            {
                int b;
                cin >> b; b--;
                adj[i].push_back(b);
            }
        }

        vi dist(V, -1);
        dist[0] = 100; // INF = 1e9 here
        for (int i = 0; i < V-1; ++i)  // total O(V*E)
        {
            bool modified = false; // optimization
            for (int u = 0; u < V; ++u) // these two loops = O(E)
                if (dist[u] > 0) // important check
                    for (auto &v : adj[u])  // C++17 style
                    {
                        if (dist[u]+energy[u] <= dist[v]) continue; // not improving, skip
                        dist[v] = dist[u]+energy[u]; // relax operation
                        modified = true; // optimization
                    }
            if (!modified) break; // optimization
        }

        bool hasPositiveCycle = false;
        for (int u = 0; u < V and not hasPositiveCycle; ++u)
            if (dist[u] > 0)
                for (auto &v: adj[u])
                    if (dist[v] < dist[u]+energy[u] and dist[u]+energy[u] > 0 and isPath(v))
                    {
                        hasPositiveCycle = true;
                        memset(vis, false, sizeof vis);
                        break;
                    }
        
        if(hasPositiveCycle or dist[V-1]>0) printf("winnable\n");
        else printf("hopeless\n");
    }
    return 0;
}