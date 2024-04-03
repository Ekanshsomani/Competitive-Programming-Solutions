#include <bits/stdc++.h>

using namespace std;

double am[21][21][21];
int p[21][21][21];

// inline void printPath(int i, int j) 
// {
//     if (i != j) printPath(i, p[i][j]);
//     printf(" %d", i);
// }

// inline int pathSize(int i, int j)
// {
//     if (p[i][j]!=j) return 1 + pathSize(i, p[i][j]);
//     return 1;
// }

int main()
{
    int n;
    while(cin >> n)
    {
        memset(am, 0, sizeof am);
        memset(p, 0, sizeof p);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if(j!=i) cin >> am[i][j][0];
                else am[i][j][0] = 1;
                p[i][j][0] = i;
            }
        
        for(int s=1; s<n; s++)
            for(int k=0; k<n; k++)
                for(int u=0; u<n; u++)
                    for(int v=0; v<n; v++)
                    {
                        double d = am[u][k][s-1]*am[k][v][0];

                        if(am[u][v][s]<d)
                        {
                            am[u][v][s] = d;
                            p[u][v][s] = k;
                        }
                    }

        bool isProfit {false};
        for(int s=1; s<n and not isProfit; s++)
            for(int u=0; u<n; u++)
                if(am[u][u][s] > 1.01)
                {
                    isProfit = true;

                    stack<int> path;
                    int size = s;
                    path.push(p[u][u][s]);
                    while(size--)
                        path.push(p[u][path.top()][size]);
                    size = s+1;
                    while(size--)
                    {
                        cout << path.top()+1 << (size==0 ? "\n" : " ");
                        path.pop();
                    }

                    // int profit[s+1];
                    // profit[s] = p[u][u][s];
                    // for(int j=s-1; j>-1; j--)
                    //     profit[j] = p[u][profit[j+1]][j];
                    // for(int j=0; j<=s; j++)
                    //     printf("%d ", profit[j]+1);
                    // printf("%d\n", profit[0]+1);
                    break;
                }
        
        if(not isProfit)
            printf("no arbitrage sequence exists\n");

    }
    return 0;
}