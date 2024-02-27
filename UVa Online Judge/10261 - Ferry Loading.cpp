#include <iostream>
#include <unordered_map>
#include <bitset>
#include <cstring>
using namespace std;

int memo[200][10001];
int car[201], n, fl;
bitset<10001> port[200];

int maxLoading(int idx, int pl, int sl)
{
    if(idx==n)
        return 0;
    if((pl+car[idx])>fl and (sl+car[idx])>fl)
        return 0;

    int &ans = memo[idx][pl];
    if(ans!=-1)
        return ans;

    int atPort{0}, atStar{0};
    if((pl+car[idx])<=fl)
        atPort = 1+maxLoading(idx+1, pl+car[idx], sl);
    if((sl+car[idx])<=fl)
        atStar = 1+maxLoading(idx+1, pl, sl+car[idx]);

    if(atStar>atPort)
        ans = atStar;
    else
    {
        port[idx][pl] = 1;
        ans = atPort;
    }

    return ans;
}

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        cin >> fl;
        fl*= 100;
        n = 0;
        int cl;
        while((cin >> car[n]) and car[n])
            n++;
        
        memset(memo, -1, sizeof memo);
        int loaded{0};
        loaded = maxLoading(0, 0, 0);

        printf("%d\n", loaded);
        int pl{0};
        for(int i=0; i<loaded; i++)
            if(port[i][pl])
            {
                printf("port\n");
                pl += car[i];
            }
            else
                printf("starboard\n");
        
        if(testcases)
        {
            printf("\n");
            for(int i=0; i<n; i++)
                port[i].reset();
        }
    }
    return 0;
}