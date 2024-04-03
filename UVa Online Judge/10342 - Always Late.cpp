#include <bits/stdc++.h>

using namespace std;

const int INF = 1e4;

// find second shortest path
// How:
    // first find am
    // then create a second matrix... maybe
    // iterate over k, u, v for second matrix
    // if am[u][v] < am[u][k]+am[k][v] < sm[u][v]

    // I can visit a vertex multiple times
    // that is am[u][k]*2+am[u][v];
    // and also use an edge many times
    // so maybe somwhere along the shortest path from u to v
    // i could just visit a node outside and then comeback

int am[100][100], sm[100][100], parent[100][100];

int main()
{
    int test{1};
    int V, E;
    while(cin >> V >> E)
    {
        for(int u=0; u<V; u++)
        {
            for(int v=u+1; v<V; v++)
            {
                am[u][v] = am[v][u] = sm[u][v] = sm[v][u] = INF;
                parent[u][v] = u; parent[v][u] = v;
            }
            parent[u][u] = u;
            am[u][u] = 0;
            sm[u][u] = INF;
        }

        while(E--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            am[u][v] = am[v][u] = w;
        }

        for(int k=0; k<V; k++)
            for(int u=0; u<V; u++)
                for(int v=0; v<V; v++)
                    if(am[u][v] > am[u][k]+am[k][v])
                    {
                        am[u][v] = am[u][k]+am[k][v];
                        parent[u][v] = parent[k][v];
                    }
        // for(int u=0; u<V; u++)
        //     for(int v=0; v<V; v++)
        //         if(am[u][v]!=INF)
        //             sm[u][v] = 3*am[u][v];

        for(int k=0; k<V; k++)
            for(int u=0; u<V; u++)
                for(int v=0; v<V; v++)
                    if(not (am[u][v]==INF or am[u][k]==INF or am[k][v]==INF))
                    {
                        int d = am[u][k]+am[k][v];
                        if(d != am[u][v] and d < sm[u][v])
                            sm[u][v] = d;
                        // d = am[u][k]*2 + am[u][v];
                        // if(d > am[u][v] and d < sm[u][v])
                        //     sm[u][v] = d;
                        // if(sm[u][v] > sm[u][k]+sm[k][v])
                        //     sm[u][v] = sm[u][k]+sm[k][v];
                    }

        for(int u=0; u<V; u++)
            for(int v=0; v<V; v++)
            {
                int node = v;
                while(node!=u)
                {
                    for(int k=0; k<V; k++)
                    {
                        int d = am[u][v]+am[node][k]*2;
                        if(d<sm[u][v] and d!=am[u][v])
                            sm[u][v] = d;
                        d = am[u][node]+am[node][k]+am[k][v];
                        if(d!=am[u][v] and d<sm[u][v])
                            sm[u][v] = d;
                    }
                    node = parent[u][node];
                }
                for(int k=0; k<V; k++)
                {
                    int d = am[u][v]+am[node][k]*2;
                    if(d>am[u][v] and d<sm[u][v])
                        sm[u][v] = d;
                    d = am[u][node]+am[node][k]+am[k][v];
                    if(d>am[u][v] and d<sm[u][v])
                        sm[u][v] = d;
                }
            }

        // for(int k=0; k<V; k++)
        //     for(int u=0; u<V; u++)
        //         for(int v=0; v<V; v++)
        //             if(sm[u][v] > sm[u][k]+sm[k][v])
        //                 sm[u][v] = sm[u][k]+sm[k][v];

        printf("Set #%d\n", test++);
        int queries;
        cin >> queries;
        while(queries--)
        {
            int u, v;
            cin >> u >> v;
            if(sm[u][v]==INF) printf("?\n");
            else printf("%d\n", sm[u][v]);
        }
    }
    return 0;
}