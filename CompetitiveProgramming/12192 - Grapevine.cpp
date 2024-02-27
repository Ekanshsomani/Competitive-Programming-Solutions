#include <iostream>
#include <algorithm>
using namespace std;

// [L,U]

int main()
{
    int properties[500][500], bounds[1000];
    int n, m;
    while(cin >> n >> m and n)
    {
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin >> properties[i][j];
        
        int maxside, minposition;

        int q;
        cin >> q;
        while(q--)
        {
            int l, u;
            cin >> l >> u;

            maxside = 0;
            for(int i=0; i<n; i++)
            {
                minposition = lower_bound(properties[i], properties[i]+m, l) - properties[i];
                for(int length = maxside; length<n; length++)
                {
                    if(n<=i+length or m<=minposition+length or u < properties[i+length][minposition+length])
                        break;
                    
                    maxside = max(maxside, length+1);
                }
            }

            cout << maxside << endl;
        }
        cout << '-' << endl;
    }
    return 0;
}