#include <iostream>
#include <string>
#include <set>
using namespace std;

bool compare(const string& a, const string& b)
{
    if(a.length()==b.length())
        return a<b;
    return a.length()<b.length();
}

char table[20][20];
set<string, decltype(compare)*> dict(compare);
int n;

int col[] = {1, -1, 0, 0, +1, -1, +1, -1};
int row[] = {0, 0, 1, -1, +1, +1, -1, -1};

bool isLegal(int i, int j)
{
    if(i>=0 and i<n and j>=0 and j<n )
        return true;
    return false;
}

void backtrack(int x, int y, string s)
{
    int l = s.length();
    if(l>2)
        dict.insert(s);
    
    if(l==n*n)
        return;

    for(int i=0; i<8; i++)
        if(isLegal(x+col[i], y+row[i]) and s[l-1]<table[x+col[i]][y+row[i]])
            backtrack(x+col[i], y+row[i], s+table[x+col[i]][y+row[i]]);
}



int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        cin >> n;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin >> table[i][j];
            }
        }

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                backtrack(i, j, string(1, table[i][j]));

        for(auto it: dict)
            cout << it << endl;

        if(testcases) 
        {
            dict.clear();
            cout << endl;
        }
    }
    return 0;
}