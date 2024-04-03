#include <bits/stdc++.h>
using namespace std;

vector<string> formulae;

int compute(int i, int j, vector<vector<int>>& memo, vector<vector<int>>& index)
{
    if(index[i][j]==-1)
        return memo[i][j];

    int& ans = memo[i][j];

    ans = 0;
    istringstream iss(formulae[index[i][j]]);
    string cell;
    while(getline(iss, cell, '+'))
    {
        int idx = 0;
        int col = 0;
        while(cell[idx]>64)
        {
            col*=26;
            col += cell[idx]-64;
            idx++;
        }
        col--;
        int row = stoi(cell.substr(idx)) - 1;
        ans += compute(row,  col, memo,  index);
    }
    index[i][j] = -1;
    return ans;
}

int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int columns, rows;
        cin >> columns >> rows;
        formulae.clear();
        vector<vector<int>> memo(rows, vector<int>(columns, -1));
        vector<vector<int>> index(rows, vector<int>(columns, -1));

        for(int i=0; i<rows; i++)
            for(int j=0; j<columns; j++)
            {
                string s;
                cin >> s;
                if(s[0]=='=')
                {
                    index[i][j] = formulae.size();
                    formulae.push_back(s.substr(1));
                }
                else
                    memo[i][j] = stoi(s);
            }

        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<columns-1; j++)
                printf("%d ", compute(i, j, memo, index));
            printf("%d\n", compute(i, columns-1, memo, index));
        }
    }
    
    return 0;
}