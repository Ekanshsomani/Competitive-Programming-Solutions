#include <iostream>
#include <cstring>
using namespace std;

// [200][11][21] -> (idx, remaning numbers, sum) -> output totalPos
int memo[200][11][22];
int divisor, n;
int values[200];

int validPos(int idx,  int rn, int sum)
{
    if(rn==0)
    {
        if(!sum)
            return 1;
        return 0;
    }
    if((idx>=n) or (n-idx)<rn)
        return 0;

    int& ans = memo[idx][rn][sum];
    if(ans != -1)
        return ans;

    int newSum{ sum + values[idx] };
    newSum %= divisor;
    if(newSum<0)
        newSum += divisor;

    int withoutNext = validPos(idx+1, rn, sum);
    int withNext = validPos(idx+1, rn-1, newSum);

    return ans = withNext + withoutNext;
}

int main()
{
    int q;
    int test{1};
    while(cin >> n >> q and (n or q))
    {
        for(int i=0; i<n; i++)
            cin >> values[i];
        
        printf("SET %d:\n", test++);
        for(int i=1; i<=q; i++)
        {
            int m;
            cin >> divisor >> m;
            memset(memo, -1, sizeof memo);
            printf("QUERY %d: %d\n", i, validPos(0, m, 0));
        }
    }
    return 0;
}