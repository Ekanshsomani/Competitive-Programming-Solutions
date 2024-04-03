#include <bits/stdc++.h>
using namespace std;

int barLength;
long long memo[51][51];

long long symbols(int length, int bars)
{
    if(length==0)
        if(bars==0)
            return 1;
        else
            return 0;
    if(bars<=0)
        return 0;

    long long &ans = memo[length][bars];
    if(ans != -1)
        return ans;

    int m = min(length, barLength);
    ans = 0;
    for(int i=1; i<=m; i++)
        ans += symbols(length-i, bars-1);
    return ans;
}

int main()
{
    int length, bars;
    while(cin >> length)
    {
        cin >> bars >> barLength;
        memset(memo, -1, sizeof memo);
        printf("%lld\n", symbols(length,  bars));
    }
    return 0;
}