#include <bits/stdc++.h>
using namespace std;

int levels, rows, columns;

inline bool isInside(int l, int r, int c)
{
    return (l>-1 and r>-1 and c>-1 and l<levels and r<rows and c<columns);
}

int main()
{
    int step[6][3]{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};

    while(cin >> levels >> rows >> columns and (levels or rows or columns))
    {
        bool vis[levels][rows][columns];

        pair<int, pair<int, int>> start, end;        
        char c;
        for(int i=0; i<levels; i++)
            for(int j=0; j<rows; j++)
                for(int k=0; k<columns; k++)
                {
                    cin >> c;
                    switch(c)
                    {
                        case '.':
                            vis[i][j][k] = false;
                        break;
                        case '#':
                            vis[i][j][k] = true;
                        break;
                        case 'S':
                            vis[i][j][k] = true;
                            start = {i, {j, k}};
                        break;
                        case 'E':
                            vis[i][j][k] = false;
                            end = {i, {j, k}};
                        break;
                    }
                }
        
        bool escape{false};
        queue<pair<int, pair<int, pair<int, int>>>> q;
        q.push({0, start});

        while(not q.empty())
        {
            pair<int, pair<int, int>> pos = q.front().second;
            int time = q.front().first;
            q.pop();

            if(pos == end)
            {
                escape = true;
                printf("Escaped in %d minute(s).\n", time);
                break;
            }

            for(int i=0; i<6; i++)
            {
                int l = pos.first + step[i][0];
                int r = pos.second.first + step[i][1];
                int c = pos.second.second + step[i][2];
                if(isInside(l, r, c) and not vis[l][r][c])
                {
                    vis[l][r][c] = true;
                    q.push({time+1, {l, {r, c}}});
                }
            }
        }

        if(not escape)
            printf("Trapped!\n");
    }
    return 0;
}