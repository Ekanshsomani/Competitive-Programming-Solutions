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
    int junctions, roads;
    while(cin >> junctions >> roads and (junctions or roads))
    {
        vector<pair<int, ii>> distances(roads);
        int savedMoney{0};
        for(int i=0; i<roads; i++)
        {
            cin >> distances[i].second.first >> distances[i].second.second >> distances[i].first;
            savedMoney += distances[i].first;
        }
        sort(distances.begin(), distances.end());

        UnionFind graph(junctions);
        for(auto it: distances)
            if(not graph.isSameSet(it.second.first, it.second.second))
            {
                graph.unionSet(it.second.first, it.second.second);
                savedMoney -= it.first;
            }
        
        printf("%d\n", savedMoney);
    }

    return 0;
}