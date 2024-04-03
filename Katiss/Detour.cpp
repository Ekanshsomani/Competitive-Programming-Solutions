#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;

stack<int> st;
vi shortest;
vector<bool> vis;

inline bool dfs(int node, vii adj[])
{
    if(node==1)
        return true;
    vis[node] = true;
    int topMost = st.top();

    for(auto [v, w]: adj[node])
        if(not vis[v] and shortest[node]!=v)
            if(dfs(v, adj))
            {
                st.push(v);
                return true;
            }
    while(st.top()!=topMost)
        st.pop();
    return false;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vii adj[V];
    while(E--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vi dist(V, INF); dist[1] = 0; // INF = 1e9 here
    shortest.assign(V, -1);
    
    set<ii> pq; // balanced BST version
    for (int u = 0; u < V; ++u) // dist[u] = INF
        pq.emplace(dist[u], u); // but dist[s] = 0

    // sort the pairs by non-decreasing distance from s
    while (!pq.empty())  // main loop
    {
        auto [d, u] = *pq.begin(); // shortest unvisited u
        pq.erase(pq.begin());
        
        for (auto &[v, w] : adj[u]) 
        { // all edges from u
            if (dist[u]+w >= dist[v]) continue; // not improving, skip
            shortest[v] = u;
            pq.erase(pq.find({dist[v], v})); // erase old pair
            dist[v] = dist[u]+w; // relax operation
            pq.emplace(dist[v], v); // enqueue better pair
        }
    }

    vis.assign(V, false);
    st.push(0);
    if(not dfs(0, adj))
        printf("impossible\n");
    else
    {
        st.push(0);
        int l = st.size()-1;
        printf("%d ", l);
        while(l--)
        {
            cout << st.top() << (l ? " " : "\n");
            st.pop();
        }
    }
    return 0;
}