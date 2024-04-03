#include <bits/stdc++.h>

#define ii pair<int, int>
// #define MAX 100000

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int price[n];
    for(int i=0; i<n; i++)
        cin >> price[i];
    // printf("Created price\n");

    vector<ii> adj[n];
    for(int i=0; i<m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }
    // printf("created adj\n");

    // bool vis[n];
    int cost[n];
    int queries;
    cin >> queries;
    while(queries--)
    {
        int capacity, start, target;
        cin >> capacity >> start >> target;
        
        int memo[n][capacity+1];
        memset(memo, -1, sizeof memo);
        memset(cost, -1, sizeof cost);
        // memset(vis, false, sizeof vis);
        priority_queue<pair<int, ii>> pq;

        // vis[start] = true;
        pq.push({-0, {0, start}});
        bool possible{false};

        while(not pq.empty())
        {
            int spent = -pq.top().first;
            int fuel = pq.top().second.first;
            int node = pq.top().second.second;
            pq.pop();

            if(node==target)
            {
                possible = true;
                printf("%d\n", spent);
                break;
            }
            
            if(memo[node][fuel]!=-1 and memo[node][fuel]<spent) continue;
            memo[node][fuel] = spent;
            
            if(fuel<capacity) 
                pq.push({-(spent+price[node]), {fuel+1, node}});


            // if((spent-fuel*price[node])<cost[node] or cost[node]==-1)
            // {
                // cost[node] = spent-fuel*price[node];
            for(auto it: adj[node])
                if(it.second<=fuel)
                    pq.push({-spent, {fuel-it.second,  it.first}});
            // }
        }

        if(not possible)
            printf("impossible\n");
    }
    return 0;
}