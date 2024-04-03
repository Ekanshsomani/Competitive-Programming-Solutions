#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

const int INF = 2000;

int main()
{
    int V, E, H;
    cin >> V >> H >> E;

    vi horror(V, INF);
    queue<int> q;
    vb vis(V, false);

    while(H--)
    {
        int node;
        cin >> node;
        horror[node] = 0;
        q.push(node);
        vis[node] = true;
    }

    vi adj[V];
    while(E--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while(not q.empty())
    {
        int u = q.front();
        q.pop();

        for(auto v: adj[u])
            if(not vis[v])
            {
                horror[v] = horror[u]+1;
                vis[v] = true;
                q.push(v);
            }
    }

    printf("%d\n", max_element(horror.begin(), horror.end()) - horror.begin());
    return 0;
}