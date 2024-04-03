#include <bits/stdc++.h>

#define ii pair<int, int>

using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for(int t=1; t<=testcases; t++)
    {
        int n, connections, start, target;
        cin >> n >> connections >> start >> target;

        vector<ii> adj[n];
        while(connections--)
        {
            int a, b, w;
            cin >> a >> b >> w;
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }

        vector<int> latency(n, -1);
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push({0, start});

        while(not pq.empty())
        {
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();

            if(latency[node]!=-1 and time>=latency[node])
                continue;
            latency[node] = time;

            if(node==target)
                break;

            for(auto it: adj[node])
                pq.push({it.second+time, it.first});
        }

        printf("Case #%d: ", t);
        if(latency[target]==-1)
            printf("unreachable\n");
        else
            printf("%d\n", latency[target]);
    }
    
    return 0;
}