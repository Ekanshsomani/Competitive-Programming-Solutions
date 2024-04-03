#include <bits/stdc++.h>

#define ii pair<int, int>
#define MAX 10000

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

struct pair_hash
{
    size_t operator() (const ii &p) const 
    {
        return (p.first<<8)+(p.second);
    }
};

unordered_map<int, int> *mst;
vector<bool> vis;
int ans;

inline bool dfs(int current, int target)
{
    if(current==target) return true;
    if(vis[current]) return false;
    vis[current] = true;
    
    for(auto it: mst[current])
        if(dfs(it.first, target))
        {
            ans = max(ans, it.second);
            return true;
        }
    return false;
}

int main()
{
    int test{0};
    int crossings, streets, queries;
    while(cin >> crossings >> streets >> queries and (crossings or streets or queries))
    {
        vector<pair<int, ii>> intensities(streets);
        for(int i=0; i<streets; i++)
        {
            cin >> intensities[i].second.first >> intensities[i].second.second >> intensities[i].first;
            intensities[i].second.first--;
            intensities[i].second.second--;
        }
        sort(intensities.begin(), intensities.end());

        UnionFind graph(crossings);
        mst = new unordered_map<int, int>[crossings];

        for(auto it: intensities)
            if(not graph.isSameSet(it.second.first, it.second.second))
            {
                graph.unionSet(it.second.first, it.second.second);
                mst[it.second.first][it.second.second] = it.first;
                mst[it.second.second][it.second.first] = it.first;
            }

        if(test++) printf("\n");
        printf("Case #%d\n", test);
        // memset(memo, -1, sizeof memo);
        while(queries--)
        {
            ii a;
            cin >> a.first >> a.second;
            a.first--; a.second--;
            if(not graph.isSameSet(a.first, a.second))
                printf("no path\n");
            else
            {
                ans = 0;
                vis.assign(crossings, false);
                dfs(a.first, a.second);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}