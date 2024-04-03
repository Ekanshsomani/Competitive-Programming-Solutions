#include <bits/stdc++.h>

using namespace std;

typedef vector<bool> vb;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;

string grid[1000];
int rows, columns;

inline bool isInside(int r, int c)
{
    return (r>-1 and c>-1 and r<rows and c<columns);
}

int main()
{
    int rAround[]{-1, -1, 0, 1, 1, 1, 0, -1};
    int cAround[]{0, 1, 1, 1, 0, -1, -1, -1};

    while(cin >> rows >> columns)
    {
        for(int i=0; i<rows; i++)
            cin >> grid[i];

        int queries;
        cin >> queries;
        while(queries--)
        {
            int sr, sc, tr, tc;
            cin >> sr >> sc >> tr >> tc;

            vector<vb> vis(rows+1, vb(columns+1, false));
            deque<iii> dq;
            dq.emplace_front(0, sr-1, sc-1);

            while (!dq.empty())  // main loop
            {
                auto [d, r, c] = dq.front(); // shortest unvisited u
                dq.pop_front();
                vis[r][c] = true;

                if(r==(tr-1) and c==(tc-1))
                {
                    printf("%d\n", d);
                    break;
                }

                for(int i=0; i<8; i++) 
                { 
                    int nr = r + rAround[i];
                    int nc = c + cAround[i];

                    if(isInside(nr, nc) and not vis[nr][nc])
                    {
                        if((grid[r][c]-'0')==i)
                            dq.emplace_front(d, nr, nc);
                        else
                            dq.emplace_back(d+1, nr, nc);
                    }
                }
            }
        }
    }
    return 0;
}