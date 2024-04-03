#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;

int rows, columns;
string grid[500];

inline bool isInside(int r, int c)
{
    return (r>-1 and c>-1 and r<rows and c<columns);
}

int main()
{
    int rAround[]{-1, 0, 1, 0};
    int cAround[]{0, 1, 0, -1};

    cin >> rows >> columns;
    for(int i=0; i<rows; i++)
        cin >> grid[i];
    
    vector<vi> dist(rows, vi(columns, -1));
    queue<ii> q;
    q.emplace(0, 0);
    dist[0][0] = 0;
    while(not q.empty())
    {
        auto [r, c] = q.front();
        q.pop();

        if(r==rows-1 and c==columns-1)
            break;

        for(int i=0; i<4; i++)
        {
            int nr = r+ (grid[r][c]-'0')*rAround[i];
            int nc = c+ (grid[r][c]-'0')*cAround[i];
            if(isInside(nr, nc) and dist[nr][nc]==-1)
            {
                dist[nr][nc] = dist[r][c]+1;
                q.emplace(nr, nc);
            }
        }
    }

    printf("%d\n", dist[rows-1][columns-1]);
    return 0;
}