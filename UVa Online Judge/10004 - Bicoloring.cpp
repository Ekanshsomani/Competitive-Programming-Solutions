#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, l;
    while(cin >> n and n)
    {
        vector<int> adj[n];
        
        for(int i=0; i<n; i++)
            adj[i].clear();

        cin >> l;
        while(l--)
        {
            int i, j;
            cin >> i >> j;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }

        vector<int> color(n, -1);
        queue<int> nodes;
        color[0] = 0;
        nodes.push(0);

        bool isBipartite{true};
        while(not nodes.empty() and isBipartite)
        {
            int a = nodes.front();
            nodes.pop();

            for(auto it: adj[a])
                if(color[it]==-1)
                {
                    color[it] = 1-color[a];
                    nodes.push(it);
                }
                else if(color[it]==color[a])
                {
                    isBipartite = false;
                    break;
                }
        }

        if(isBipartite)
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
    }
    return 0;
}