#include <bits/stdc++.h>

#define ii pair<int, int>

using namespace std;

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
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int n, m;
        cin >> n >> m;

        vector<pair<int, ii>> edgeList(m);
        for(int i=0; i<m; i++)
            cin >> edgeList[i].second.first >> edgeList[i].second.second >> edgeList[i].first;
        
        sort(edgeList.begin(), edgeList.end(), greater<pair<int, ii>>());

        int totalCost{0};
        UnionFind graph(n+1);
        for(auto it: edgeList)
            if(not graph.isSameSet(it.second.first, it.second.second))
                graph.unionSet(it.second.first, it.second.second);
            else
                totalCost += it.first;

        printf("%d\n", totalCost);
    }
    return 0;
}