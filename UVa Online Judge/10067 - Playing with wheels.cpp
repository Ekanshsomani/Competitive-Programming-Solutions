#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

// left -> Clockwise
// right -> Anticlockwise

// O(n^2) -> 10^8 == 100 Million
// Better Way:
    // start from "0000" increase all four digits add them as edge backtrack

vi adj[10000];
bitset<10000> vis, forbidden;

inline void backtrack(string node)
{
    int u = stoi(node);
    
    if(vis[u]) return;
    vis[u] = true;

    for(int i=0; i<4; i++)
    {
        node[i] += (node[i]=='9' ? -9 : 1);
        int v = stoi(node);
        adj[u].push_back(v);
        adj[v].push_back(u);
        backtrack(node);
        node[i] -= (node[i]=='0' ? -9 : 1);
    }
}

int main()
{
    backtrack("0000");

    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        vis.reset();
        forbidden.reset();

        int a1, b1, c1, d1;

        cin >> a1 >> b1 >> c1 >> d1;
        int start = a1*1000 + b1*100 + c1*10 + d1;


        cin >> a1 >> b1 >> c1 >> d1;
        int target = a1*1000 + b1*100 + c1*10 + d1;

        int n;
        cin >> n;
        while(n--)
        {
            cin >> a1 >> b1 >> c1 >> d1;
            int num = a1*1000 + b1*100 + c1*10 + d1;
            forbidden[num] = true;
        }

        queue<ii> q;
        q.emplace(start, 0);
        vis[start] = true;
        while(not q.empty())
        {
            auto [u, presses] = q.front();
            q.pop();

            if(u==target)
            {
                printf("%d\n", presses);
                break;
            }

            for(auto v: adj[u])
                if(not (vis[v] or forbidden[v]))
                {
                    vis[v] = true;
                    q.emplace(v, presses+1);
                }
        }

        if(not vis[target])
            printf("-1\n");
    }
    return 0;
}