#include <bits/stdc++.h>
using namespace std;

int memo[100][5001];
int shares[100], x, n;

// states -> (idx, shareSum) -> min((idx+1, shareSum), (idx+1, shareSum+shares[idx]))
// in memo (idx, shareSum) -> minimum possible sum of shares

int minSum(int idx, int shareSum)
{
    if(idx==n)
        if((shareSum+shares[x])>5000)
            return shareSum;
        else
            return 10000;

    if(idx==x)
        return minSum(idx+1, shareSum);

    if(shareSum>5000)
        return shareSum;
    
    int &ans = memo[idx][shareSum];
    if(ans!=-1)
        return ans;
    return ans = min(minSum(idx+1, shareSum), minSum(idx+1, shareSum+shares[idx]));
}

int main()
{
    while(cin >> n >> x and (n or x))
    {
        x--;
        for(int i=0; i<n; i++)
        {
            double val;
            cin >> val;
            shares[i] = val*100+1e-9;
        }

        if(shares[x]>5000)
        {
            printf("100.00\n");
            continue;
        }

        if(shares[x]==0)
        {
            printf("0.00\n");
            continue;
        }

        memset(memo, -1, sizeof memo);
        int ms{minSum(0, 0) + shares[x]};
        // printf("%d %d ", shares[x], ms);
        printf("%.2f\n", (100.00 * shares[x])/(1.00*ms) + 1e-9);
    }
    return 0;
}