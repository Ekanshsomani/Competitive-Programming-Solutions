#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1e4
int memo[40][301][301], conventional[40], infoTech[40];
int n, target;
bool pos;

int minLength(int idx, int conSum, int eSum)
{
    int modulus = conSum*conSum + eSum*eSum;
    if(modulus==target)
    {
        pos = true;
        return 0;
    }
    if(modulus>target or idx==n)
        return MAX;

    int &ans = memo[idx][conSum][eSum];
    if(ans!=-1)
        return ans;
    if(conventional[idx]==0 and infoTech[idx]==0)
    {
        ans = minLength(idx+1, conSum, eSum);
        return ans;
    }
    ans = min(minLength(idx+1, conSum, eSum), 
    1 + minLength(idx, conSum + conventional[idx], eSum + infoTech[idx]));
    return ans;
}

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        cin >> n >> target;
        memset(memo, -1, sizeof memo);
        pos = false;
        target *= target;

        for(int i=0; i<n; i++)
            cin >> conventional[i] >> infoTech[i];
        
        int length = minLength(0, 0, 0);
        if(not pos)
            printf("not possible\n");
        else
            printf("%d\n", length);
    }    
    return 0;
}