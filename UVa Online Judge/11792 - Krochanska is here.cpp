#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;

const int INF = 100000;

// 10000 stations
// 100 lines -> 1 Million edges Max
// (V+E)*V (BFS - V times)
// 1 Million*TenThousand operations -> Can't do -> But with pruning... -> maybe possible

int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int V, E;
        cin >> V >> E;
        V++;

        vi adj[V];
        vi occured(V, 0);

        while(E--)
        {
            int prev, curr;
            cin >> prev;
            occured[prev]++;

            while(cin >> curr and curr)
            {
                adj[prev].push_back(curr);
                adj[curr].push_back(prev);
                occured[curr]++;
                prev = curr;
            }
        }

        int minTotal = INF;
        int bestNode;
        for(int i=1; i<V; i++)
        {
            // printf("%d-%d", i, occured[i]);
            if(occured[i]<2)
            {
                // printf(" ");
                continue;
            }

            vb vis(V, false);
            queue<ii> q;
            q.emplace(0, i);
            vis[i] = true;
            int total = 0;

            while(not q.empty())
            {
                auto [d, u] = q.front();
                q.pop();

                if(total > minTotal)
                    break;

                for(auto v: adj[u])
                    if(not vis[v])
                    {
                        if(occured[v]>1) total += (d+1);
                        vis[v] = true;
                        q.emplace(d+2, v);
                    }
            }

            // printf("-%d ", total);
            if(total<minTotal)
            {
                minTotal = total;
                bestNode = i;
            }
        }

        printf("Krochanska is in: %d\n", bestNode);
    }
    
    return 0;
}