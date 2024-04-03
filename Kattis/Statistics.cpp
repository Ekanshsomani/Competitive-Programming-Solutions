#include <bits/stdc++.h>

using namespace std;

const int INF = 1e7; // 10^9 = 1B is < 2^31-1

int main()
{
    int n, test{1};
    while(cin >> n)
    {
        int maxVal{-INF}, minVal(INF);
        while(n--)
        {
            int a;
            cin >> a;
            maxVal = max(a, maxVal);
            minVal = min(a, minVal);
        }

        printf("Case %d: %d %d %d\n", test++, minVal, maxVal, maxVal-minVal);
    }
    return 0;
}