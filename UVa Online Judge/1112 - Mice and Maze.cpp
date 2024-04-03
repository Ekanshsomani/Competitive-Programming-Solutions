#include <bits/stdc++.h>

#define ii pair<int, int>

using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int n, start, maxTime, connections;
        cin >> n >> start >> maxTime >> connections;

        vector<ii> adj[n+1];
        while(connections--)
        {
            int a, b, units;
            cin >> a >> b >> units;
            adj[b].push_back({a, units});
        }

        int escaped{0};
        vector<int> escapeTime(n+1, -1);
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push({0, start});

        while(not pq.empty())
        {
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(time>maxTime)
                break;

            if(escapeTime[node]==-1)
                escaped++;
            else if(time>=escapeTime[node])
                continue;
            escapeTime[node] = time;

            for(auto it: adj[node])
                pq.push({it.second+time, it.first});
        }

        printf("%d\n", escaped);
        if(testcases)
            printf("\n");
    }
    return 0;
}