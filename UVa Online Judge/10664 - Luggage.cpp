#include <bits/stdc++.h>
using namespace std;

int memo[20][101];
int weight[20];
int sum, n;

bool isPos(int idx, int currsum)
{
    if(currsum==sum)
        return true;
    if(currsum>sum or idx==n)
        return false;
    
    int& ans = memo[idx][currsum];
    if(ans!=-1)
        return ans;

    return ans = (isPos(idx+1, currsum) or isPos(idx+1, currsum+weight[idx]));
}

int main()
{
    string line;
    int testcases;
    cin >> testcases;
    cin.ignore();
    
    while(testcases--)
    {
        getline(cin, line);
        istringstream ss(line);
        n = 0;
        sum = 0;

        while(ss >> weight[n])
        {
            sum += weight[n];
            n++;
        }

        if(sum&1)
        {
            printf("NO\n");
            continue;
        }
        memset(memo, -1, sizeof memo);

        sum >>= 1;
        if(isPos(0, 0))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}