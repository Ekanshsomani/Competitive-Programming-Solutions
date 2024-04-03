#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<vb> vvb;

int rows, columns;

inline bool isInside(int r, int c)
{
    return (r>-1 and c>-1 and r<rows and c<columns);
}

int main()
{
    int rAround[]{-1, 0, 1, 0};
    int cAround[]{0, 1, 0, -1};

    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        cin >> columns >> rows;

        queue<ii> fire, q;
        bool blocked[rows][columns], vis[rows][columns];

        for(int i=0; i<rows; i++)
            for(int j=0; j<columns; j++)
            {
                char c;
                cin >> c;
                switch(c)
                {
                    case '#':
                        blocked[i][j] = true;
                    break;
                    case '@':
                        q.emplace(i, j);
                        vis[i][j] = true;
                    break;
                    case '*':
                        fire.emplace(i, j);
                        blocked[i][j] = true;
                    break;
                    default:
                        blocked[i][j] = false;
                        vis[i][j] = false;
                    break;
                }
            }
        
        bool escaped{false};
        int time{0};
        while(not (q.empty() or escaped))
        {
            int f = fire.size();
            int l = q.size();

            while(f--)
            {
                auto [r, c] = fire.front();
                fire.pop();

                for(int i=0; i<4; i++)
                {
                    int nr = r+rAround[i];
                    int nc = c+cAround[i];
                    if(isInside(nr, nc) and not blocked[nr][nc])
                    {
                        blocked[nr][nc] = true;
                        fire.emplace(nr, nc);
                    }
                }
            }

            while(l--)
            {
                auto[r, c] = q.front();
                q.pop();

                if(r==0 or c==0 or r==rows-1 or c==columns-1)
                {
                    escaped = true;
                    break;
                }

                for(int i=0; i<4; i++)
                {
                    int nr = r+rAround[i];
                    int nc = c+cAround[i];
                    if(isInside(nr, nc) and not (blocked[nr][nc] or vis[nr][nc]))
                    {
                        vis[nr][nc] = true;
                        q.emplace(nr, nc);
                    }
                }
            }

            time++;
        }

        if(escaped)
            printf("%d\n", time);
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}