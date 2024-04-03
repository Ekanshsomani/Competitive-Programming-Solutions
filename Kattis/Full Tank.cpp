#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;

int main()
{
    int V, E;
    cin >> V >> E;

    int price[V];
    for(int i=0; i<V; i++)
        cin >> price[i];

    vii adj[V];
    while(E--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    int queries;
    cin >> queries;
    while(queries--)
    {
        int capacity, start, target;
        cin >> capacity >> start >> target;

        vvi cost(V, vi(capacity+1, INF)); cost[start][0] = 0;
        set<iii> pq; // balanced BST version
        for (int u = 0; u < V; ++u) // dist[u] = INF
            for(int f=0; f<capacity+1; ++f)
                pq.emplace(cost[u][f], u, f);

        // sort the pairs by non-decreasing distance from s
        while (!pq.empty())  // main loop
        {
            auto [c, u, f] = *pq.begin(); // shortest unvisited u
            pq.erase(pq.begin());            

            if(u==target)
                break;

            if(f<capacity and cost[u][f+1]>c+price[u]) 
            {
                pq.erase(pq.find({cost[u][f+1], u, f+1}));
                cost[u][f+1] = c+price[u];
                pq.emplace(cost[u][f+1], u, f+1);
            }

            for (auto &[v, w] : adj[u]) 
            {
                if (f<w or c >= cost[v][f-w]) continue; // not improving, skip
                pq.erase(pq.find({cost[v][f-w], v, f-w})); // erase old pair
                cost[v][f-w] = c; // relax operation
                pq.emplace(cost[v][f-w], v, f-w); // enqueue better pair
            }
        }

        if(cost[target][0]==INF)
            printf("impossible\n");
        else
            printf("%d\n", cost[target][0]);
    }
    return 0;
}