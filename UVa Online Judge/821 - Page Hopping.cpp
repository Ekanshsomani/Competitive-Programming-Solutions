#include <bits/stdc++.h>

using namespace std;

const int INF = 10000;

int AM[101][101];
unordered_set<int> nodes;

int main()
{
    int test{1};
    int u, v;
    while(cin >> u >> v and (u or v))
    {
        memset(AM, INF, sizeof AM);
        nodes.clear();
        nodes.insert(u);
        nodes.insert(v);

        AM[u][v] = 1;
        while(cin >> u >> v and (u or v))
        {
            AM[u][v] = 1;
            nodes.insert(u);
            nodes.insert(v);
        }

        for(int k=0; k<101; k++)
            for(int i=0; i<101; i++)
                for(int j=0; j<101; j++)
                    AM[i][j] = min(AM[i][j], AM[i][k]+AM[k][j]);

        int total{0};
        for(auto it1: nodes)
            for(auto it2: nodes)
                if(it1!=it2)
                    total += AM[it1][it2];
        int V = nodes.size();
        printf("Case %d: average length between pages = %.3f clicks\n", test++, total/(1.00*V*(V-1)));
    }
    return 0;
}