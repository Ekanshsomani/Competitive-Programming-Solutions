#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

inline bool isInside(int x, int y)
{
    return (x>-1 and y>-1 and x<201 and y<201);
}

int main()
{
    bool vis[201][201];
    int passVal[201][201][2];
    int x_around[]{0, -1, 0, 1};
    int y_around[]{-1, 0, 1, 0};

    int walls, doors;
    while(cin >> walls >> doors and (walls>-1 or doors>-1))
    {
        memset(vis, false, sizeof vis);
        memset(passVal, 0, sizeof passVal);
        while(walls--)
        {
            int x, y, d, t;
            cin >> x >> y >> d >> t;
            if(d)
                for(int i=0; i<t; i++)
                    passVal[x][y+i][d] = 2;
            else
                for(int i=0; i<t; i++)
                    passVal[x+i][y][d] = 2;
        }

        while(doors--)
        {
            int x, y, d;
            cin >> x >> y >> d;
            passVal[x][y][d] = 1;
        }

        double d1, d2;
        cin >> d1 >> d2;
        ii target;
        target.first = (int)floor(d1);
        target.second = (int)floor(d2);

        if(target.first>199 or target.second>199)
        {
            printf("0\n");
            continue;
        }

        priority_queue<iii, vector<iii>, greater<iii>> pq;
        pq.push({0, {0, 0}});

        while(not pq.empty())
        {
            ii node = pq.top().second;
            int length = pq.top().first;
            pq.pop();

            int x, y;
            tie(x, y) = node;
            if(vis[x][y]) continue;
            vis[x][y] = true;

            if(node==target)
            {
                printf("%d\n", length);
                break;
            }

            for(int i=0; i<4; i++)
            {
                int nx = x + x_around[i];
                int ny = y + y_around[i];
                ii snode = {nx, ny};
                int pass = (i<2 ? passVal[x][y][i] : passVal[nx][ny][i%2]);
                if(isInside(nx, ny) and not vis[nx][ny] and pass!=2)
                    pq.push({length+pass, {nx, ny}});
            }
        }

        if(not vis[target.first][target.second])
            printf("-1\n");
    }
    return 0;
}