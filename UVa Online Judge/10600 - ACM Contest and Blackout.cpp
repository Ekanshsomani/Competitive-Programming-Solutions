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
        
        bool isSameSet(ii a)
        {
            return findSet(a.first) == findSet(a.second);
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

        void unionSet(ii a)
        {
            unionSet(a.first, a.second);
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

        vector<pair<int, ii>> edges(m);
        for(int i=0; i<m; i++)
            cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
        sort(edges.begin(), edges.end());

        UnionFind graph(n+1);

        vector<int> cheapestPlan;
        int s1{0};
        for(int i=0; i<m; i++)
            if(not graph.isSameSet(edges[i].second))
            {
                graph.unionSet(edges[i].second);
                cheapestPlan.push_back(i);
                s1 += edges[i].first;
            }

        int l = cheapestPlan.size();
        int s2{INT_MAX};
        for(int i=0; i<l; i++)
        {
            int currCost{0};
            UnionFind currGraph(n+1);
            for(int j=0; j<m; j++)
                if(not currGraph.isSameSet(edges[j].second) and j!= cheapestPlan[i])
                {
                    currGraph.unionSet(edges[j].second);
                    currCost += edges[j].first;
                }
            
            bool allConnected{true};
            for(int k=1; k<n; k++)
                if(not currGraph.isSameSet(k, k+1))
                {
                    allConnected = false;
                    break;
                }
            if(allConnected)
                s2 = min(s2, currCost);
        }

        printf("%d %d\n", s1, s2);
    }
    return 0;
}