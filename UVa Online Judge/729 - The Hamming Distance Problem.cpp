#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int n,h;
        cin >> n >> h;

        char *s = new char(n);
        for(int i=0; i<n-h; i++)
            s[i] = '0';

        for(int i=n-h; i<n; i++)
            s[i]= '1';

        do{
            for(int i=0; i<n; i++)
                cout << s[i];
            cout << endl;
        }while(next_permutation(s, s+n));

        if(testcases) cout << endl;
    }
    return 0;
}