#include <bits/stdc++.h>

#define UNVISITED -1

using namespace std;

set<pair<int, int>> critical;
vector<int> *adj;
vector<int> parent, dfsNum, dfsLow;
int n;

inline void findBridges(int node)
{
    for(auto it: adj[node])
    {
        if(dfsNum[it]==UNVISITED)
        {
            dfsNum[it] = dfsLow[it] = dfsNum[node]+1;
            parent[it] = node;
            findBridges(it);

            if(dfsLow[it]>dfsNum[node])
                critical.insert({min(node, it), max(node, it)});
        }

        if(it!=parent[node])
            dfsLow[node] = min(dfsLow[it], dfsLow[node]);
    }
    return;
}

int main()
{
    while(cin >> n)
    {
        adj = new vector<int>[n];
        dfsNum.assign(n, UNVISITED);
        dfsLow.assign(n, UNVISITED);
        parent.assign(n, 0);

        for(int i=0; i<n; i++)
        {
            int node;
            int connections;
            char brace;
            cin >> node >> brace >> connections >> brace;
            adj[node].assign(connections, 0);
            while(connections--)
                cin >> adj[node][connections];
        }

        for(int i=0; i<n; i++)
            if(dfsNum[i]==UNVISITED)
                findBridges(i);
        
        printf("%d critical links\n", critical.size());
        for(auto it: critical)
            printf("%d - %d\n", it.first, it.second);
        printf("\n");

        critical.clear();
    }
    return 0;
}