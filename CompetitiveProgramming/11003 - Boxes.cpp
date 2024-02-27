#include <bits/stdc++.h>
using namespace std;

int weight[1000], capacity[1000], n;

int maxSize()
{
    int maxCap = *max_element(capacity, capacity+n);

    vector<int> memo(maxCap+1, 0);
    for(int i=0; i<n; i++)
        for(int j=0; j<=capacity[i]; j++)
            if((j+weight[i])<=maxCap)
                memo[j] = max(memo[j], memo[j+weight[i]]+1);
            else if(!memo[j])
                memo[j] = 1;

    return *max_element(memo.begin(), memo.end());
}

int main()
{
    while(cin >> n and n)
    {
        for(int i=0; i<n; i++)
            cin >> weight[i] >> capacity[i];

        printf("%d\n", maxSize());
    }
    return 0;
}