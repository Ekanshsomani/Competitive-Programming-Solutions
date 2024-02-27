#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int MinimumEffort(vector<vector<int>>& heights) {
    priority_queue<pair<int, pair<int, int>>, 
    vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> dis(n, vector<int>(m,1e9));

    pq.push({0,{0,0}});
    dis[0][0] = 0;

    int nrows[] = {-1, +1, 0, 0};
    int ncols[] = {0, 0, -1, +1};

    int x, y, tdist, h1;
    int adx, ady, h2, absdif;
    while(!pq.empty()){
        y = pq.top().second.second;
        x = pq.top().second.first;
        tdist = pq.top().first;
        h1 = heights[y][x];
        pq.pop();

        for(int i=0; i<4; i++){
            adx = x+ncols[i];
            ady = y+nrows[i];
            

            if(adx>-1 && adx<m && ady>-1 && ady<n){
                h2 = heights[ady][adx];
                absdif = abs(h2-h1);
                if(absdif>tdist && dis[ady][adx]>absdif){
                    dis[ady][adx]=absdif;
                    pq.push({absdif, {adx, ady}});
                }
                else if(absdif<tdist && dis[ady][adx]>tdist){
                    dis[ady][adx] = tdist;
                    pq.push({tdist, {adx, ady}});
                }
            }
        }
    }

    return dis[n-1][m-1];
}