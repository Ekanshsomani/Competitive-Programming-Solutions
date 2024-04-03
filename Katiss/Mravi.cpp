#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, bool> edge;
typedef vector<edge> ve;
typedef pair<double, int> di;

int main()
{
    int V;
    cin >> V; V++;
    ve parent(V, {0, 100, 0});

    for(int i=2; i<V; i++)
    {
        int u, v, w, s;
        cin >> u >> v >> w >> s;
        parent[v] = edge(u, w, s);
    }

    set<di, greater<di>> pq;
    double leaves[V]; leaves[0] = 0;
    for(int i=1; i<V; i++)
    {
        int honey;
        cin >> honey;
        leaves[i] = honey;
        pq.emplace(leaves[i], i);
    }

    while(not pq.empty())
    {
        auto [d, u] = *pq.begin();
        pq.erase(pq.begin());

        if(d==-1.00) break;

        auto &[v, w, s] = parent[u];
        double minHoney;
        if(s and d>=1.00) minHoney = sqrt(d)*100.00/w;
        else minHoney = d*100.00/w;

        if(minHoney > leaves[v])
        {
            pq.erase({leaves[v], v});
            leaves[v] = minHoney;
            pq.emplace(leaves[v], v);
        }
    }
    printf("%f\n", leaves[0]);
    return 0;
}