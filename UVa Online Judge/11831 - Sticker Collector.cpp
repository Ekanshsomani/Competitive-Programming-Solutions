#include <bits/stdc++.h>
using namespace std;

int main()
{
    char orientation[]{'N', 'L', 'S', 'O'};
    unordered_map<char, int> index{{'N', 0}, {'L', 1}, {'S', 2}, {'O', 3}};
    int steps[4][2]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int rows, columns;
    string grid[100];
    int instructions;
    while(cin >> rows >> columns >> instructions and
    (rows or columns or instructions))
    {
        for(int i=0; i<rows; i++)
            cin >> grid[i];
        
        int r, c, dir;
        for(r=0; r<rows; r++)
        {
            for(c=0; c<columns; c++)
                if(grid[r][c]>64) 
                {
                    dir = index[grid[r][c]];
                    grid[r][c] = index[grid[r][c]] + 48;
                    break;
                }
            if(c<columns)
                break;
        }

        int stickers{0};
        string line;
        cin >> line;
        for(auto it: line)
            switch(it)
            {
                case 'D':
                    dir = (dir+1)%4;
                break;
                case 'E':
                    dir = (dir==0 ? 3 : dir-1);
                break;
                default:
                    r += steps[dir][0];
                    c += steps[dir][1];

                    if(c>-1 and r>-1 and r<rows and c<columns and grid[r][c]!='#')
                    {
                        if(grid[r][c]=='*')
                        {
                            grid[r][c] = '.';
                            stickers++;
                        }
                        continue;
                    }
                    r -= steps[dir][0];
                    c -= steps[dir][1];
                break;
            }
        printf("%d\n", stickers);
    }
    return 0;
}