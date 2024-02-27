#include <iostream>
#include <bitset>
using namespace std;

// start iterating
// every time you find a '.' that's not covered, place a crow ahead of it 
// and cover relevant position

int main()
{
    int n, crows;
    char a;
    bitset<100> covered;

    int testcases;
    cin >> testcases;
    for(int t=1; t<=testcases; t++)
    {
        crows = 0;
        covered.reset();

        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> a;
            if(a=='.' and covered[i]==0)
            {
                crows++;
                for(int j=i; j<(i+3) and j<n; j++)
                    covered[j] = 1;
            }
        }

        printf("Case %d: %d\n", t, crows);
    }
    return 0;
}