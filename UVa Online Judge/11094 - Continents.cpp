#include <bits/stdc++.h>
using namespace std;

int m, n;
string grid[20];
int step[4][2]{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
char land, water{'w'};

inline int floodFill(int x, int y)
{
    if(y==-1) y = n-1;
    else if(y==n) y = 0;

    if(x<0 or x>=m or grid[x][y]!=land)
        return 0;

    grid[x][y] = water;
    int ans = 1;
    for(int i=0; i<4; i++)
        ans += floodFill(x+step[i][0], y+step[i][1]);
    return ans;
}

int main()
{
    while(cin >> m >> n)
    {
        for(int i=0; i<m; i++)
            cin >> grid[i];

        int x, y;
        cin >> x >> y;
        land = grid[x][y];
        water = (land>32 ? land-1 : land+1);
        floodFill(x, y);


        int maxLand{0};
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                maxLand = max(maxLand, floodFill(i, j));

        printf("%d\n", maxLand);
    }
    return 0;
}