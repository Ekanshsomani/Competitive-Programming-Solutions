#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;

inline bool isInside(int r, int c)
{
    return (r>-1 and c>-1 and r<8 and c<8);
}

int main()
{
    int rKnight[]{-2, -2, -1, -1, 1, 1, 2, 2};
    int cKnight[]{-1, 1, -2, 2, -2, 2, -1, 1};
    bool vis[8][8];

    string a, b;
    while(cin >> a >> b)
    {
        int sr = a[1] - '1';
        int sc = a[0] - 'a';
        int tr = b[1] - '1';
        int tc = b[0] - 'a';

        memset(vis, false, sizeof vis);
        queue<iii> q;
        
        q.emplace(0, sr, sc);
        vis[sr][sc] = true;
        while(not q.empty())
        {
            auto [m, r, c] = q.front();
            q.pop();

            if(r==tr and c==tc)
            {
                cout << "To get from " << a << " to " << b 
                << " takes " << m << " knight moves.\n";
                break;
            }

            for(int i=0; i<8; i++)
            {
                int nr = r+rKnight[i];
                int nc = c+cKnight[i];
                if(isInside(nr, nc) and not vis[nr][nc])
                {
                    vis[nr][nc] = true;
                    q.emplace(m+1, nr, nc);
                }
            }
        }
    }
    return 0;
}