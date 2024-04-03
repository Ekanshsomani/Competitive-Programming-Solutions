#include <bits/stdc++.h>
using namespace std;

// states -> int n, back;
unsigned long long memo[62][62];
unsigned int back;

unsigned long long countCalls(int n)
{
    if(n<=1) return 1;

    unsigned long long &ans = memo[n][back];
    if(ans != 0)
        return ans;
    
    ans = 1;
    for(int i=1; i<=back; i++) 
        ans += countCalls(n-i);

    return ans;
}

int main()
{
    int n, test{1};
    while(cin >> n >> back and n < 61)
        printf("Case %d: %llu\n", test++, countCalls(n));
    return 0;
}