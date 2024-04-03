#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;

inline int getWeight(int x1, int y1, int x2, int y2)
{
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main()
{
    int V;
    cin >> V;
    V += 2;
    int xc[V], yc[V];
    for(int i=0; i<V; i++)
        cin >> xc[i] >> yc[i];

    // cout << "Successfully read in the coordinates" << endl;

    vii adj[V];
    for(int i=0; i<V; i++)
        for(int j=i+1; j<V; j++)
        {
            int w = getWeight(xc[i], yc[i], xc[j], yc[j]);
            adj[i].emplace_back(j, w);
            adj[j].emplace_back(i, w);
            // cout << i << "-" << j << "-" << w << endl;
        }

    // cout << "Successfully created the adjacency matrix" << endl;

    vi dist(V, INF); dist[V-2] = 0; //
    vi parent(V, -1);

    // cout << "Successfully created the dist and parent vecs" << endl;

    set<ii> pq; // balanced BST version
    for (int u = 0; u < V; ++u) // dist[u] = INF
        pq.emplace(dist[u], u); // but dist[s] = 0

    // cout << "Successfully created the pq heap" << endl;

    // sort the pairs by non-decreasing distance from s
    while (!pq.empty())  // main loop
    {
        auto [d, u] = *pq.begin(); // shortest unvisited u
        pq.erase(pq.begin());

        // cout << d << " " << u << endl;

        if(u == (V-1))
        {
            u = parent[u];
            if(parent[u]==-1)
                printf("-\n");
            stack<int> st;
            while(parent[u]!=-1)
            {
                st.push(u);
                u = parent[u];
            }
            while(not st.empty())
            {
                printf("%d\n", st.top());
                st.pop();
            }
            break;
        }
        
        for (auto &[v, w] : adj[u]) 
        { // all edges from u
            // cout << v << " " << w << " " << dist[v] << endl;
            if (d+w >= dist[v]) continue; // not improving, skip
            pq.erase(pq.find({dist[v], v})); // erase old pair
            dist[v] = dist[u]+w; // relax operation
            parent[v] = u;
            pq.emplace(dist[v], v); // enqueue better pair
        }
    }
    return 0;
}