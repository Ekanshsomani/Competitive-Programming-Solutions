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

double getDistance(ii a, ii b)
{
    // return (
    //     abs(a.first-b.first) +
    //     abs(a.second - b.second)
    // );
    return sqrt(
        (a.first-b.first)*(a.first-b.first) + 
        (a.second-b.second)*(a.second-b.second)
    );
}

int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int n, m;
        cin >> n;
        vector<ii> coordinates(n+1);
        for(int i=1; i<=n; i++)
            cin >> coordinates[i].first >> coordinates[i].second;
        
        UnionFind graph(n+1);
        cin >> m;
        while(m--)
        {
            int a, b;
            cin >> a >> b;
            graph.unionSet(a, b);
        }

        vector<pair<double, ii>> distance;
        for(int i=1; i<n; i++)
            for(int j=i+1; j<=n; j++)
                distance.push_back({getDistance(coordinates[i], coordinates[j]), {i, j}});
        sort(distance.begin(), distance.end());

        vector<ii> toBuild;
        for(auto it: distance)
            if(not graph.isSameSet(it.second.first, it.second.second))
            {
                toBuild.push_back(it.second);
                graph.unionSet(it.second.first, it.second.second);
            }
        // sort(toBuild.begin(), toBuild.end());

        if(toBuild.size()==0)
            printf("No new highways need\n");
        
        for(auto it: toBuild)
            printf("%d %d\n", it.first, it.second);
        
        if(testcases)
            printf("\n");
    }
    
    return 0;
}