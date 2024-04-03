#include <bits/stdc++.h>

#define leaveTime second.second
#define reachTime second.first
#define node second.second

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

inline bool customCompare(const iii& a, const iii& b)
{
    if(a.second.first==b.second.first)
        return a.second.second>b.second.second;
    return a.second.first<b.second.first;
}

int main()
{
    int c;
    while(cin >> c and c)
    {
        string cities[c];
        unordered_map<string, int> cityIdx;
        for(int i=0; i<c; i++)
        {
            cin >> cities[i];
            cityIdx[cities[i]] =i;
        }

        vector<iii> adj[c];
        int trains;
        cin >> trains;
        while(trains--)
        {
            int stops;
            cin >> stops;

            string city, time;
            cin >> time >> city;
            int prevIdx, boarding;
            prevIdx = cityIdx[city];
            boarding = stoi(time.substr(0, 2))*60 + stoi(time.substr(2, 2));

            while(stops--)
            {
                cin >> time >> city;
                int currIdx, arrival;
                currIdx = cityIdx[city];
                arrival = stoi(time.substr(0, 2))*60 + stoi(time.substr(2, 2));
                adj[currIdx].push_back({prevIdx, {arrival, boarding}});
            }
        }

        for(int i=0; i<c; i++)
            sort(adj[i].begin(), adj[i].end(), customCompare);

        string destination, time, startCity;
        cin >> time >> startCity >> destination;

        int target = cityIdx[startCity];
        int minTime = stoi(time.substr(0, 2))*60 + stoi(time.substr(2, 2));
        int source = cityIdx[destination];

        // time (the second one or smaller one), the next we visit must have first time smaller than this
        // length (duration) : key for prority queu
        // node

        bool reached{false};
        for(auto it: adj[source])
        {
            priority_queue<iii, vector<iii>, greater<iii>> pq;
            vector<bool> vis(c, false);
            vis[source] = true;
            
            pq.push({it.leaveTime - it.reachTime, {it.reachTime, it.first}});
            while(not pq.empty())
            {
                iii curr = pq.top();
                int duration = curr.first;
                int time = curr.reachTime;
                int u = curr.node;
                pq.pop();

                if(vis[u]) continue;
                vis[u] = true;

                if(u==target)
                {
                    printf("%d %d\n", (100*(time/60) + time%60), 100*(it.leaveTime/60) + it.leaveTime%60);
                    reached = true;
                    break;
                }

                for(auto v: adj[u])
                    if(v.leaveTime <= time)
                        pq.push({duration + v.leaveTime-v.reachTime, {v.reachTime, v.first}});
            }

            if(reached)
                break;
        }

        if(not reached)
            printf("no connection\n");
    }
    return 0;
}