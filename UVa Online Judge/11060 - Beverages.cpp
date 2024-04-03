#include <bits/stdc++.h>
using namespace std;

int nodes;
vector<int> adj[100], ans;
bitset<100> vis;

void kahns(int node)
{
    ans.push_back(node);
    vis[node] = 1;

    if(ans.size()==nodes)
        return;
    
    for(int i=0; i<nodes; i++)
        if(not vis[i])
        {
            bool addable{true};
            for(auto it: adj[i])
                if(not vis[it])
                    addable = false;

            if(addable)
                {kahns(i); break;}
        }
    return;
}

int main()
{
    int test{1}, edges;
    unordered_map<string, int> indices;
    string names[100];

    while(cin >> nodes)
    {
        for(int i=0; i<nodes; i++)
            adj[i].clear();
        indices.clear();
        vis.reset();
        ans.clear();

        for(int i=0; i<nodes; i++)
        {
            cin >> names[i];
            // cout << names[i] << endl;
            indices[names[i]] = i;
        }

        cin >> edges;
        while(edges--)
        {
            string b1, b2;
            cin >> b1 >> b2;
            // cout << b1 << " " << b2 << endl;
            adj[indices[b2]].push_back(indices[b1]);
        }

        for(int i=0; i<nodes; i++)
            if(adj[i].size()==0)
            {
                kahns(i);
                break;
            }

        printf("Case #%d: Dilbert should drink beverages in this order: ", test++);
        for(int i=0; i<nodes; i++)
            cout << names[ans[i]] << (i==nodes-1 ? ".\n" : " ");
        printf("\n");
    }
    return 0;
}