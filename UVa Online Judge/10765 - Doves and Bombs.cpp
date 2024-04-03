#include <bits/stdc++.h>

#define UNVISITED -1

using namespace std;

struct compare
{
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) const
    {
        if(a.second==b.second)
            return a.first<b.first;
        return a.second>b.second;
    }
};

vector<int> *adj;
vector<int> parent, dfsNum, dfsLow, artPoints;
int n, m;

inline void findArtPoint(int node)
{
    for(auto it: adj[node])
        if(dfsNum[it]==UNVISITED)
        {
            parent[it] = node;
            dfsNum[it] = dfsLow[it] = dfsNum[node]+1;
            findArtPoint(it);
            if(dfsLow[it]>=dfsNum[node])
                artPoints[node]++;
            dfsLow[node] = min(dfsLow[node], dfsLow[it]);
        }
        else if(parent[node]!=it)
            dfsLow[node] = min(dfsLow[node], dfsNum[it]);
    return;
}

int main()
{
    set<pair<int, int>, compare> targets;
    while(cin >> n >> m and (n or m))
    {
        adj = new vector<int>[n];
        parent.assign(n, 0);
        dfsNum.assign(n, UNVISITED);
        dfsLow.assign(n, UNVISITED);
        artPoints.assign(n, 0);

        int i, j;
        while(cin >> i >> j and (i>-1 or j>-1))
        {
            adj[i].push_back(j);
            adj[j].push_back(i);
        }

        artPoints[0] = -1;
        dfsNum[0] = 1;
        dfsLow[0] = 1;
        for(auto it: adj[0])
            if(dfsNum[it]==UNVISITED)
            {
                artPoints[0]++;
                dfsNum[it] = 2;
                dfsLow[it] = 2;
                findArtPoint(it);
            }

        for(int i=0; i<n; i++)
            targets.insert({i, artPoints[i]+1});
        
        auto it = targets.begin();
        while(m--)
        {
            printf("%d %d\n", (*it).first, (*it).second);
            it++;
        }
        printf("\n");

        targets.clear();
    }
    return 0;
}