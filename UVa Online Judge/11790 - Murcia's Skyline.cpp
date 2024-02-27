#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for(int t=1; t<=testcases; t++)
    {
        int n;
        cin >> n;
        vector<int> heights(n), widths(n);
        for(int i=0; i<n; i++)
            cin >> heights[i];
        for(int i=0; i<n; i++)
            cin >> widths[i];

        vector<int> lis(n, 0), lds(n, 0);
        int miw{0}, mdw{0};
        for(int i=0; i<n; i++)
        {
            lis[i] = widths[i];
            lds[i] = widths[i];
            for(int j=0; j<i; j++)
                if(heights[i]>heights[j])
                    lis[i] = max(lis[i], lis[j]+widths[i]);
                else if(heights[i]<heights[j])
                    lds[i] = max(lds[i], lds[j]+widths[i]);
            miw = max(miw, lis[i]);
            mdw = max(mdw, lds[i]);
        }

        if(miw>=mdw)
            printf("Case %d. Increasing (%d). Decreasing (%d).\n", t, miw, mdw);
        else
            printf("Case %d. Decreasing (%d). Increasing (%d).\n", t, mdw, miw);
    }
    
    return 0;
}