#include <bits/stdc++.h>

using namespace std;

const int INF = 100;

int am[51][51];

int main()
{
    int test{1};
    int V, E;
    while(cin >> V >> E and (V or E))
    {
        printf("Network %d: ", test++);
        unordered_map<string, int> nameid;
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
                am[i][j] = INF;
            am[i][i] = 0;
        }

        int idx = 0;
        while(E--)
        {
            int u, v;
            string a, b;
            cin >> a >> b;
            if(not nameid.count(a)) {nameid[a] = idx; idx++;}
            if(not nameid.count(b)) {nameid[b] = idx; idx++;}

            u = nameid[a]; v = nameid[b];
            am[u][v] = am[v][u] = 1;
        }

        if(idx<V) {printf("DISCONNECTED\n\n"); continue;}

        for(int k=0; k<V; k++)
            for(int u=0; u<V; u++)
                for(int v=0; v<V; v++)
                    if(am[u][v] > am[u][k]+am[k][v])
                        am[u][v] = am[u][k]+am[k][v];

        int separation{0};
        for(int u=0; u<V; u++)
            for(int v=0; v<V; v++)
                separation = max(separation, am[u][v]);
        
        if(separation==INF)
            printf("DISCONNECTED\n\n");
        else
            printf("%d\n\n", separation);
    }
    return 0;
}