#include <bits/stdc++.h>

using namespace std;

// start bfs at one of the special position
// try looping back once you have visited all of them

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int n, k;
        cin >> n >> k;

        ii special[k];
        map<ii, int> specIdx;
        for(int i=0; i<k; i++)
        {
            cin >> special[i].first >> special[i].second;
            specIdx[special[i]] = i;
        }

        
    }
    return 0;
}