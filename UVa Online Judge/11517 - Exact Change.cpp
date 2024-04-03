#include <bits/stdc++.h>
using namespace std;

int coin[100], price, n;
pair<int, int> memo[100][10000];

pair<int, int> minChange(int idx, int sum)
{
    if(sum>=price)
        return {sum, 0};
    if(idx==n)
        return {1e5, 1e5};

    pair<int, int> &ans = memo[idx][sum];
    if(ans.first!=-1)
        return ans;

    pair<int, int> withNext, withoutNext;
    
    withNext = minChange(idx+1, sum+coin[idx]);
    withNext.second++;

    withoutNext = minChange(idx+1, sum);

    if(withNext.first<withoutNext.first)
        ans = withNext;
    else if(withNext.first==withoutNext.first and withNext.second<withoutNext.second)
        ans = withNext;
    else
        ans = withoutNext;
    return ans;
}

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        cin >> price >> n;
        for(int i=0; i<n; i++)
            cin >> coin[i];

        memset(memo, -1, sizeof(memo));
        pair<int, int>  ans = minChange(0, 0);
        printf("%d %d\n", ans.first, ans.second);
    }
}