#include <bits/stdc++.h>
using namespace std;

int memo[10][1000];
int wind[10][1000];
int n;

int minFuel(int idx, int alt)
{
    if(idx==n)
        if(alt)
            return 1e6;
        else
            return 0;
    
    int &ans = memo[alt][idx];
    if(ans != -1)
        return ans;

    if((n-idx)==alt)
        return ans = minFuel(idx+1, alt-1)+20-wind[alt][idx];

    ans = minFuel(idx+1, alt) + 30;
    if(alt<9)
        ans = min(ans, minFuel(idx+1, alt+1)+ 60);
    if(alt)
        ans = min(ans, minFuel(idx+1, alt-1) + 20);

    return ans -= wind[alt][idx];
}

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        cin >> n;
        n /= 100;

        for(int i=9; i>-1; i--)
            for(int j=0; j<n; j++)
                cin >> wind[i][j];

        memset(memo, -1, sizeof memo);
        printf("%d\n\n", minFuel(0, 0));
    }
    return 0;
}