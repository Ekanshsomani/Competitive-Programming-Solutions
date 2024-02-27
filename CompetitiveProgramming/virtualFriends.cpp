// 11503

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// UnionFind
// Constructor(int N)
// findSet
// isSameSet
// UnionSet

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

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int f;
        cin >> f;

        UnionBySize network(100002);
        unordered_map<string, int> index;
        int size{0};
        while(f--)
        {
            string a, b;
            cin >> a >> b;

            if(!index.count(a))
            {
                index[a] = size;
                size++;
            }
            if(!index.count(b))
            {
                index[b] = size;
                size++;
            }

            network.unionSet(index[a], index[b]);
            cout << network.getSize(network.findSet(index[a])) << endl;

        }
    }
    return 0;
}