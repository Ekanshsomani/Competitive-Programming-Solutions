#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef tuple<int, int, int> iii;

const int INF = 0x3f3f3f3f;
int dist[100][100];

int main()
{
    int testcases;
    cin >> testcases;
    for(int t=1; t<=testcases; t++)
    {
        int V;
        cin >> V;
        unordered_map<string, int> nameIdx;
        vii adj[V];

        for(int i=0; i<V; i++)
        {
            string name;
            cin >> name;
            nameIdx[name] = i;
        }
        int start, target;
        start = nameIdx["Calgary"];
        target = nameIdx["Fredericton"];
        // printf("%d-%d\n", start, target);

        int E;
        cin >> E;
        while(E--)
        {
            string u, v;
            int w;
            cin >> u >> v >> w;
            adj[nameIdx[u]].emplace_back(nameIdx[v], w);
        }

        memset(dist, INF, sizeof dist);
        dist[start][0] = 0; // city, stopovers
        priority_queue<iii, vector<iii>, greater<iii>> pq;
        for(auto &[v, w]: adj[start])
            if(dist[v][0]>w)
            {
                dist[v][0] = w;
                pq.emplace(w, 0, v);
            }

        while(not pq.empty())
        {
            auto [d, s, u] = pq.top();
            pq.pop();

            if(dist[u][s] < d or u==target) continue;

            for(auto &[v, w]: adj[u])
            {
                if(dist[v][s+1] <= d+w) continue;
                dist[v][s+1] = d+w;
                pq.emplace(d+w, s+1, v);
            }
        }

        printf("Scenario #%d\n", t);
        int queries;
        cin >> queries;
        while(queries--)
        {
            int maxStops;
            cin >> maxStops; maxStops++;
            int cost = *min_element(dist[target], dist[target] + maxStops);
            if(cost<INF)
                printf("Total cost of flight(s) is $%d\n", cost);
            else
                printf("No satisfactory flights\n");
        }
        if(t<testcases)
            printf("\n");
    }
    return 0;
}