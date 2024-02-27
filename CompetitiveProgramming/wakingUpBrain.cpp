// 10507

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// UnionFind
// Constructor(int N)
// findSet
// isSameSet
// UnionSet

class UnionFind
{
    private: 
        vector<int> p, rank;
    
    public:    
        UnionFind(int N)
        {
            rank.assign(N, 0);
            p.assign(N, 0);
            for (int i = 0; i < N; i++) 
                p[i] = i; 
        }
        
        int findSet(int i) 
        { 
            return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
        }
        
        bool isSameSet(int i, int j) 
        { 
            return findSet(i) == findSet(j); 
        }
        
        void unionSet(int i, int j) 
        {
            if (!isSameSet(i, j)) 
            {
                int x = findSet(i), y = findSet(j);
                if (rank[x] > rank[y])
                    p[y] = x;
                else 
                {
                    p[x] = y;
                    if (rank[x] == rank[y]) rank[y]++; 
                }
            }
        }
};

int main()
{
    int nodes;
    while(cin >> nodes)
    {
        int edges;
        cin >> edges;

        UnionFind awake(nodes), connected(nodes);
        unordered_map<char, int> nodeIndex;
        unordered_map<int, vector<int>> adj;

        char a, b, c;
        cin >> a >> b >> c;

        nodeIndex[a] = 0;
        nodeIndex[b] = 1;
        nodeIndex[c] = 2;

        awake.unionSet(1, 0);
        awake.unionSet(2, 0);

        int size{3};
        while(edges--)
        {
            cin >> a >> b;
            if(!nodeIndex.count(a))
            {
                nodeIndex[a] = size;
                size++;
            }
            if(!nodeIndex.count(b))
            {
                nodeIndex[b] = size;
                size++;
            }

            if(!adj.count(nodeIndex[a])) adj[nodeIndex[a]] = {};
            if(!adj.count(nodeIndex[b])) adj[nodeIndex[b]] = {};

            adj[nodeIndex[a]].push_back(nodeIndex[b]);
            adj[nodeIndex[b]].push_back(nodeIndex[a]);

            connected.unionSet(nodeIndex[a], nodeIndex[b]);
        }

        if(nodes==3)
        {
            cout << "WAKE UP IN, 0, YEARS" << endl;
            continue;
        }

        bool possible{1};

        if(size!=nodes) possible = 0;
        for(int i=1; i<nodes; i++)
        {
            if(!possible) break;

            if(!connected.isSameSet(i, i-1) || (i>2 && adj[i].size()<3))
                possible = 0;
        }

        int wake = 3;
        int year{0};
        while(wake<nodes && possible)
        {
            vector<int> toAdd;
            for(int i=3; i<nodes; i++)
            {
                if(!awake.isSameSet(i, 0))
                {
                    int connections{0};
                    for(auto it: adj[i])
                        if(awake.isSameSet(it, 0)) connections++;
                    if(connections>2) toAdd.push_back(i);
                }
            }

            if(toAdd.empty()) possible = 0;
            year++;
            for(auto it: toAdd) awake.unionSet(it, 0);
            wake += toAdd.size();
        }

        if(!possible)
            cout << "THIS BRAIN NEVER WAKES UP" << endl;
        else
            cout << "WAKE UP IN, " << year << ", YEARS" << endl;
    }
    return 0;
}