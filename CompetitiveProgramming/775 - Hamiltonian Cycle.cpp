#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int n;
vector<int> adj[256], path;
bool vis[256];

bool backtrack()
{
    if(path.size()==n+1)
    {
        if(path.back()==0) return true;
        return false;
    }

    int prev = path.back();
    for(auto it: adj[prev])
    {
        if(vis[it] or (it==0 and path.size()!=n))
            continue;
        vis[it] = 1;
        path.push_back(it);
        if(backtrack())
            return true;
        path.pop_back();
        vis[it] = 0;
    }
    return false;
}

int main()
{
    int i, j, delim;
    string line;
    while(scanf("%d\n", &n)!=EOF)
    {
        path.push_back(0);
        while(getline(cin, line) and line!="%")
        {
            delim = line.find(" ");
            i = stoi(line.substr(0, delim));
            j = stoi(line.substr(delim+1));

            adj[i-1].push_back(j-1);
            adj[j-1].push_back(i-1);
        }

        memset(vis, 0, n);
        if(backtrack())
            for(auto& it: path)
                cout << it+1 << ((&it == &path.back())?"\n":" ");
        else
            cout << "N\n";

        for(int i=0; i<n; i++)
            adj[i].clear();
        path.clear();
    }
    return 0;
}