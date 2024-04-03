#include <bits/stdc++.h>
using namespace std;

int x[11], y[11], dist[11][11];
int nodes;

int allVis;
int memo[11][1<<11];

int tsp(int pos, int vis)
{
    if(vis==allVis)
        return dist[0][pos];

    /**/
    int &ans = memo[pos][vis];
    if(ans!=-1)
        return ans;

    ans = 2000000000;
    for(int i=1; i<nodes; i++)
        if(not (vis&(1<<i)))
            ans = min(ans, tsp(i, vis|(1<<i))+dist[i][pos]);
    return ans;
}

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int n, m;
        cin >> n >> m;
        cin >> x[0] >> y[0];
        cin >> nodes;
        nodes++;
        for(int i=1; i<nodes; i++)
            cin >> x[i] >> y[i];

        for(int i=0; i<nodes; i++)
            for(int j=i+1; j<nodes; j++)
            {
                dist[i][j] = abs(x[j]-x[i])+abs(y[j]-y[i]);
                dist[j][i] = dist[i][j];
            }

        memset(memo, -1, sizeof memo);
        allVis = (1<<nodes) - 1;
        
        printf("The shortest path has length %d\n", tsp(0, 1));
    }
    return 0;
}