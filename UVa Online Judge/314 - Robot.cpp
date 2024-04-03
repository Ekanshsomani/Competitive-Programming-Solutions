#include <bits/stdc++.h>

#define ii pair<int, int>

using namespace std;

bool vis[50][50][4], bomb[51][51];

int columns, rows;

inline bool isValid(int r, int c)
{
    return (r>0 and c>0 and r<rows and c<columns);
}

int main()
{
    int step[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    unordered_map<string, int> dirIdx{
        {"north", 0}, {"west", 1}, 
        {"south", 2}, {"east", 3}
    };

    while(cin >> rows >> columns and (rows or columns))
    {
        memset(vis, false, sizeof vis);
        memset(bomb, false, sizeof bomb);

        for(int i=0; i<rows; i++)
            for(int j=0; j<columns; j++)
            {
                int obstacle;
                cin >> obstacle;
                if(obstacle)
                {
                    bomb[i][j] = true;
                    bomb[i+1][j] = true;
                    bomb[i][j+1] = true;
                    bomb[i+1][j+1] = true;
                }
            }

        string dir;
        ii source, target;
        cin >> source.first >> source.second;
        cin >> target.first >> target.second;
        cin >> dir;

        queue<pair<int, ii>> q;
        if(not isValid(source.first, source.second) or bomb[source.first][source.second])
        {
            printf("-1\n");
            continue;
        }
        vis[source.first][source.second][dirIdx[dir]] = true;
        q.push({dirIdx[dir], source});
        int time{-1};

        bool pathExist{false};
        while(not (q.empty() or pathExist))
        {
            int l = q.size();
            while(l--)
            {
                int x, y;
                tie(x, y) = q.front().second;
                int idx = q.front().first;
                q.pop();

                if(ii(x, y)==target)
                {
                    pathExist = true;
                    break;
                }

                bool &visit = vis[x][y][(idx+1)%4];
                if(not visit)
                {
                    visit = true;
                    q.push({(idx+1)%4, {x, y}});
                }

                bool &visited = vis[x][y][(idx+3)%4];
                if(not visited)
                {
                    visited = true;
                    q.push({(idx+3)%4, {x, y}});
                }

                for(int i=1; i<4; i++)
                {
                    int r = x+i*step[idx][0];
                    int c = y+i*step[idx][1];
                    if((not isValid(r, c)) or bomb[r][c])
                        break;
                    if(not vis[r][c][idx])
                    {
                        vis[r][c][idx] = true;
                        q.push({idx, {r, c}});
                    }
                }
            }
            time++;
        }

        if(pathExist)
            printf("%d\n", time);
        else
            printf("-1\n");
    }
    return 0;
}