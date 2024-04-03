#include <bits/stdc++.h>

using namespace std;

typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

int rows, columns;
string grid[400];

inline bool isInside(int r, int c)
{
    return (r>-1 and c>-1 and r<rows and c<columns);
}

int main()
{
    int rAround[]{-1, 0, 1, 0,};
    int cAround[]{0, 1, 0, -1,};

    cin >> rows >> columns;
    for(int i=0; i<rows; i++)
        cin >> grid[i];

    int sr, sc;
    cin >> sr >> sc;

    vector<vb> vis(rows, vb(columns, false));
    deque<iii> dq;
    dq.emplace_front(1, sr-1, sc-1);
    vis[sr-1][sc-1] = true;

    while (!dq.empty())  // main loop
    {
        auto [d, r, c] = dq.front(); // shortest unvisited u
        dq.pop_front();

        if(r==(rows-1) or c==(columns-1) or r==0 or c==0)
        {
            printf("%d\n", d);
            break;
        }

        for(int i=0; i<4; i++) 
        { 
            int nr = r + rAround[i];
            int nc = c + cAround[i];

            if(isInside(nr, nc) and not vis[nr][nc] and grid[nr][nc]!='#')
            {
                vis[nr][nc] = true;
                if(grid[nr][nc]=='D')
                    dq.emplace_front(d, nr, nc);
                else
                    dq.emplace_back(d+1, nr, nc);
            }
        }
    }
    return 0;
}