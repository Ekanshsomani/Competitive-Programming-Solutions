// 539

#include <iostream>
#include <vector>
using namespace std;

int nodes, edges;
int nodeVis{0}, edgeVis[25]={0};

vector<int> adj[25];

int longestLength(int val)
{
    int maxLength{0};
    for(auto it: adj[val])
        if((edgeVis[it]&(1<<val))==0)
        {
            edgeVis[it] |= (1<<val);
            edgeVis[val] |= (1<<it);
            maxLength = max(1+longestLength(it), maxLength);
            edgeVis[it] &= ~(1<<val);
            edgeVis[val] &= ~(1<<it);
        }
    return maxLength;
}

int main()
{
    int a, b;
    while(cin >> nodes >> edges and nodes and edges)
    {
        for(int i=0; i<nodes; i++) 
            adj[i].clear();

        for(int i=0; i<edges; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        nodeVis = 0;
        int ans{0};
        for(int i=0; i<nodes; i++)
            ans = max(longestLength(i), ans);

        cout << ans << "\n";
    }
    return 0;
}