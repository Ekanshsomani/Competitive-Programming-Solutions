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
    return sqrt(
        (a.first-b.first)*(a.first-b.first) + 
        (a.second-b.second)*(a.second-b.second)
    );
}

int main()
{
    int testcases;
    cin >> testcases;
    for(int t=1; t<=testcases; t++)
    {
        int cities, threshold;
        cin >> cities >> threshold;

        vector<ii> coordinates(cities);
        for(int i=0; i<cities; i++)
            cin >> coordinates[i].first >> coordinates[i].second;

        vector<pair<double, ii>> distance;
        for(int i=0; i<cities-1; i++)
            for(int j=i+1; j<cities; j++)
                distance.push_back({getDistance(coordinates[i], coordinates[j]), {i, j}});
        sort(distance.begin(), distance.end());

        double road{0}, track{0};
        int states{cities};
        UnionFind graph(cities);
        for(auto it: distance)
            if(not graph.isSameSet(it.second.first, it.second.second))
            {
                graph.unionSet(it.second.first, it.second.second);
                if(it.first > (1.00*threshold))
                    track += it.first;
                else
                {
                    road += it.first;
                    states--;
                }
            }

        printf("Case #%d: %d %.0f %.0f\n", t, states, road, track);
    }
    return 0;
}