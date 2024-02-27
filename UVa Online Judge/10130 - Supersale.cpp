#include <iostream>
#include <cstring>
using namespace std;

int memo[1001][31];
int price[1001], weight[1001], n;

int maxValue(int idx, int remWeight)
{
    if(idx==n or remWeight==0)
        return 0;

    int &ans = memo[idx][remWeight];
    if(ans!=-1)
        return ans;

    if(remWeight>=weight[idx])
        ans = maxValue(idx+1, remWeight-weight[idx])+price[idx];
    
    ans = max(ans, maxValue(idx+1, remWeight));
    return ans;
}

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> price[i] >> weight[i];

        int queries, sum{0};
        cin >> queries;
        while(queries--)
        {
            memset(memo, -1, sizeof memo);

            int maxWeight;
            cin >> maxWeight;
            sum += maxValue(0, maxWeight);
        }
        printf("%d\n", sum);
    }
    return 0;
}