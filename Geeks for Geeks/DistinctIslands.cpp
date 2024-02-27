#include <iostream>
#include <set>
#include <vector>
#include <stack>
using namespace std;

void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis,
vector<pair<int,int>>& vec, int i, int j, int n, int m){
    
    int nrows[] = {-1, +1, 0, 0};
    int ncols[] = {0, 0, -1, +1};
    
    stack<pair<int, int>> s;
    s.push({i, j});

    while(!s.empty()){
        int a = s.top().first;
        int b = s.top().second;
        vec.push_back({a-i, b-j});
        s.pop();

        for(int it=0; it<4; it++){
            int nrow = a+nrows[it];
            int ncol = b+ncols[it];

            if(nrow>-1 && ncol>-1 && nrow<n && ncol<m 
            && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                s.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }
}

int countDistinctIslands(vector<vector<int>>& grid){
    set<vector<pair<int, int>>> st;
    
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==1 && vis[i][j]==0){
                vis[i][j] = 1;
                vector<pair<int, int>> vec;
                dfs(grid, vis, vec, i, j, n, m);
                st.insert(vec);
            }
        }
    }

    return st.size();
}