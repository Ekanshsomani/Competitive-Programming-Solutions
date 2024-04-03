#include <bits/stdc++.h>

using namespace std;

// if i am given the minimum distance between all pairs of nodes
// then how can I find the simplest possible graph for those node(minimum travelling cost)
// can I use floyd ?
    // if some other vertex can get me there then take that path; make this one zero
    // 

int sum[100][100], adj[100][100];

int main()
{
    int testcases;
    cin >> testcases;
    for(int t=1; t<=testcases; t++)
    {
        int V;
        cin >> V;
        for(int u=0; u<V; u++)
        {
            for(int v=0; v<u; v++)
            {
                cin >> sum[u][v]; 
                sum[v][u] = sum[u][v];
                adj[u][v] = adj[v][u] = 1;
            }
            adj[u][u] = sum[u][u] = 0;
        }

        bool possible{true};
        for(int k=V-1; k>-1 and possible; k--)
            for(int u=0; u<V and possible; u++)
                for(int v=0; v<V and possible; v++)
                    if(u == v or u == k or v == k) ;
                    else if(sum[u][v] == sum[u][k]+sum[k][v])
                        adj[u][v] = 0;
                    else if(sum[u][v] > sum[u][k]+sum[k][v])
                        possible = false;

        printf("Case #%d:\n", t);
        if(possible)
        {
            int E{0};
            for(int u=0; u<V; u++)
                for(int v=0; v<u; v++)
                    E += adj[u][v];

            printf("%d\n", E);
            for(int u=0; u<V; u++)
                for(int v=u+1; v<V; v++)
                    if(adj[u][v])
                        printf("%d %d %d\n", u+1, v+1, sum[u][v]);
        }
        else
            printf("Need better measurements.\n");
        printf("\n");
    }
    return 0;
}