#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int, int> iiii;

int n;

inline bool isInside(int r, int c)
{
    return (r>0 and c>0 and r<=(n<<1) and c<=(n<<1));
}

int main()
{
    int rKnight[]{-2, -2, -1, -1, 1, 1, 2, 2};
    int cKnight[]{-1, 1, -2, 2, -2, 2, -1, 1};

    int rBishop[]{-2, -2, 2, 2};
    int cBishop[]{-2, 2, -2, 2};

    bool vis[41][41][3];
    while(cin >> n and n)
    {
        int sr, sc, tr, tc, obr, obc;
        cin >> sr >> sc >> tr >> tc;

        memset(vis, false, sizeof vis);
        while(cin >> obr >> obc and (obr and obc))
        {
            vis[obr][obc][0] = true;
            vis[obr][obc][1] = true;
            vis[obr][obc][2] = true;
        }

        queue<iiii> q;
        q.emplace(0, 0, sr, sc); vis[sr][sc][0] = true;
        q.emplace(0, 1, sr, sc); vis[sr][sc][1] = true;
        q.emplace(0, 2, sr, sc); vis[sr][sc][2] = true;

        bool reached{false};
        while(not q.empty())
        {
            auto [d, p, r, c] = q.front();
            q.pop();

            if(r==tr and c==tc)
            {
                reached = true;
                printf("Result : %d\n", d);
                break;
            }

            if(p!=0)
                for(int i=0; i<8; i++)
                {
                    int nr = r+rKnight[i];
                    int nc = c+cKnight[i];
                    if(isInside(nr, nc) and not vis[nr][nc][0])
                    {
                        vis[nr][nc][0] = true;
                        q.emplace(d+1, 0, nr, nc);
                    }
                }
            
            if(p!=1)
                for(int i=0; i<4; i++)
                {
                    int nr = r+rBishop[i];
                    int nc = c+cBishop[i];
                    if(isInside(nr, nc) and not vis[nr][nc][1])
                    {
                        vis[nr][nc][1] = true;
                        q.emplace(d+1, 1, nr, nc);
                    }
                }

            if(p!=2)
            {
                int nr = (n<<1) - r + 1;
                int nc = (n<<1) - c + 1;
                if(not vis[nr][c][2])
                {
                    vis[nr][c][2] = true;
                    q.emplace(d+1, 2, nr, c);
                }
                if(not vis[r][nc][2])
                {
                    vis[r][nc][2] = true;
                    q.emplace(d+1, 2, r, nc);
                }
            }
        }

        if(not reached)
            printf("Solution doesn't exist\n");
    }
    return 0;
}