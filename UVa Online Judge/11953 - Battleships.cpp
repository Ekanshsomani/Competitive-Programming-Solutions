#include <bits/stdc++.h>
using namespace std;

string grid[100];
int n;
int step[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

inline void floodfill(int x, int y) // orientation - 0 or 2;
{
    if(x<0 or y<0 or x>=n or y>=n or grid[x][y]=='.')
        return;

    grid[x][y] = '.';
    for(int i=0; i<4; i++)
        floodfill(x+step[i][0], y+step[i][1]);
    return;
}

int main()
{
    int testcases;
    cin >> testcases;
    for(int t=1; t<=testcases; t++)
    {
        cin >> n;
        for(int i=0; i<n; i++)  
            cin >> grid[i];
        
        int alive{0};
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(tolower(grid[i][j])=='x')
                {
                    floodfill(i, j);
                    alive++;
                }
        printf("Case %d: %d\n", t, alive);
    }
    return 0;
}