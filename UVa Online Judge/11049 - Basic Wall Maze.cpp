#include <bits/stdc++.h>

#define ii pair<int, int>

using namespace std;

inline bool isInside(int r, int c)
{
    return (r>0 and c>0 and r<7 and c<7);
}

int main()
{
    int step[4][2]{{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    char drtn[4]{'N', 'E', 'S', 'W'};

    ii start; // first->columnNum, second -> RowNum; -> 1 indexing
    while(cin >> start.first >> start.second and (start.first or start.second))
    {
        // printf("Entering while for %d and %d\n", start.first, start.second);
        ii end;
        cin >> end.first >> end.second;
        
        set<pair<ii, ii>> wall;
        for(int i=0; i<3; i++)
        {
            ii wStart, wEnd; // first -> dist from left side, second -> dist from up
            cin >> wStart.first >> wStart.second;
            cin >> wEnd.first >> wEnd.second;

            if(wStart.first == wEnd.first)
                for(int i=wStart.second+1; i<=wEnd.second; i++)
                {
                    wall.insert({{wStart.first, i}, {wStart.first+1, i}});
                    wall.insert({{wStart.first+1, i}, {wStart.first, i}});
                }
            else
                for(int i=wStart.first+1; i<=wEnd.first; i++)
                {
                    wall.insert({{i, wStart.second},{i, wStart.second+1}});
                    wall.insert({{i, wStart.second+1},{i, wStart.second}});
                }
        }

        bool vis[7][7] = {false};
        queue<pair<string, ii>> q;
        q.push({"", start});
        vis[start.first][start.second] = true;

        while(not q.empty())
        {
            ii pos = q.front().second;
            string path = q.front().first;
            q.pop();
            if(pos==end)
            {
                cout << path << "\n";
                break;
            }

            for(int i=0; i<4; i++)
            {
                int c = pos.first + step[i][0];
                int r = pos.second + step[i][1];
                string p = path + drtn[i];
                if(isInside(c, r) and not (vis[c][r] or wall.count({pos, {c, r}})))
                {
                    vis[c][r] = true;
                    q.push({p, {c, r}});
                }
            }
        }
    }
}