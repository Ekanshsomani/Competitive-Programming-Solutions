#include <iostream>
#include <cstring>
using namespace std;

int states[105][105];


int ways(int sum, int numbers)
{
    if(numbers==1) return 1;
    else if(sum==0) return 1;

    int &ans = states[sum][numbers];
    if(ans!=-1) return ans;
    else
    {
        ans = 0;
        for(int i=0; i<=sum; i++)
        {
            ans += ways(sum-i, numbers-1);
            if(ans>=1000000) ans %= 1000000;
        }
        return ans;
    }
    return ans;
}

int main()
{
    memset(states, -1, sizeof states);

    int n, k;
    while(cin >> n >> k and (n or k))
    {
        printf("%d\n", ways(n, k));
    }
    return 0;
}