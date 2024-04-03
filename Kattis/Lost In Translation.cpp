#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;

int main()
{
    int V, E;
    cin >> V >> E;
    V++;

    unordered_map<string, int> langIdx;
    langIdx["English"] = 0;
    for(int i=1; i<V; i++)
    {
        string s;
        cin >> s;
        langIdx[s] = i;
    }

    vii adj[V];
    while(E--)
    {
        string s1, s2;
        int w;
        cin >> s1 >> s2 >> w;
        adj[langIdx[s1]].emplace_back(langIdx[s2], w);
        adj[langIdx[s2]].emplace_back(langIdx[s1], w);
    }

    int start{0};
    vi dist(V, INF), cost(V, INF); 
    dist[start] = 0;
    cost[start] = 0;

    set<iii> pq; // balanced BST version
    for (int u = 0; u < V; ++u) // dist[u] = INF
        pq.emplace(dist[u], cost[u], u); // but dist[s] = 0

    // sort the pairs by non-decreasing distance from s
    while (!pq.empty())  // main loop
    {
        auto [d, c, u] = *pq.begin(); // shortest unvisited u
        pq.erase(pq.begin());
        
        for (auto &[v, w] : adj[u]) 
        { // all edges from u
            if (dist[u]+1 > dist[v]) continue; // not improving, skip
            if((dist[u]+1 == dist[v]) and w>=cost[v]) continue;
            pq.erase(pq.find({dist[v], cost[v], v})); // erase old pair
            dist[v] = dist[u]+1; // relax operation
            cost[v] = w;
            pq.emplace(dist[v], w, v); // enqueue better pair
        }
    }

    int totalCost{0};
    for(int i=0; i<V; i++)
    {
        if(cost[i]==INF)
        {
            printf("Impossible\n");
            return 0;
        }
        totalCost += cost[i];
    }
    printf("%d\n", totalCost);
    return 0;
}