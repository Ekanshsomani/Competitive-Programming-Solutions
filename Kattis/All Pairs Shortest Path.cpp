/*
** Kattis **
** Problem Code: allpairspath **
** User: Ekansh Somani **
*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e7;

int am[150][150];

int main()
{
    int V, E, queries;
    while(cin >> V >> E >> queries and (V or E or queries))
    {
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
                am[i][j] = INF;
            am[i][i] = 0;
        }

        while(E--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            am[u][v] = min(am[u][v],w);
        }

        for(int k=0; k<V; k++)
            for(int u=0; u<V; u++)
                for(int v=0; v<V; v++)
                    if(am[u][k]<INF and am[k][v]<INF)
                        am[u][v] = min(am[u][v], am[u][k]+am[k][v]);

        for(int u=0; u<V; u++)
            for(int v=0; v<V; v++)
                for(int k=0; k<V; k++)
                    if(am[k][k]<0 and am[u][k]!=INF and am[k][v]!=INF)
                    {
                        am[u][v] = -INF;
                        break;
                    }
                
        while(queries--)
        {
            int u, v;
            cin >> u >> v;
            if(am[u][v] == INF) printf("Impossible\n");
            else if(am[u][v]== -INF) printf("-Infinity\n");
            else printf("%d\n", am[u][v]);
        }
        printf("\n");
    }
    return 0;
}