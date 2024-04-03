#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

int main()
{
    int V, E;
    cin >> V >> E;

    vi adj[V+1];
    while(E--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<ii> q;
    vector<bool> vis(V+1, false);
    q.emplace(0, 1);
    vis[1] = true;

    while(not q.empty())
    {
        auto [w, u] = q.front();
        q.pop();

        if(u==V)
        {
            printf("%d\n", w-1);
            break;
        }

        for(auto v: adj[u])
            if(not vis[v])
            {
                vis[v] = true;
                q.emplace(w+1, v);
            }
    }

    return 0;
}