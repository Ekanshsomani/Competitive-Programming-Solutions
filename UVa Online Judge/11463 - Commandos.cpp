#include <bits/stdc++.h>

using namespace std;

const int INF = 20000;
int am[100][100];

int main()
{
    int testcases;
    cin >> testcases;
    for(int t=1; t<=testcases; t++)
    {
        memset(am, INF, sizeof am);

        int V, E;
        cin >> V >> E;
        while(E--)
        {
            int u, v;
            cin >> u >> v;
            am[u][v] = 1;
            am[v][u] = 1;
        }

        for(int k=0; k<V; k++)
        {
            am[k][k] = 0;
            for(int i=0; i<V; i++)
                for(int j=0; j<V; j++)
                    am[i][j] = min(am[i][j], am[i][k]+am[k][j]);
        }
        
        int start, dest;
        cin >> start >> dest;

        int time{0};
        for(int i=0; i<V; i++)
            time = max(time, am[start][i]+am[i][dest]);
        printf("Case %d: %d\n", t, time);
    }
    return 0;
}