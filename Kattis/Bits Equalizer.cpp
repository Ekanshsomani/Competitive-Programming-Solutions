#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for(int t=1; t<=testcases; t++)
    {
        string a, b;
        cin >> a >> b;
        printf("Case %d: ", t);

        if(a.length()!=b.length())
        {
            printf("-1\n");
            continue;
        }

        int l = a.length();
        int overall{0}, zeroToOne{0}, oneToZero{0}, qMarksToOne{0};
        for(int i=0; i<l; i++)
            if(a[i]!=b[i])
            {
                overall++;
                if(a[i]=='0')
                    zeroToOne++;
                else if(a[i]=='1')
                    oneToZero++;
                else if(a[i]=='?' and b[i]=='1')
                    qMarksToOne++;
            }

        if(oneToZero > (qMarksToOne+zeroToOne))
            printf("-1\n");
        else
            printf("%d\n", overall - min(oneToZero, zeroToOne));
    }
    return 0;
}