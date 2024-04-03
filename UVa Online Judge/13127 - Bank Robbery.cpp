#include <bits/stdc++.h>



using namespace std;

typedef pair<int, int> ii;

const int INF = 1e9; // 10^9 = 1B is < 2^31-1


int main()
{
    int V, E, B, P;
    while(cin >> V)
    {
        cin >> E >> B >> P;

        vector<ii> adj[V];
        while(E--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> banks(B);
        for(int i=0; i<B; i++)
            cin >> banks[i];

        set<ii> pq; vector<int> dist(V, INF);
        while(P--)
        {
            int u;
            cin >> u;
            dist[u] = 0;
        }

        for (int u = 0; u < V; ++u) // dist[u] = INF
            pq.emplace(dist[u], u); // but dist[s] = 0
    
        // sort the pairs by non-decreasing distance from s
        while (!pq.empty())  // main loop
        {
            auto [d, u] = *pq.begin(); // shortest unvisited u
            pq.erase(pq.begin());
            
            for (auto &[v, w] : adj[u]) 
            {
                if (dist[u]+w >= dist[v]) continue; // not improving, skip
                pq.erase(pq.find({dist[v], v})); // erase old pair
                dist[v] = dist[u]+w; // relax operation
                pq.emplace(dist[v], v); // enqueue better pair
            }
        }

        int minDist = 0;
        vector<int> furthest;
        for(auto i: banks)
            if(dist[i]>minDist)
            {
                minDist = dist[i];
                furthest.clear();
                furthest.push_back(i);
            }
            else if(dist[i]==minDist)
                furthest.push_back(i);
        sort(furthest.begin(), furthest.end());

        int l = furthest.size();
        printf("%d ", l);
        if(minDist==INF)
            printf("*\n");
        else
            printf("%d\n", minDist);
        
        for(int i=0; i<l; i++)
            cout << furthest[i] << (i==l-1 ? "\n" : " ");;

    }
    return 0;
}