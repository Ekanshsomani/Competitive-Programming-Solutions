#include <bits/stdc++.h>
using namespace std;

#define WATER -1

int grid[101][101], neighbors[101][101];
bitset<101> vis[101];
int rows, columns;
int m, n;
int direction[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

inline bool isInside(int r, int c)
{
    return (r<rows and c<columns and r>-1 and c>-1);
}

inline void dfs(int r, int c)
{
    if(vis[r][c])
        return;

    vis[r][c] = true;
    for(int i=0; i<4; i++)
    {
        int r1 = r+direction[i][0]*m;
        int c1 = c+direction[i][1]*n;

        if(isInside(r1, c1) and grid[r1][c1] != WATER)
        {
            neighbors[r1][c1]++;
            dfs(r1, c1);
        }

        r1 = r+direction[i][0]*n;
        c1 = c+direction[i][1]*m;

        if(isInside(r1, c1) and grid[r1][c1] != WATER)
        {
            neighbors[r1][c1]++;
            dfs(r1, c1);
        }
    }

    return;
}

int main()
{
    int testcases;
    cin >> testcases;
    for(int t=1; t<=testcases; t++)
    {
        int wetSpots;
        cin >> rows >> columns >> m >> n >> wetSpots;

        memset(neighbors, 0, sizeof neighbors);
        memset(grid, 0, sizeof grid);
        for(int i=0; i<rows; i++)
            vis[i].reset();

        while(wetSpots--)
        {
            int i, j;
            cin >> i >> j;
            grid[i][j] = WATER;
        }

        dfs(0, 0);

        int odd{0}, even{0};
        for(int r=0; r<rows; r++)
            for(int c=0; c<columns; c++)
            {
                if(m==0 or n==0 or m==n)
                    neighbors[r][c] >>= 1;

                if(neighbors[r][c] or not(r or c))
                    if(neighbors[r][c]&1) 
                        odd++;
                    else
                        even++;
            }

        printf("Case %d: %d %d\n", t, even, odd);
    }
    return 0;
}