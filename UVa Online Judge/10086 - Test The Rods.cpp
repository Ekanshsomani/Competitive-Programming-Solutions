#include <bits/stdc++.h>
using namespace std;

int sites;
int samples[30], nCost[30][21], bCost[30][21];
int memo[30][301], path[30][301];
// states -> idx, ncpc(left) -> return minCost

int minCost(int idx, int ncpc, int bcew)
{
    if(idx==sites)
        return 0;
    
    int &ans = memo[idx][ncpc];
    if(ans!=-1)
        return ans;
    
    ans = 1e6;
    int upto = min(ncpc, samples[idx]);
    int from = max(0, samples[idx]-bcew); // samples[idx]-j <= bcew;

    for(int j=from; j<=upto; j++)
    {
        if ((minCost(idx+1, ncpc-j, bcew-(samples[idx]-j)) + nCost[idx][j] + 
            bCost[idx][samples[idx]-j]) < ans )
            {
                ans = 
                    minCost(idx+1, ncpc-j, bcew-(samples[idx]-j)) + nCost[idx][j] + 
                    bCost[idx][samples[idx]-j];
                path[idx][ncpc] = j;
            }
    }
    return ans;
}

int main()
{
    int ncpc, bcew;
    while(cin >> ncpc >> bcew and (ncpc or bcew))
    {
        
        cin >> sites;
        for(int i=0; i<sites; i++)
        {
            cin >> samples[i];
            nCost[i][0] = 0;
            bCost[i][0] = 0;
            for(int j=0; j<samples[i]; j++)
                cin >> nCost[i][j+1];
            for(int j=0; j<samples[i]; j++)
                cin >> bCost[i][j+1];
        }

        memset(memo, -1, sizeof memo);
        printf("%d\n", minCost(0, ncpc, bcew));
        for(int i=0; i<sites; i++)
        {
            cout << path[i][ncpc] << (i==(sites-1) ? "\n\n" : " ");
            ncpc -= path[i][ncpc];
        }
    }
    return 0;
}