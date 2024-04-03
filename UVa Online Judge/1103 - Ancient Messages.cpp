#include <bits/stdc++.h>
using namespace std;

int step[4][2]{{0, 1}, {1, 0}, {0, -1},  {-1, 0}};
int n, m;
string grid[201];
int emptySpace{0};

inline void floodfill(int x, int y, char newVal, char val)
{
    if(x<0 or y<0 or x>=n or y>=m or grid[x][y]!=val)
        return;
    
    grid[x][y] = newVal;
    for(int i=0; i<4; i++)
        floodfill(x+step[i][0], y+step[i][1], newVal, val);
    return;
}

inline void symbolFill(int x, int y)
{
    if(x<0 or y<0 or x>=n or y>=m or grid[x][y]=='*')
        return;
    
    if(grid[x][y]=='0')
    {
        emptySpace++;
        floodfill(x, y, '*', '0');
        return;
    }

    grid[x][y] = '*';
    for(int i=0; i<4; i++)
        symbolFill(x+step[i][0], y+step[i][1]);
    return;
}

int main()
{
    int test{1};

    int w;
    char spaces[]{'W', 'A', 'K', 'J', 'S', 'D'};
    multiset<char> symbols;
    while(cin >> n >> w and (n or w))
    {
        m = w<<2;

        for(int i=0; i<n; i++)
        {
            grid[i] = "";
            for(int j=0; j<w; j++)
            {
                char a;
                cin >> a;
                int b = a - (a>96 ? 87 : 48);
                bitset<4> bits(b);
                grid[i] += bits.to_string();
            }
        }

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(i==0 or j==0 or i==n-1 or j==m-1)
                    floodfill(i, j, '*', '0');

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j]=='1')
                {
                    emptySpace = 0;
                    symbolFill(i, j);
                    symbols.insert(spaces[emptySpace]);
                }
        
        printf("Case %d: ", test++);
        for(auto it: symbols)
            printf("%c", it);
        printf("\n");

        symbols.clear();
    }
    return 0;
}