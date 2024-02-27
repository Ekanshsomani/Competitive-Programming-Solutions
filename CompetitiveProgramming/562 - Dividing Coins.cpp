#include <iostream>
#include <vector>
using namespace std;

int coins[105], n, sum;

inline int minDiff()
{
    int half{sum>>1};
    
    vector<int> memo(half+1, 0);
    for(int i=0; i<n; i++)
        for(int j=half; j>=coins[i]; j--)
            memo[j] = max(memo[j], memo[j-coins[i]]+coins[i]);

    int maxSum = 0;
    for(int i=0; i<=half; i++)
        maxSum = max(maxSum, memo[i]);
    
    return sum-2*maxSum;
}

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        sum = 0;
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> coins[i];
            sum += coins[i];
        }

        printf("%d\n", minDiff());
    }
    return 0;
}