#include <bits/stdc++.h>

#define ii pair<int, int>

using namespace std;

int rows, columns;

inline bool isInside(int r, int c)
{
    return (r>-1 and c>-1 and r<rows and c<columns);
}

int main()
{
    int step[4][2]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

    int x, y, r, c;
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        cin >> rows >> columns;
        bool vis[rows][columns];
        queue<ii> fire, joe;
        for(int i=0; i<rows; i++)
            for(int j=0; j<columns; j++)
            {
                char c;
                cin >> c;
                switch (c)
                {
                case '#':
                    vis[i][j] = true;
                break;
                case 'J':
                    joe.push({i, j});
                    vis[i][j] = true;
                break;
                case 'F':
                    fire.push({i, j});
                    vis[i][j] = true;
                break;
                default:
                    vis[i][j] = false;
                break;
                }
            }

        bool found{false};
        int time{0};
        while(not (found or joe.empty()))
        {
            int f = fire.size();
            while(f--)
            {
                tie(x, y) = fire.front();
                fire.pop();
                for(int i=0; i<4; i++)
                {
                    r = x + step[i][0];
                    c = y + step[i][1];
                    if(isInside(r, c) and not vis[r][c])
                    {
                        vis[r][c] = true;
                        fire.push({r, c});
                    }
                }
            }
            
            int j = joe.size();
            while(j--)
            {
                tie(x, y) = joe.front();
                joe.pop();
                if(x==0 or y==0 or x==rows-1 or y==columns-1)
                {
                    found = true;
                    break;
                }
                for(int i=0; i<4; i++)
                {
                    r = x + step[i][0];
                    c = y + step[i][1];
                    if(isInside(r, c) and not vis[r][c])
                    {
                        vis[r][c] = true;
                        joe.push({r, c});
                    }
                }
            }
            time++;
        }

        if(found)
            printf("%d\n", time);
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}