#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    while(getline(cin, line) and line[0]!='0')
    {
        int n = stoi(line);
        vector<int> adj[n];

        while(getline(cin, line) and line[0]!='0')
        {
            istringstream iss(line);
            int a, b;
            iss >> a;
            while(iss >> b) 
            {
                adj[a-1].push_back(b-1);
                adj[b-1].push_back(a-1);
            }
        }

        int critical{0};
        for(int i=0; i<n; i++)
        {
            vector<bool> vis(n, 0);
            vis[i] = 1;
            int start = (i ? 0 : 1);

            queue<int> q;
            vis[start] = 1;
            q.push(start);

            while(not q.empty())
            {
                int a = q.front();
                q.pop();

                for(auto it: adj[a])
                    if(not vis[it])
                    {
                        vis[it] = 1;
                        q.push(it);
                    }
            }

            if(find(vis.begin(), vis.end(), false)!=vis.end())
                critical++;
        }

        printf("%d\n", critical);
    }
    return 0;
}