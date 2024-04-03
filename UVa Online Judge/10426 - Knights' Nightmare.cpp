#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int rows, columns;
const int INF = 0x3f3f3f3f;
int wake[17][17][4], sleep[17][17][4];


inline bool isInside(int r, int c)
{
    return (r>0 and c>0 and r<=rows and c<=columns);
}

int main()
{
    int rKnight[]{-2, -2, -1, -1, 1, 1, 2, 2};
    int cKnight[]{-1, 1, -2, 2, -2, 2, -1, 1};
    string setNum;
    while(cin >> setNum)
    {
        cin >> rows >> columns;

        int sr[4], sc[4], mr, mc;
        for(int i=0; i<4; i++)
            cin >> sr[i] >> sc[i];
        cin >> mr >> mc;

        memset(wake, INF, sizeof wake);
        memset(sleep, INF, sizeof sleep);

        for(int idx=0; idx<4; idx++)
        {
            queue<ii> q;
            q.emplace(sr[idx], sc[idx]);
            wake[sr[idx]][sc[idx]][idx] = 0;

            while(not q.empty())
            {
                int r, c;
                tie(r, c) = q.front();
                q.pop();

                for(int k=0; k<8; k++)
                {
                    int nr = r+rKnight[k];
                    int nc = c+cKnight[k];

                    if(isInside(nr, nc) and wake[nr][nc][idx]==INF)
                    {
                        wake[nr][nc][idx] = wake[r][c][idx]+1;
                        q.emplace(nr, nc);
                    }
                }
            }
            // printf("\n");

            sleep[sr[idx]][sc[idx]][idx] = 0;
            q.emplace(sr[idx], sc[idx]);
            while(not q.empty())
            {
                auto [r, c] = q.front();
                q.pop();

                for(int k=0; k<8; k++)
                {
                    int nr = r+rKnight[k];
                    int nc = c+cKnight[k];

                    if(nr == mr and nc == mc)
                        continue;

                    if(isInside(nr, nc) and sleep[nr][nc][idx]==INF)
                    {
                        sleep[nr][nc][idx] = sleep[r][c][idx]+1;
                        q.emplace(nr, nc);
                    }
                }
            }
        }

        unsigned long minTime = INF;
        for(int i=1; i<=rows; i++)
            for(int j=1; j<=columns; j++)
            {
                unsigned long time1 = wake[i][j][0] + sleep[i][j][1] + sleep[i][j][2] + sleep[i][j][3];
                unsigned long time2 = wake[i][j][1] + sleep[i][j][0] + sleep[i][j][2] + sleep[i][j][3];
                unsigned long time3 = wake[i][j][2] + sleep[i][j][1] + sleep[i][j][0] + sleep[i][j][3];
                unsigned long time4 = wake[i][j][3] + sleep[i][j][1] + sleep[i][j][2] + sleep[i][j][0];
                minTime = min(minTime, min(time1, min(time2, min(time3, time4))));
            }

        cout << setNum << "\n";
        if(minTime==INF)
            printf("Meeting is impossible.\n");
        else
            printf("Minimum time required is %d minutes.\n", minTime);
    }
    return 0;
}