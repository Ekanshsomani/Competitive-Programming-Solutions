#include <bits/stdc++.h>
using namespace std;

int price[101], favor[101], n;
int budget;

inline int maxFavor()
{
    int budgup = budget;
    if(budgup > 1800)
        budgup += 200;

    vector<int> memo(budgup+1, 0);
    for(int i=0; i<n; i++)
        for(int j=budgup; j>=price[i]; j--)
            if(memo[j-price[i]]>0 or j==price[i])
                memo[j] = max(memo[j], memo[j-price[i]]+favor[i]);

    if(budget>1800 and budget<2001)
    {
        int maxFavor = *max_element(memo.begin(), memo.begin()+budget);
        for(int i=2001; i<=budgup; i++)
            maxFavor = max(maxFavor, memo[i]);
        return maxFavor;
    }

    return *max_element(memo.begin(), memo.end());
}

int main()
{
    while(cin >> budget >> n)
    {
        for(int i=0; i<n; i++)
            cin >> price[i] >> favor[i];

        printf("%d\n", maxFavor());
    }
    return 0;
}