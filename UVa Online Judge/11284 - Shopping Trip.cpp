#include <bits/stdc++.h>
using namespace std;

int dist[51][51];
int indices[13], benefit[13]; // idx, benefit;
int nodes, operas;
int memo[13][1<<13], gotAll;

inline void shortestPaths()
{
    for(int k=0; k<nodes; k++)
        for(int i=0; i<nodes; i++)
            for(int j=0; j<nodes; j++)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
}

int maxBenefit(int pos, int taken)
{
    if(taken==gotAll)
        return -dist[0][indices[pos]];

    int &ans = memo[pos][taken];
    if(ans != -1)
        return ans;

    ans = -dist[0][indices[pos]];
    for(int i=0; i<operas; i++)
        if(not( taken & (1<<i)))
        {
            int b = benefit[i]-dist[indices[i]][indices[pos]];
            b += maxBenefit(i, taken | (1<<i));
            ans = max(ans, b);
        }
    return ans;
}

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int roads;
        cin >> nodes >> roads;
        nodes++;

        for(int i=0; i<nodes; i++)
        {
            for(int j=i+1; j<nodes; j++)
                dist[i][j] = dist[j][i] = 1e8;
            dist[i][i] = 0;
        }
        for(int i=0; i<roads; i++)
        {
            int node1, node2;
            double c;
            cin >> node1 >> node2 >> c;

            dist[node1][node2] = min(dist[node1][node2], (int)round(c*100));
            dist[node2][node1] = dist[node1][node2];
        }
        shortestPaths();

        cin >> operas;
        operas++;
        benefit[0] = 0;
        indices[0] = 0;
        for(int i=1; i<operas; i++)
        {
            double b;
            cin >> indices[i] >> b;
            benefit[i] = (int)round(b*100.0);
        }

        gotAll = (1<<operas)-1;
        memset(memo, -1, sizeof memo);
        
        int b = maxBenefit(0, 1);
        if(b<=0)
            printf("Don't leave the house\n");
        else
            printf("Daniel can save $%d.%02d\n", b/100, b%100);
    }
    return 0;
}