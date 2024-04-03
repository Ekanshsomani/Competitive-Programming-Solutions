#include <bits/stdc++.h>

using namespace std;

// one box = 1000 metres

int x[105], y[105];
bool am[105][105];

inline double dist(int u, int v)
{
    return sqrt((x[u]-x[v])*(x[u]-x[v]) + (y[u]-y[v])*(y[u]-y[v]));
}

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int V;
        cin >> V;
        V += 2;
        for(int i=0; i<V; i++)
            cin >> x[i] >> y[i];

        for(int u=0; u<V; u++)
        {
            for(int v=0; v<u; v++)
                am[u][v] = am[v][u] = dist(u, v)<=1000;
            am[u][u] =  true;
        }

        for(int k=0; k<V; k++)
            for(int u=0; u<V; u++)
                for(int v=0; v<V; v++)
                    am[u][v] |= am[u][k]&am[k][v];
        
        if(am[0][V-1]) printf("happy\n");
        else printf("sad\n");
    }
    return 0;
}