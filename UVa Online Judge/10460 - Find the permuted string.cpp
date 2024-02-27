#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    double factorial[27];
    factorial[0] = factorial[1] = 1;
    for(int i=2; i<27; i++) factorial[i] = i*factorial[i-1];

    double pIndex;
    string s;

    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        string res = "";

        cin >> s >> pIndex;

        pIndex--;
        double total = factorial[s.length()];

        for(int i=0; i<s.length(); i++)
        {
            
            total /= i+1;
            
            int insertIdx = pIndex/total;
            pIndex = fmod(pIndex, total);
            res.insert(res.begin()+insertIdx, s[i]);
        }
        cout << res << endl;
    }
    return 0;
}