#include <bits/stdc++.h>

#define ii pair<int, int>

using namespace std;

int main()
{
    int elevators, target;
    while(cin >> elevators >> target)
    {
        vector<ii> adj[100];

        int weights[elevators];
        for(int i=0; i<elevators; i++)
            cin >> weights[i];

        string line;
        cin.ignore();
        for(int k=0; k<elevators; k++)
        {
            getline(cin, line);
            istringstream iss(line);

            vector<int> points;
            int floor;
            while(iss >> floor)
                points.push_back(floor);
            
            int l = points.size();
            for(int i=0; i<l; i++)
                for(int j=i+1; j<l; j++)
                {
                    adj[points[j]].push_back({points[i], weights[k]});
                    adj[points[i]].push_back({points[j], weights[k]});
                }
        }

        if(target==0)
        {
            printf("0\n");
            continue;
        }
        
        bitset<100> vis;
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push({-60, 0});
        
        while(not pq.empty())
        {
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();

            if(vis[node]) continue;
            vis[node] = true;

            if(node==target)
            {
                printf("%d\n", time);
                break;
            }

            for(auto it: adj[node])
            {
                int floor = it.first;
                int spent = 60 + it.second*abs(floor-node) + time;
                pq.push({spent, floor});
            }
        }

        if(not vis[target])
            printf("IMPOSSIBLE\n");
    }
    return 0;
}