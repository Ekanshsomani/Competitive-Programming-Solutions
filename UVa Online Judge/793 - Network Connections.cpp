// 793
// bob - bi-directional

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
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

int main()
{
    int testcases;
    cin >> testcases;

    while(testcases--)
    {
        int computers;
        cin >> computers;
        cin.ignore();

        string line;
        UnionFind network(computers);

        int success{0},  unsuccess{0};

        while(getline(cin, line) && line.length()>1)
        {
            char type;
            int i, j;
            istringstream in(line);
            in >> type >> i >> j;

            if(type == 'c') network.unionSet(i-1, j-1);
            else if(network.isSameSet(i-1, j-1)) success++;
            else unsuccess++;
        }

        cout << success << ',' << unsuccess << endl;
        if(testcases)
            cout << endl;
    }
    return 0;
}