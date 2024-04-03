#include <bits/stdc++.h>
using namespace std;

long long memo[5][30001];
int coin[5]{1, 5, 10, 25, 50};

long long countWays(int idx, int remMoney)
{
    if(idx==5)
        if(remMoney)
            return 0;
        else
            return 1;
    if(remMoney==0)
        return 1;
    long long &ans = memo[idx][remMoney];
    if(ans!=-1)
        return ans;
    
    ans = countWays(idx+1, remMoney);
    if(remMoney>=coin[idx])
        ans += countWays(idx, remMoney-coin[idx]);
    return ans;
}

int main()
{
    memset(memo, -1, sizeof memo);

    int amount;
    while(cin >> amount)
    {
        long long ways{0};
        ways  = countWays(0, amount);

        if(ways==1)
            printf("There is only 1 way ");
        else
            printf("There are %lld ways ", ways);
        printf("to produce %d cents change.\n", amount);
    }
    return 0;
}