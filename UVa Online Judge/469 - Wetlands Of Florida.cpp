#include <bits/stdc++.h>
using namespace std;

int rows, columns;
string grid[99];
int nbr[]{-1, -1, -1,  0,  0, +1, +1, +1};
int nbc[]{-1,  0, +1, -1, +1, -1,  0, +1};

int dfs(int r, int c, char a, char b)
{
    if(r<0 | r>=rows | c<0 | c>=columns) return 0;
    if(grid[r][c]!=a) return 0;
    
    grid[r][c] = b;
    int ans = 1;
    for(int i=0; i<8; i++)
        ans += dfs(r + nbr[i], c + nbc[i], a, b);
    return ans;
}

int main()
{
    string line;

    int testcases;
    cin >> testcases;
    cin.ignore();
    cin.ignore();
    while(testcases--)
    {
        rows = 0;
        while(getline(cin, line) and line.size()>0)
        {
            if(line[0]>64)
            {
                grid[rows] = line;
                rows++;
            }
            else
            {
                columns = grid[0].size();
                istringstream iss(line);
                int i, j;
                iss >> i >> j;
                i--, j--;
                // printf("%d %d %c\n", i, j, grid[i][j]);
                printf("%d\n", dfs(i, j, 'W', '.'));
                dfs(i, j, '.', 'W');
            }
        }
        if(testcases) printf("\n");
    }
    return 0;
}