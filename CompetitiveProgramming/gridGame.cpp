// 11553
// the key thing that one needs to realize here is that Alice's choice
// is irrelevant. As long Bob keeps his column corresponding to rows consistent
// , Alice pattern of choosing doesn't matter.

#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

int grid[8][8], p[8];

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int n;
        cin >>  n;

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin >> grid[i][j];

        for(int i=0; i<n; i++)
            p[i] = i;
        
        int sum{INT_MAX};
        do{
            int s{0};
            for(int i=0; i<n; i++)
                s += grid[i][p[i]];
            sum = min(sum, s);
        }while(next_permutation(p, p+n));

        cout << sum << endl;
    }
    return 0;
}