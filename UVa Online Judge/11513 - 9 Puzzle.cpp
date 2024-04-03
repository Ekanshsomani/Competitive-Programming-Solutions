#include <bits/stdc++.h>

#define ss pair<string, string>

using namespace std;

// use strings to identify puzzle
// store them in an unordered_set vis
// if the string is equal to target

unordered_map<string, string> path;
string start {"123456789"};

inline string leftShift(string s, int row)
{
    row *= 3;
    char top = s[row];
    s[row] = s[row + 1];
    s[row+1] = s[row+2];
    s[row+2] = top;
    return s;
}

inline string downShift(string s, int col)
{
    char bottom = s[6+col];
    s[6+col] = s[3+col];
    s[3+col] = s[col];
    s[col] = bottom;
    return s;
}

inline void bfs()
{
    queue<string> q;
    q.push(start);
    while(not q.empty())
    {
        string s = q.front();
        q.pop();

        for(int i=2; i>-1; i--)
        {
            char num = '1'+i;

            string ns = leftShift(s, i);
            if(not path.count(ns))
            {
                path[ns] = "H"+string(1, num);
                path[ns] += path[s];
                q.push({ns});
            }

            ns = downShift(s, i);
            if(not path.count(ns))
            {
                path[ns] = "V"+string(1, num);
                path[ns] += path[s];
                q.push(ns);
            }
        }
    }
}


int main()
{
    bfs();
    char a;
    while(cin >> a and a>'0')
    {
        string target{"123456789"};
        target[0] = a;
        for(int i=1; i<9; i++)
            cin >> target[i];

        if(path.count(target))
            cout << ((path[target].size())>>1) << " " << path[target] << "\n";
        else
            cout << "Not solvable\n";
    }
    return 0;
}