#include <bits/stdc++.h>

#define ii pair<int, int>

using namespace std;

int rows, columns;
// vector<bool> *vis;

inline bool isInside(int r, int c)
{
    return (r>0 and c>0 and r<=rows and c<=columns);
}

inline double distance(ii a, ii b)
{
    return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

int main()
{
    int step[4][2]{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int r, c, loudness;
    while(cin >> rows >> columns and (rows or columns))
    {
        bool vis[rows+1][columns+1] = {false};

        int blocked;
        cin >> blocked;
        while(blocked--)
        {
            cin >> r >> c;
            vis[r][c] = true;
        }

        int jigglyPuffs;
        cin >> jigglyPuffs;
        while(jigglyPuffs--)
        {
            cin >> r >> c >> loudness;
            for(int i=r-loudness; i<=r+loudness; i++)
                for(int j=c-loudness; j<=c+loudness; j++)
                    if(isInside(i, j) and distance({r, c}, {i, j})<=1.00*loudness)
                        vis[i][j] = true;
        }

        bool escaped{false};
        ii end = {rows, columns};
        queue<pair<int, ii>> q;
        q.push({0, {1, 1}});
        vis[1][1] = true;
        
        while(not q.empty())
        {
            ii pos = q.front().second;
            int time = q.front().first;
            q.pop();

            if(pos== end)
            {
                escaped = true;
                printf("%d\n", time);
            }

            for(int i=0; i<4; i++)
            {
                int r = pos.first + step[i][0];
                int c = pos.second + step[i][1];
                if(isInside(r, c) and not vis[r][c])
                {
                    vis[r][c] = true;
                    q.push({time+1, {r, c}});
                }
            }
        }

        if(not escaped)
            printf("Impossible.\n");
    }
    return 0;
}