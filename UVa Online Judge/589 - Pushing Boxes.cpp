#include <bits/stdc++.h>

using namespace std;

typedef pair<int, string> is;
typedef tuple<int, string, int, int> isii;
typedef tuple<int, int, string, int, int, int, int> pqTuple;

int rows, columns;
string grid[20];
bool vis[20][20];
int distp[20][20][20][20], dists[20][20][20][20];

int rAround[]{-1, 0, 1, 0};
int cAround[]{0, 1, 0, -1};
char direction[]{'n', 'e', 's', 'w'};

const int INF = 0x3f3f3f3f;

inline bool isInside(int r, int c)
{
    return (r>-1 and c>-1 and r<rows and c<columns);
}

inline is bfs(int sr, int sc, int tr, int tc, int br, int bc)
{
    if(not (isInside(tr, tc) and grid[tr][tc]!='#')) return {-1, ""};

    memset(vis, false, sizeof vis);
    queue<isii> q;

    q.emplace(0, "", sr, sc);
    vis[sr][sc] = true;
    vis[br][bc] = true;

    while(not q.empty())
    {
        auto [m, s, r, c] = q.front();
        q.pop();

        if(r==tr and c==tc)
            return {m, s};

        for(int i=0; i<4; i++)
        {
            int nr = r+rAround[i];
            int nc = c+cAround[i];
            if(isInside(nr, nc) and (not vis[nr][nc]) and grid[nr][nc]!='#')
            {
                vis[nr][nc] = true;
                q.emplace(m+1, s+direction[i], nr, nc);
            }
        }
    }
    return {-1, ""};
}

int main()
{
    int test{1};
    char pushDirect[]{'N', 'E', 'S', 'W'};
    while(cin >> rows >> columns and (rows or columns))
    {
        int sr, sc, bsr, bsc, tr, tc;
        for(int i=0; i<rows; i++)
        {
            cin >> grid[i];
            for(int j=0; j<columns; j++)
                if(grid[i][j]=='B')
                    {bsr = i; bsc = j;}
                else if(grid[i][j]=='S')
                    {sr = i; sc = j;}
                else if(grid[i][j]=='T')
                    {tr = i; tc = j;}
        }

        memset(distp, INF, sizeof distp); distp[bsr][bsc][sr][sc] = 0;
        memset(dists, INF, sizeof dists); dists[bsr][bsc][sr][sc] = 0;
        priority_queue<pqTuple, vector<pqTuple>,  greater<pqTuple>> pq;
        pq.emplace(0, 0, "", bsr, bsc, sr, sc);

        printf("Maze #%d\n", test++);
        bool solvable{false};
        while (!pq.empty())
        {
            auto [pushes, steps, s, br, bc, cr, cc] = pq.top();
            pq.pop();

            if(pushes > distp[br][bc][cr][cc]) continue;

            if(br==tr and bc==tc)
            {
                solvable = true;
                cout << s << endl;
                break;
            }

            for(int i=0; i<4; i++)
            { 
                int nbr = br+rAround[i];
                int nbc = bc+cAround[i];

                int ncr = br-rAround[i];
                int ncc = bc-cAround[i];

                auto [nd, ns] = bfs(cr, cc, ncr, ncc, br, bc);
                if(nd!=-1 and distp[br][bc][ncr][ncc]> pushes or 
                (distp[br][bc][ncr][ncc]==pushes and dists[br][bc][ncr][ncc]>(pushes+steps+nd)))
                {
                    distp[br][bc][ncr][ncc] = pushes;
                    dists[br][bc][ncr][ncc] = pushes+steps+nd;
                }

                if(isInside(nbr, nbc) and nd!=-1 and grid[nbr][nbc]!='#')
                {
                    if(distp[nbr][nbc][br][bc] > (pushes+1) or 
                    (distp[nbr][nbc][br][bc] == (pushes+1) and dists[nbr][nbc][br][bc]> (pushes+steps+nd+1)))
                    {
                        distp[nbr][nbc][br][bc] = pushes+1;
                        dists[nbr][nbc][br][bc] = steps+nd;
                        pq.emplace(pushes+1, pushes+steps+nd+1, s+ns+pushDirect[i], nbr, nbc, br, bc);
                    }
                }
            }
        }

        if(not solvable)
            printf("Impossible.\n");
        printf("\n");
    }
    return 0;
}