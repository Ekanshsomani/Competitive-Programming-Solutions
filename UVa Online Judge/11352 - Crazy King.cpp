#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int,  int> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int rows, columns;
bool vis[100][100];

inline bool isInside(int r, int c)
{
    return (r>-1 and c>-1 and r<rows and c<columns);
}

int main()
{
    int rHorse[]{-2, -2, -1, -1, 1, 1, 2, 2};
    int cHorse[]{-1, 1, -2, 2, -2, 2, -1, 1};

    int rAround[]{-1, -1, 0, 1, 1, 1, 0, -1};
    int cAround[]{0, 1, 1, 1, 0, -1, -1, -1};

    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        cin >> rows >> columns;
        int sr, sc, tr, tc;

        memset(vis, false, sizeof vis);
        for(int i=0; i<rows; i++)
            for(int j=0; j<columns; j++)
            {
                char c;
                cin >> c;
                switch(c)
                {
                    case 'A':
                        sr = i; 
                        sc = j;
                    break;
                    case 'B':
                        tr = i;
                        tc = j;
                    break;
                    case 'Z':
                        vis[i][j] = true;
                        for(int k=0; k<8; k++)
                        {
                            int r = i+rHorse[k];
                            int c = j+cHorse[k];
                            if(isInside(r, c))
                                vis[r][c] = true;
                        }
                    break;
                    default:
                        ;
                    break;
                }
            }

        vis[tr][tc] = false;
        queue<iii> q;
        q.emplace(0, sr, sc);
        vis[sr][sc] = true;
        while(not q.empty())
        {
            auto [d, r, c] = q.front();
            q.pop();

            if(r==tr and c==tc)
            {
                printf("Minimal possible length of a trip is %d\n", d);
                break;
            }

            for(int i=0; i<8; i++)
            {
                int nr = r+ rAround[i];
                int nc = c+ cAround[i];
                if(isInside(nr, nc) and not vis[nr][nc])
                {
                    vis[nr][nc] = true;
                    q.emplace(d+1, nr, nc);
                }
            }
        }

        if(not vis[tr][tc])
            printf("King Peter, you can't go now!\n");
    }
    return 0;
}