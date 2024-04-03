#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> nodeIdx;
    int nc{}, test{1};
    while(cin >> nc and nc)
    {
        adj.clear();
        nodeIdx.clear();

        int nodes{0};
        while(nc--)
        {
            int a, b;
            cin >>  a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);

            if(not nodeIdx.count(a)) nodeIdx[a] = nodes++;
            if(not nodeIdx.count(b)) nodeIdx[b] = nodes++;
        }
        
        int source, ttl;
        while(cin >> source >> ttl and (source or ttl))
        {
            printf("Case %d: ", test++);
            if(not adj.count(source))
            {
                printf("%d nodes not reachable from node %d with TTL = %d.\n", nodes, source, ttl);
                continue;
            }
            else if (ttl==0)
            {
                printf("%d nodes not reachable from node %d with TTL = %d.\n", nodes-1, source, ttl);
                continue;
            }

            vector<bool> vis(nodes, false);
            queue<ii> q;

            q.push({source, ttl});
            vis[nodeIdx[source]] = true;
            int unvisited{nodes-1};

            while(not q.empty())
            {
                auto &[u, tval] = q.front();
                q.pop();

                for(auto v: adj[u])
                    if(not vis[nodeIdx[v]])
                    {
                        unvisited--;
                        vis[nodeIdx[v]] = true;
                        if(tval>1) q.push({v, tval-1});
                    }
            }

            printf("%d nodes not reachable from node %d with TTL = %d.\n", unvisited, source, ttl);
        }
    }
    return 0;
}