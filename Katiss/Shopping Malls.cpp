#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, double> id;
typedef pair<double, int> di;
typedef vector<id> vid;
typedef vector<double> vd;
typedef vector<int> vi;

const double INF = 0x3f3f3f3f;

inline double euclidianDist(iii &a, iii&b)
{
    auto &[f1, x1, y1] = a;
    auto &[f2, x2, y2] = b;
    return sqrt( 
        25*(f1-f2)*(f1-f2) +
        (x1-x2)*(x1-x2) + 
        (y1-y2)*(y1-y2)
    );
}

int main()
{
    int V, E;
    cin >> V >> E;

    iii vertices[V];
    for(int i=0; i<V; i++)
    {
        int floor, x, y;
        cin >> floor >> x >> y;
        vertices[i] = {floor, x, y};
    }

    vid adj[V];
    while(E--)
    {
        string id;
        int u, v;
        cin >> u >> v >> id;
        double w = euclidianDist(vertices[u], vertices[v]);
        if(id[0]=='w' or id[0]=='s')
        {
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        else if(id[0]=='l')
        {
            adj[u].emplace_back(v, 1);
            adj[v].emplace_back(u, 1);
        }
        else
        {
            adj[u].emplace_back(v, 1);
            adj[v].emplace_back(u, 3*w);
        }
    }

    int  queries;
    cin >> queries;
    while(queries--)
    {
        int start, target;
        cin >> start >> target;
        vd dist(V, INF); dist[start] = 0.0; // INF = 1e9 here
        vi parent(V, -1);
        set<di> pq; // balanced BST version
        for (int u = 0; u < V; ++u) // dist[u] = INF
            pq.emplace(dist[u], u); // but dist[s] = 0

        stack<int> path;

        while (!pq.empty())  // main loop
        {
            auto [d, u] = *pq.begin(); // shortest unvisited u
            pq.erase(pq.begin());
            
            if(u==target)
            {
                while(u!=-1)
                {
                    path.push(u);
                    u=parent[u];
                }
                break;
            }


            for (auto &[v, w] : adj[u]) 
            {
                if (dist[u]+w >= dist[v]) continue; // not improving, skip
                parent[v] = u;
                pq.erase(pq.find({dist[v], v})); // erase old pair
                dist[v] = dist[u]+w; // relax operation
                pq.emplace(dist[v], v); // enqueue better pair
            }
        }

        int l = path.size();
        while(l--)
        {
            cout << path.top() << (l ? " " : "\n");
            path.pop();
        }
    }
    return 0;
}