#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class UnionFind
{
    private: 
        vi p, rank;
    
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

        void clear(int N)
        {
            rank.clear(); p.clear();
            rank.assign(N, 0);
            p.assign(N, 0);
            for (int i = 0; i < N; i++) 
                p[i] = i;
        }
};

int main()
{
    const int V{26};
    UnionFind aair(V), bair(V);

    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int E;
        cin >> E;
        while(E--)
        {
            char u, v;
            cin >> u >> v;
            aair.unionSet(u-'A', v-'A');
        }
        cin >> E;
        while(E--)
        {
            char u, v;
            cin >> u >> v;
            bair.unionSet(u-'A', v-'A');
        }

        bool similar{true};
        for(int u=0; u<V and similar; u++)
            for(int v=u+1; v<V; v++)
                if(aair.isSameSet(u, v)!=bair.isSameSet(u, v))
                {
                    printf("NO\n");
                    similar = false;
                    break;
                }

        if(similar) printf("YES\n");
        
        if(testcases)
            aair.clear(V), bair.clear(V), printf("\n");
    }
    return 0;
}