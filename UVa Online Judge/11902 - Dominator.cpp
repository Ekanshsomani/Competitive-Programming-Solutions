#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[100];
bitset<100> vis, reach;

void dfs(int idx)
{
    vis[idx] = 1;

    for(auto it: adj[idx])
        if(!vis[it])
            dfs(it);
}

int main()
{
    int testcases;
    cin >> testcases;
    for(int test=1; test<=testcases; test++)
    {
        cin >> n;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                int val;
                cin >> val;
                if(val)
                    adj[i].push_back(j);
            }

        string s{"+"};
        for(int i=0; i<n; i++)
            s += "--";
        s = s.substr(0, s.size()-1) + "+\n";

        printf("Case %d:\n", test);
        dfs(0);
        cout << s;
        for(int j=0; j<n; j++)
        {
            reach[j] = vis[j];
            cout << (vis[j] ? "|Y" : "|N");
        }
        printf("|\n");
        vis.reset();
        for(int i=1; i<n; i++)
        {
            cout << s;
            for(int j=0; j<n; j++)
            {
                if(!reach[j] or !reach[i])
                    printf("|N");
                else if(i==j)
                    printf("|Y");
                else
                {
                    vis[i] = 1;
                    dfs(0);
                    cout << (vis[j] ? "|N" : "|Y");
                    vis.reset();
                }
            }
            printf("|\n");
        }
        cout << s;

        reach.reset();
        for(int i=0; i<n; i++)
            adj[i].clear();
    }
    return 0;
}