#include <bits/stdc++.h>
using namespace std;

int memo[50001];
bool vis[50001];
int graph[50001];
int nodes;

inline int dfs(int idx)
{
    vis[idx] = 1;
    int ans = 1;
    if(graph[idx] and not vis[graph[idx]])
        ans += dfs(graph[idx]);
    vis[idx] = 0;
    return memo[idx] = ans;
}

int main()
{
    int testcases;
    cin >> testcases;
    for(int t=1; t<=testcases; t++)
    {
        cin >> nodes;
        fill(graph, graph+nodes+1, 0);
        fill(memo, memo+nodes+1, -1);

        for(int i=0; i<nodes; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u] = v;
        }

        int maxVis{0}, start{0};
        for(int i=1; i<=nodes; i++)
        {
            if(memo[i]==-1)
                dfs(i);
            
            if(maxVis <  memo[i])
            {
                start = i;
                maxVis = memo[i];
            }
        }

        printf("Case %d: %d\n", t, start);
    }
    return 0;
}