#include <iostream>
#include <set>
using namespace std;

set<pair<int, int>> edges;
int n, k;
int maxSize;

int vec[100];
int largestSet[100];

void backtrack(int index, int node)
{
    if(node==n)
    {
        if(index>maxSize)
        {
            maxSize = index;
            for(int i=0; i<maxSize; i++)
                largestSet[i] = vec[i];
        }
        return;
    }

    for(int i=node; i<n; i++)
    {
        bool addable{true};
        
        for(int j=0; j<index and addable; j++)
            if(edges.count({i,vec[j]}) or edges.count({vec[j],i}))
                addable = false;
        
        if(not addable)
            continue;
        
        vec[index] = i;
        backtrack(index+1, i+1);
    }

    if(index>maxSize)
    {
        maxSize = index;
        for(int i=0; i<maxSize; i++)
            largestSet[i] = vec[i];
    }

    return;    
}

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        cin >> n >> k;
        maxSize = 0;
        edges.clear();

        for(int i=0; i<k; i++)
        {
            int a, b;
            cin >> a >> b;
            edges.insert({a-1, b-1});
        }

        backtrack(0, 0);

        cout << maxSize << endl;
        for(int i=0; i<maxSize; i++)
            cout << largestSet[i]+1 << ((i==(maxSize-1))?"\n":" ");
    }
    return 0;
}