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
    int step[4][2]{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        cin >> rows >> columns;

        int maze[rows][columns];
        for(int i=0; i<rows; i++)
            for(int j=0; j<columns; j++)
                cin >> maze[i][j];
        
        priority_queue<pair<int, ii>> pq;
        pq.push({-maze[0][0], {0, 0}});
        
        vector<vector<bool>> vis(rows, vector<bool>(columns, false));

        while(not pq.empty())
        {
            int x, y;
            tie(x, y) = pq.top().second;
            int cost {-pq.top().first};
            pq.pop();

            if(x==rows-1 and y==columns-1)
            {
                printf("%d\n", cost);
                break;
            }

            if(vis[x][y]) continue;
            vis[x][y] = true;

            for(int i=0; i<4; i++)
            {
                int r{x + step[i][0]}, c{y+step[i][1]};
                if(isInside(r, c))
                    pq.push({-(cost+maze[r][c]), {r, c}});
            }
        }
    }
    return 0;
}