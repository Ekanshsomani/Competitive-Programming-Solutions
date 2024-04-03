#include <bits/stdc++.h>

#define ii pair<int, int>

using namespace std;

bool isInside(int r, int c)
{
    return (r>-1 and c>-1 and r<2001 and c<2001);
}

bool vis[2001][2001], mall2[2001][2001];

int main()
{
    int step[4][2]{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    ii pos;
    int p1, p2;
    while(cin >> p1 and p1)
    {
        queue<pair<int, ii>> q;
        memset(vis, 0, sizeof vis);
        memset(mall2, 0, sizeof mall2);

        while(p1--)
        {
            cin >> pos.first >> pos.second;
            vis[pos.first][pos.second] = true;
            q.push({0, pos});
        }

        cin >> p2;
        while(p2--)
        {
            cin >> pos.first >> pos.second;
            mall2[pos.first][pos.second] = 1;
        }

        while(not q.empty())
        {
            pos = q.front().second;
            int dist = q.front().first;
            q.pop();

            if(mall2[pos.first][pos.second])
            {
                printf("%d\n", dist);
                break;
            }

            for(int i=0; i<4; i++)
            {
                int r = pos.first + step[i][0];
                int c = pos.second + step[i][1];
                if(isInside(r, c) and not vis[r][c])
                {
                    vis[r][c] = true;
                    q.push({dist+1, {r, c}});
                }
            }
        }

    }
    return 0;
}