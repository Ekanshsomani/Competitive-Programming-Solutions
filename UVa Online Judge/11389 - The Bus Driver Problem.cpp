#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int morn[100], aftern[100];

    int n, d, r;
    while(cin >> n >> d >> r and (n or d or r))
    {
        for(int i=0; i<n; i++)
            cin >> morn[i];
        
        for(int i=0; i<n; i++)
            cin >>  aftern[i];

        sort(morn, morn+n);
        sort(aftern, aftern+n);

        int extra{0};
        for(int i=0; i<n; i++)
            if(morn[i]+aftern[n-(i+1)] > d)
                extra += r*(morn[i]+aftern[n-(i+1)]-d);

        printf("%d\n", extra);
    }
    return 0;
}