#include <iostream>
using namespace std;

int main()
{
    long long prices[100][100];

    int testcases;
    cin >> testcases;
    for(int t=1; t<=testcases; t++)
    {
        int n, m, k;
        cin >> n >> m >> k;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                
                cin >> prices[i][j];
                long long &s = prices[i][j];

                if(i) s += prices[i-1][j];
                if(j) s += prices[i][j-1];
                if(i and j) s -= prices[i-1][j-1];
            }

        int maxArea{0};
        long long minPrice{0};
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if((n-i)*(m-j) < maxArea) break;
                for(int x=i; x<n; x++)
                    for(int y=j; y<m; y++)
                    {
                        int currentArea{(x+1-i)*(y+1-j)}; 
                        if(currentArea < maxArea) continue;

                        long long currPrice{prices[x][y]};
                        if(i) currPrice -= prices[i-1][y];
                        if(j) currPrice -= prices[x][j-1];
                        if(currPrice>k) continue;
                        if(i and j) currPrice += prices[i-1][j-1];

                        if(currPrice<=k)
                        {
                            minPrice = (currentArea>maxArea) ? 
                                currPrice : min(minPrice, currPrice);
                            maxArea = currentArea;
                        }
                    }
            }
        
        printf("Case #%d: %d %lld\n", t, maxArea, minPrice);

    }
    return 0;
}