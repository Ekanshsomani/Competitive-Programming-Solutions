#include <bits/stdc++.h>

using namespace std;

const int INF = 1e7;

int boss[101][101], me[101][101];
bitset<101> notSafe;
int V;

inline void floydWarshall(int path[101][101])
{
    for(int k=1; k<=V; k++)
        if(not notSafe[k])
            for(int u=1; u<=V; u++)
                if(not notSafe[u])
                    for(int v=1; v<=V; v++)
                        if(not notSafe[v] and path[u][v] > path[u][k]+path[k][v])
                            path[u][v] = path[u][k]+path[k][v];
}

int main()
{
    while(cin >> V)
    {
        int E, bhome, office, yhome, market;
        cin >> E >> bhome >> office >> yhome >> market;
        
        for(int i=1; i<=V; i++)
        {
            for(int j=1; j<=V; j++)
                boss[i][j] = me[i][j] = INF;
            boss[i][i] = me[i][i] = 0;
        }
        while(E--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            boss[u][v] = boss[v][u] = me[u][v] = me[v][u] = w;
        }

        notSafe.reset();
        floydWarshall(boss);

        for(int i=1; i<=V; i++)
            if(boss[bhome][office] == boss[bhome][i]+boss[i][office])
                notSafe[i] = true;
        
        if(notSafe[yhome] or notSafe[market])
            printf("MISSION IMPOSSIBLE.\n");
        else
        {
            floydWarshall(me);
            int ans = me[yhome][market];
            if(ans == INF)
                printf("MISSION IMPOSSIBLE.\n");
            else
                printf("%d\n", ans);
        }
    }
    return 0;
}