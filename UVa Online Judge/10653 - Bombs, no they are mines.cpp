#include <bits/stdc++.h>
using namespace std;

int rows, columns;

inline bool isInside(int r, int c)
{
    return (r>-1 and c>-1 and r<rows and c<columns);
}

int main()
{
    int step[4][2]{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    while(cin >> rows >> columns and (rows or columns))
    {
        vector<vector<bool>> vis(rows, vector<bool>(columns, false));

        int bombRows;
        cin >> bombRows;
        while(bombRows--)
        {
            int r, c, rb;
            cin >> r >> rb;
            while(rb--)
            {
                cin >> c;
                vis[r][c] = true;
            }
        }

        int startRow, startColumn;
        cin >> startRow >> startColumn;
        int destRow, destColumn;
        cin >> destRow >> destColumn;
        
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {startRow, startColumn}});
        while(!q.empty())
        {
            pair<int, int> pos = q.front().second;
            int time = q.front().first;
            q.pop();

            if(pos.first==destRow and pos.second==destColumn)
            {
                printf("%d\n", time);
                break;
            }

            for(int i=0; i<4; i++)
            {
                int r = pos.first + step[i][0];
                int c = pos.second + step[i][1];
                if(isInside(r, c) and not vis[r][c])
                {
                    vis[r][c] = true;
                    q.push({time+1, {r, c}});
                }
            }
        }
    }
    return 0;
}