#include <bits/stdc++.h>
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
    string line;

    int testcases;
    cin >> testcases;
    cin.ignore();
    while(testcases--)
    {
        char maxNode;
        cin >> maxNode;
        int n(maxNode-64);
        cin.ignore();

        UnionFind graph(n);

        while(getline(cin, line) and line.size()>0)
        {
            istringstream iss(line);
            char node1, node2;
            iss >> node1 >> node2;
            graph.unionSet(node1-'A', node2-'A');
        }

        unordered_set<int> diffSets;
        for(int i=0; i<n; i++)
            diffSets.insert(graph.findSet(i));
        
        printf("%d\n", diffSets.size());
        if(testcases) printf("\n");
    }
    return 0;
}