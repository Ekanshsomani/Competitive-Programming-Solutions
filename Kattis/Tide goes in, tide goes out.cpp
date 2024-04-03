#include <bits/stdc++.h>

using namespace std;

typedef tuple<double, int, int> dii;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;

const double INF = 1e5;

int rows, columns;
vvi clng, flr;

inline bool isValid(int r, int c, int prevR, int prevC, int level)
{
    if(not (r>-1 and c>-1 and r<rows and c<columns))
        return false;
    
    if(max(max(level, flr[prevR][prevC]), flr[r][c])+50 > clng[r][c])
        return false;
    
    if(flr[r][c]+50 > clng[prevR][prevC])
        return false;

    return true;
}

// adjacent contraints:
    // max(level, floorHeightCurrent, floorHeightNext) <= ceilHeightNext-50
    // floorHeightNext <= ceilHeightCurrent-50

int main()
{
    int rAround[]{-1, 0, 1, 0};
    int cAround[]{0, 1, 0, -1};

    int testcases;
    cin >> testcases;
    for(int t=1; t<=testcases; t++)
    {
        int init;
        cin >> init >> rows >> columns;

        clng.assign(rows, vi(columns));
        flr.assign(rows, vi(columns));

        for(int i=0; i<rows; i++)
            for(int j=0; j<columns; j++)
                cin >> clng[i][j];
        
        for(int i=0; i<rows; i++)
            for(int j=0; j<columns; j++)
                cin >> flr[i][j];

        vvd time(rows, vd(columns, INF));
        time[0][0] = 0;
        
        queue<ii> q;
        q.emplace(0, 0);
        while(not q.empty())
        {
            auto [r, c] = q.front();
            q.pop();

            for(int i=0; i<4; i++)
            {
                int nr = r+rAround[i];
                int nc = c+cAround[i];
                if(isValid(nr, nc, r, c, init) and time[nr][nc]==INF)
                {
                    time[nr][nc] = 0;
                    q.emplace(nr, nc);
                }
            }
        }

        set<dii> pq; // balanced BST version
        for(int i=0; i<rows; i++)
            for(int j=0; j<columns; j++)
                pq.emplace(time[i][j], i, j);

        // sort the pairs by non-decreasing distance from s
        while (not pq.empty())  // main loop
        {
            auto [ct, r, c] = *pq.begin(); // shortest unvisited u
            pq.erase(pq.begin());

            if(r==rows-1 and c==columns-1)
                break;

            for(int i=0; i<4; i++)
            { 
                int nr = r+rAround[i];
                int nc = c+cAround[i];
                
                if(not (nr>-1 and nc>-1 and nr<rows and nc<columns))
                    continue;
    
                if(max(flr[nr][nc], flr[r][c])+50 > clng[nr][nc])
                    continue;

                if(flr[nr][nc]+50 > clng[r][c])
                    continue;

                double nTime = 0;
                if((init- (ct*10) + 50) > clng[nr][nc])
                    nTime += (init + 50 - clng[nr][nc])/10.0 - ct;

                nTime += ct + (((init-(ct+nTime)*10) < (flr[r][c]+20)) ? 10 : 1);
                if(nTime >= time[nr][nc]) continue;

                pq.erase(pq.find({time[nr][nc], nr, nc})); // erase old pair
                time[nr][nc] = nTime;
                pq.emplace(time[nr][nc], nr, nc); // enqueue better pair
            }
        }

        printf("Case #%d: %f\n", t, time[rows-1][columns-1]);
    }
    return 0;
}