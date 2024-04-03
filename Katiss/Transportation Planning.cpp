#include <bits/stdc++.h>

using namespace std;

// total commute time = sum of all values in am (or just the upper-right half)
// build one road which reduces above the most
// how can I go about it
    // first compute am for existing roads
    // after that see if adding any edge improves it

const double INF = 1e5;

double am[100][100];
int x[100], y[100];

inline double getDist(int u, int v)
{
    return sqrt((x[v]-x[u])*(x[v]-x[u]) + (y[v]-y[u])*(y[v]-y[u]));
}

int main()
{
    int V;
    while(cin >> V and V)
    {
        for(int i=0; i<V; i++)
            cin >> x[i] >> y[i];

        for(int u=0; u<V; u++)
        {
            for(int v=0; v<V; v++)
                am[u][v] = INF;
            am[u][u] = 0;
        }

        int E;
        cin >> E;
        while(E--)
        {
            int u, v;
            cin >> u >> v;
            am[u][v] = am[v][u] = getDist(u, v);
        }

        for(int k=0; k<V; k++)
            for(int u=0; u<V; u++)
                for(int v=0; v<V; v++)
                    if(am[u][v] > am[u][k]+am[k][v])
                        am[u][v] = am[u][k]+am[k][v];

        double sum=0;
        for(int u=0; u<V; u++)
            for(int v=u+1; v<V; v++)
                sum += am[u][v];
        // printf("%f\n", sum);

        double maxReduction{0};
        int start, target;
        for(int i=0; i<V; i++)
            for(int j=i+1; j<V; j++)
            {
                double d = getDist(i, j);
                double reduction = 0;
                if(am[i][j] <= d) continue;

                for(int u=0; u<V; u++)
                    for(int v=u+1; v<V; v++)
                        reduction += (am[u][v] - min(am[u][v], min(am[u][i]+am[j][v], am[u][j]+am[i][v])+d));
                
                if(reduction > maxReduction)
                {
                    maxReduction =  reduction;
                    start = i; target = j;
                }
            }
        
        if(maxReduction>0)
            printf("adding %d %d reduces %f to %f\n", start, target, sum, sum-maxReduction);
        else
            printf("no addition reduces %f\n", sum);
    }
    return 0;
}