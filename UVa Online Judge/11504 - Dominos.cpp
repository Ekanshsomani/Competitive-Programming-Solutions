#include <bits/stdc++.h>

using namespace std;

vector<int> *adj;
vector<bool> vis;
stack<int> st;
int n;

inline void dfs(int node)
{
    vis[node] = true;
    for(auto it: adj[node])
        if(not vis[it])
            dfs(it);
}

inline void topologicalSort(int node)
{
    vis[node] = true;
    for(auto it: adj[node])
        if(not vis[it])
            topologicalSort(it);
    
    st.push(node);
}

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int m;
        cin >> n >> m;
        adj = new vector<int>[n];

        while(m--)
        {
            int a, b;
            cin >> a >> b;
            adj[a-1].push_back(b-1);
        }

		vis.assign(n, false);
        for(int i=0; i<n; i++)
            if(not vis[i])
                topologicalSort(i);

        int tip{0};
        vis.assign(n, false);
        while(not st.empty())
        {
            if(not vis[st.top()])
            {
                dfs(st.top());
                tip++;
            }
            st.pop();
        }

        printf("%d\n", tip);
    }
}