#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int rows, columns;

inline bool isInside(int r, int c)
{
    return (r>-1 and c>-1 and r<rows and c<columns);
}

int main()
{
    int rAround[]{-1, 0, 1, 0};
    int cAround[]{0, 1, 0, -1};

    int weak;
    cin >> rows >> columns >> weak;

    bool vis[rows][columns]{false};
    queue<ii> q;
    while(weak--)
    {
        int x, y;
        cin >> x >> y;
        q.emplace(x-1, y-1);
        vis[x-1][y-1] = true;
    }

    int days{0};
    while(not q.empty())
    {
        int l = q.size();
        while(l--)
        {
            auto [r, c] = q.front();
            q.pop();

            for(int i=0; i<4; i++)
            {
                int nr = r + rAround[i];
                int nc = c + cAround[i];
                if(isInside(nr, nc) and not vis[nr][nc])
                {
                    vis[nr][nc] = true;
                    q.emplace(nr, nc);
                }
            }
        }
        days++;
    }

    printf("%d\n", days);
    return 0;
}