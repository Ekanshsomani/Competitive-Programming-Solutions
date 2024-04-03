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
    while(testcases--)
    {
        int satelites, outposts;
        cin >> satelites >> outposts;

        vector<ii> coordinates(outposts);
        for(int i=0; i<outposts; i++)
            cin >> coordinates[i].first >> coordinates[i].second;

        vector<pair<double, ii>> distance;
        for(int i=0; i<outposts-1; i++)
            for(int j=i+1; j<outposts; j++)
                distance.push_back({getDistance(coordinates[i], coordinates[j]), {i, j}});
        sort(distance.begin(), distance.end());

        UnionFind graph(outposts);
        int components{outposts};
        double maxDist{0};
        for(auto it: distance)
            if(not graph.isSameSet(it.second.first, it.second.second))
            {
                graph.unionSet(it.second.first, it.second.second);
                components--;
                if(components<=satelites)
                {
                    maxDist = it.first;
                    break;
                }
            }

        printf("%.2f\n", maxDist);
    }
    return 0;
}