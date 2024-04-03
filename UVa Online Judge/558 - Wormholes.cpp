#include <bits/stdc++.h>

#define INF 10000000

using namespace std;

typedef pair<int, int> ii;

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int n, m;
        cin >> n >> m;

        vector<ii> adj[n];
        while(m--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
        }

        vector<int> dist(n, INF);
        dist[0] = 0;
        for(int i=0; i<n-1; i++)
        {
            bool modified {false};
            for(int u=0; u<n; u++)
                if(dist[u]!=INF)
                    for(auto &[v, w]: adj[u])
                    {
                        if(dist[u]+w >= dist[v]) continue;
                        dist[v] = dist[u]+w;
                        modified = true;
                    }
            if(not modified) break;
        }

        bool hasNegativeCycle{false};
        for(int u=0; u<n; u++)
        {
            if(dist[u]!=INF)
                for(auto &[v, w]: adj[u])
                    if(dist[u]+w < dist[v])
                    {
                        hasNegativeCycle = true;
                        break;
                    }
            if(hasNegativeCycle) break;
        }

        if(hasNegativeCycle) printf("possible\n");
        else printf("not possible\n");
    }
    return 0;
}