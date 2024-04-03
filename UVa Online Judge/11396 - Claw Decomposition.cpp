#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vertices;
    while(cin >> vertices and vertices)
    {
        vector<int> adj[vertices];
        int a, b;
        while(cin >> a >> b and (a or b))
        {
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }

        bool isBipartite{true};
        vector<int> color(vertices, -1);
        queue<int> nodes;
        for(int i=0; i<vertices; i++)
        {
            if(color[i]==-1)
            {
                color[i] = 0;
                nodes.push(i);

                while(not nodes.empty() and isBipartite)
                {
                    int a = nodes.front();
                    nodes.pop();
                    for(auto it: adj[a])
                        if(color[it]==-1)
                        {
                            color[it] = 1-color[a];
                            nodes.push(it);
                        }
                        else if(color[it]==color[a])
                        {
                            isBipartite = false;
                            break;
                        }
                }
            }
            if(not isBipartite)
                break;
        }

        if(isBipartite)
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;
}