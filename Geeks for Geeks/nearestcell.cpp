#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> nearest(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();

    int nrows[] = {-1, +1, 0, 0};
    int ncols[] = {0, 0, -1, +1};

    vector<vector<int>> dist(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, 0));

    queue <pair<pair<int, int>, int>> q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==1){
                q.push({{i, j}, 0});
                vis[i][j]=1;
            }
            else{
                vis[i][j]=0;
            }
        }
    }

    while(!q.empty()){
        int a = q.front().first.first;
        int b = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        dist[a][b] = steps;
        for(int i=0; i<4; i++){
            int nrow = a + nrows[i];
            int ncol = b + ncols[i];

            if(nrow>-1 && nrow<n && ncol>-1 && ncol < m
            && vis[nrow][ncol]==0){
                    q.push({{nrow, ncol}, steps+1});
                    vis[nrow][ncol] = 1;
            }
        }
    }

    return dist;
}