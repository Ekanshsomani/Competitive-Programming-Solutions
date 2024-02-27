// 11991

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        unordered_map<int, vector<int>> adj;
        for(int i=1; i<=n; i++)
        {
            int val;
            cin >> val;
            if(adj.count(val)==0) adj[val] = {};
            adj[val].push_back(i);
        }

        while(m--){
            int k, v;
            cin >> k >> v;
            if(adj.count(v)==0 || adj[v].size()<k) cout << 0 << endl;
            else cout << adj[v][k-1] << endl;
        }
    }
}