// 10102

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m;
    while(cin >> m)
    {
        vector<pair<int, int>> ones, threes;

        string colors;
        for(int i=1; i<=m; i++)
        {
            cin >> colors;
            for(int j=1; j<=m; j++)
            {
                
                if(colors[j-1] == '1') ones.push_back({i,j});
                else if(colors[j-1] == '3') threes.push_back({i, j});
            }
        }

        int max{0};
        for(auto ito: ones)
        {
            int min{abs(threes[0].first-ito.first) + abs(threes[0].second-ito.second)};
            for(auto itt: threes)
            {
                int steps(abs(itt.first-ito.first)+abs(itt.second-ito.second));
                if(steps<min) min = steps;
            }
            if(min>max) max = min;
        }

        cout << max << endl;
    }
    return 0;
}