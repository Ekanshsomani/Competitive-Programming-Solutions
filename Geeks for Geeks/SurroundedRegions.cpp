#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void dfs(int n, int m, vector<vector<char>>& mat, 
vector<vector<int>>& vis, int row, int col,
vector<vector<char>>& ngrid){
    ngrid[row][col] = 'O';

    int nrows[] = {-1, +1, 0, 0};
    int ncols[] = {0, 0, -1, +1};

    for(int i=0; i<4; i++){
        int nrow = row + nrows[i];
        int ncol = col + ncols[i];

        if(nrow>-1 && ncol>-1 && nrow<n && ncol<n
        && vis[nrow][ncol]==0 && mat[nrow][ncol]=='O'){
            vis[nrow][ncol]=1;
            dfs(n, m, mat, vis, nrow, ncol, ngrid);
        }
    }

}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
    vector<vector<char>> ngrid(n, vector<char>(m, 'X'));
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if((i==0 || i==n-1 || j==0 || j==m-1) && vis[i][j]==0){
                vis[i][j] = 1;
                dfs(n, m, mat, vis, i, j, ngrid);
            }
        }
    }

    return ngrid;
}