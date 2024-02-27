#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

pair<int, int> memo[31][1001];
int quantity[31], recTime[31];
int n;

pair<int, int> maxQty(int idx, int rt)
{
    pair<int, int> &ans = memo[idx][rt];
    if(idx==n or rt==0)
        ans = {0, 0};

    if(ans.first != -1)
        return ans;
    
    if((rt-recTime[idx])<0)
        ans = maxQty(idx+1, rt);
    else if( maxQty(idx+1, rt).first > (maxQty(idx+1, rt-recTime[idx]).first + 
    quantity[idx]))
        ans = memo[idx+1][rt];
    else
    {
        ans = memo[idx+1][rt-recTime[idx]];
        ans.first += quantity[idx];
        ans.second |= (1<<idx);
    }
    return ans;
}

int main()
{
    int depth[31];
    int time, factor;
    queue<pair<int, int>> q;

    int test{0};
    while(cin >> time >> factor)
    {
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> depth[i] >> quantity[i];
            recTime[i] = 3*factor*depth[i];
        }

        memset(memo, -1, sizeof memo);
        /*
        for(int i=0; i<=n; i++)
            for(int j=0; j<=time; j++)
                memo[i][j] = {-1, 0};
        /**/
        pair<int, int> ans = maxQty(0, time);

        int idx{0}, recovered{ans.second};
        while(recovered)
        {
            if(recovered&1)
                q.push({depth[idx], quantity[idx]});
            idx++;
            recovered >>= 1;
        }

        if(test++) printf("\n");
        printf("%d\n", ans.first);
        printf("%d\n", q.size());
        while(!q.empty())
        {
            printf("%d %d\n", q.front().first, q.front().second);
            q.pop();
        }
    }
    return 0;
}