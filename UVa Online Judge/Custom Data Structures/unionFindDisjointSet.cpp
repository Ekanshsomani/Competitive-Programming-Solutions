#include <vector>
using namespace std;

// UnionFind
// Constructor(int N)
// findSet
// isSameSet
// UnionSet

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

class UnionBySize
{
    private: 
        vector<int> p, size;
    
    public:    
        UnionBySize(int N)
        {
            size.assign(N, 1);
            p.assign(N, 0);
            for (int i = 0; i < N; i++) 
                p[i] = i; 
        }

        int getSize(int i)
        {
            return size[i];
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
                if (size[x] > size[y])
                {
                    p[y] = x;
                    size[x] += size[y];
                }
                else 
                {
                    p[x] = y;
                    size[y] += size[x];
                }
            }
        }
};