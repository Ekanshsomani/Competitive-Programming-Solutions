#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

int rows, columns;

const int INF = 2000000;

inline bool isInside(int r, int c)
{
    return (r>-1 and c>-1 and r<rows and c<columns);
}

// Negative altitude -> implies water
// water moves iff -> neighboring square has lower value
// that means that dist(at node) = max(grid[nr][nc], grid[r][c]+1, dist[r][c])

int main()
{
    int rAround[]{-1, -1, 0, 1, 1, 1, 0, -1};
    int cAround[]{0, 1, 1, 1, 0, -1, -1, -1};

    cin >> rows >> columns;
    
    int grid[rows][columns];

    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            cin >> grid[i][j];
    
    int sr, sc;
    cin >> sr >> sc;

    vvi dist(rows, vi(columns, INF));
    dist[sr-1][sc-1] = grid[sr-1][sc-1];
    

    set<iii> pq; // balanced BST version
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            pq.emplace(dist[i][j], i, j);

    // sort the pairs by non-decreasing distance from s
    while (!pq.empty())  // main loop
    {
        auto [d, r, c] = *pq.begin(); // shortest unvisited u
        pq.erase(pq.begin());

        for(int i=0; i<8; i++)
        { 
            int nr = r+rAround[i];
            int nc = c+cAround[i];
            if(isInside(nr, nc) and d < dist[nr][nc] and grid[nr][nc] < dist[nr][nc])
            {
                pq.erase(pq.find({dist[nr][nc], nr, nc})); // erase old pair
                dist[nr][nc] = max(d, grid[nr][nc]); // relax operation
                pq.emplace(dist[nr][nc], nr, nc); // enqueue better pair
            }
        }
    }

    long long drained{0};
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            if(dist[i][j]<0)
                drained -= dist[i][j];
    printf("%lld\n", drained);
    return 0;
}