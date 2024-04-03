#include <bits/stdc++.h>

using namespace std;

// isInside
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int INF = 2000;

int rows, columns;
string grid[20];

inline bool isInside(int r, int c)
{
    return (r>-1 and c>-1 and r<rows and c<columns);
}

int main()
{
    int rAround[]{-1, -1, 0, 1, 1, 1, 0, -1};
    int cAround[]{0, 1, 1, 1, 0, -1, -1, -1};
    while(cin >> rows >> columns and (rows or columns))
    {
        for(int i=0; i<rows; i++)
            cin >> grid[i];
        
        vvi dist(rows, vi(columns, INF));
        vvii parent(rows, vii(columns, {-1, -1}));
        set<iii> pq; // balanced BST version
        
        for(int i=0; i<columns; i++)
            dist[0][i] = grid[0][i]-'0';
        
        for(int i=0; i<rows; i++)
            for(int j=0; j<columns; j++)
                pq.emplace(dist[i][j], i, j);

        // sort the pairs by non-decreasing distance from s
        while (!pq.empty())  // main loop
        {
            auto [d, r, c] = *pq.begin(); // shortest unvisited u
            pq.erase(pq.begin());

            if(r==rows-1)
            {
                while(r!=-1)
                {
                    grid[r][c] = ' ';
                    tie(r, c) = parent[r][c];
                }
                break;
            }

            for(int i=0; i<8; i++)
            { 
                int nr = r+rAround[i];
                int nc = c+cAround[i];
                if(isInside(nr, nc) and d+(grid[nr][nc]-'0') < dist[nr][nc])
                {
                    pq.erase(pq.find({dist[nr][nc], nr, nc})); // erase old pair
                    parent[nr][nc] = {r, c};
                    dist[nr][nc] = d + (grid[nr][nc]-'0'); // relax operation
                    pq.emplace(dist[nr][nc], nr, nc); // enqueue better pair
                }
            }
        }

        for(int i=0; i<rows; i++)
            cout << grid[i] << "\n";
        printf("\n");
    }
    return 0;
}