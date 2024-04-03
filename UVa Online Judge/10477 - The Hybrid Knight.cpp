#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int, int> iiii;

int n;

inline bool isInside(int r, int c)
{
    return (r>-1 and c>-1 and r<n and c<n);
}

int main()
{
    int rKnight[]{-2, -2, -1, -1, 1, 1, 2, 2};
    int cKnight[]{-1, 1, -2, 2, -2, 2, -1, 1};

    int rMutant[]{-3, -3, -1, -1, 1, 1, 3, 3};
    int cMutant[]{-1, 1, -3, 3, -3, 3, -1, 1};

    int rPawn[]{-1, 0, 1, 0};
    int cPawn[]{0, 1, 0, -1};

    int rDia[]{-1, -1, 1, 1};
    int cDia[]{-1, 1, -1, 1};

    bool vis[20][20][3];
    int test{1};
    
    while(cin >> n and n)
    {
        printf("Set %d:\n", test++);

        int queries;
        cin >> queries;
        while(queries--)
        {
            int idx, sr, sc, tr, tc;
            cin >> idx;
            idx--;
            sr = idx/n;
            sc = idx%n;
            
            cin >> idx;
            idx--;
            tr = idx/n;
            tc = idx%n;

            memset(vis, false, sizeof vis);
            queue<iiii> q;
            q.emplace(0, 0, sr, sc); vis[sr][sc][0] = true; // 0 means last move was knight
            q.emplace(0, 1, sr, sc); vis[sr][sc][1] = true; // 1 means last move was mutant
            q.emplace(0, 2, sr, sc); vis[sr][sc][2] = true; // 2 means last move was pawn

            bool reached{false};
            while(not q.empty())
            {
                auto [d, p, r, c] = q.front();
                q.pop();

                if(r==tr and c==tc)
                {
                    reached = true;
                    printf("%d\n", d);
                    break;
                }

                if(p==2)
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
                
                if(p==0)
                    for(int i=0; i<8; i++)
                    {
                        int nr = r+rMutant[i];
                        int nc = c+cMutant[i];
                        if(isInside(nr, nc) and not vis[nr][nc][1])
                        {
                            vis[nr][nc][1] = true;
                            q.emplace(d+1, 1, nr, nc);
                        }
                    }

                if(p==1)
                {
                    for(int i=0; i<4; i++)
                    {
                        int nr = r+rDia[i];
                        int nc = c+cDia[i];
                        if(nr==tr and nc==tc)
                        {
                            vis[nr][nc][2] = true;
                            q.emplace(d+1, 2, nr, nc);
                            break;
                        }
                    }
                    if(vis[tr][tc][2])
                        continue;
                    
                    for(int i=0; i<4; i++)
                    {
                        int nr = r+rPawn[i];
                        int nc = c+cPawn[i];
                        if(isInside(nr, nc) and not vis[nr][nc][2])
                        {
                            vis[nr][nc][2] = true;
                            q.emplace(d+1, 2, nr, nc);
                        }
                    }
                }
            }

            if(not reached)
                printf("?\n");
        }
    }
    return 0;
}