// 10895

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    int n, m;
    while(cin >> m >> n)
    {
        vector<vector<pair<int, int>>> transpose(n);

        for(int i=1; i<=m; i++)
        {
            int r;
            cin >> r;
            vector<int> indices(r);

            for(int j=0; j<r; j++) cin >> indices[j];

            for(auto it: indices)
            {
                int value;
                cin >> value;
                transpose[it-1].push_back({i, value});
            }
        }

        cout << n << ' ' << m << endl;

        // printing matrix
        // int prev;
        // queue<int> values;
        for(auto it: transpose)
        {
            int r = it.size();
            if(r>0)
            {
            cout << r << ' ';
            for(int i=0; i<r-1; i++) cout << it[i].first << ' ';
            cout << it[r-1].first << endl; 

            for(int i=0; i<r-1; i++) cout << it[i].second << ' ';
            cout << it[r-1].second << endl;
            }
            else cout << r << endl << endl;
        }
    }
    return 0;
}
