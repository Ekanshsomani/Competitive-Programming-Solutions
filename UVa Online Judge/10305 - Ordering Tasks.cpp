#include <bits/stdc++.h>
using namespace std;

int nodes, edges;
vector<int> adj[100];
stack<int> ts;
bitset<100> vis;

void dfs(int idx)
{
    vis[idx] = 1;
    for(auto it: adj[idx])
        if(!vis[it])
            dfs(it);
    ts.push(idx);
}

int main()
{
    while(cin >> nodes >> edges and (nodes or edges))
    {
        for(int i=0; i<nodes; i++)
            adj[i].clear();
        vis.reset();

        int i, j;
        while(edges--)
        {
            cin >> i >> j;
            adj[i-1].push_back(j-1);
        }

        for(int i=0; i<nodes; i++)
            if(!vis[i])
                dfs(i);

        while(!ts.empty())
        {
            cout << ts.top()+1;
            ts.pop();
            cout << (ts.empty() ? "\n": " ");
        }
    }
    return 0;
}