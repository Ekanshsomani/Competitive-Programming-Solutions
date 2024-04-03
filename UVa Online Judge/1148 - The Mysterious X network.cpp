#include <bits/stdc++.h>

using namespace std;

typedef pair<int , int> ii;

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int V;
        cin >> V;

        vector<int> adj[V];
        for(int i=0; i<V; i++)
        {
            int u, n;
            cin >> u >> n;
            while(n--)
            {
                int v;
                cin >> v;
                if(find(adj[u].begin(), adj[u].end(), v)==adj[u].end())
                {
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }

        int start, target;
        cin >> start >> target;
        queue<ii> q;
        vector<bool> vis(V, false);
        
        q.push({start, 0});
        vis[start] = true;
        while(not q.empty())
        {
            auto &[u, w] = q.front();
            q.pop();

            if(u==target)
            {
                printf("%d %d %d\n", start, target, w-1);
                break;
            }

            for(auto v: adj[u])
                if(not vis[v])
                {
                    vis[v] = true;
                    q.push({v, w+1});
                }
        }

        if(testcases) printf("\n");
    }
    return 0;
}