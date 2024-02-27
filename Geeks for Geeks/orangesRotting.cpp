#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int nrows[] = {0, 0, -1, +1};
    int ncols[] = {-1, +1, 0, 0};
    
    int n = grid.size();
    int m = grid[0].size();
    
    queue<pair<pair<int, int>, int>> q;

    int cntfresh;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==2){
                q.push({{i, j}, 0});
            }
            else if(grid[i][j]==1){
                cntfresh++;
            }
        }
    }
    
    int a, b, t, tm=0, cnt=0;
    
    int nrow, ncol;
    while(!q.empty()){
        a = q.front().first.first;
        b = q.front().first.second;
        t = q.front().second;
        tm = max(tm, t);
        q.pop();

        for(int i=0; i<4; i++){
            nrow = a+nrows[i];
            ncol = b+ncols[i];

            if(nrow<n && ncol<m && nrow>-1 && ncol>-1 && grid[nrow][ncol]==1){
                grid[nrow][ncol]==2;
                q.push({{nrow, ncol}, t+1});
                cnt++;
            }
        }
    }

    if(cnt != cntfresh){
        return -1;
    }

    return tm;
}