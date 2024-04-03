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
    int n, m;
    while(cin >> n >> m and (n or m))
    {
        vector<pair<int, ii>> weights(m);
        for(int i=0; i<m; i++)
            cin >> weights[i].second.first >> weights[i].second.second >> weights[i].first;
        sort(weights.begin(), weights.end());

        vector<int> heavyWeights;
        UnionFind graph(n);
        for(auto it: weights)
            if(not graph.isSameSet(it.second.first, it.second.second))
                graph.unionSet(it.second.first, it.second.second);
            else
                heavyWeights.push_back(it.first);
        
        int l = heavyWeights.size();
        if(l==0)
            printf("forest\n");
        else
            for(int i=0; i<l; i++)
                cout << heavyWeights[i] << (i==l-1 ? "\n" : " ");
    }

    return 0;
}