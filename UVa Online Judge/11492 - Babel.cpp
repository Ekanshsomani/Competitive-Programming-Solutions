#include <bits/stdc++.h>

#define character second.second

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main()
{
    int n;
    while(cin >> n and n)
    {
        string startLang, targetLang;
        cin >> startLang >> targetLang;

        unordered_map<string, int> index;
        vector<vector<iii>> adj;
        int gIdx{0};

        for(int i=0; i<n; i++)
        {
            string u, v, w;
            cin >> u >> v >> w;

            if(not index.count(u))
            {
                index[u] = gIdx++;
                adj.push_back(vector<iii>());
            }
            if(not index.count(v))
            {
                index[v] = gIdx++;
                adj.push_back(vector<iii>());
            }

            adj[index[u]].push_back({(int) w.length(), {index[v], w[0]-'a'}});
            adj[index[v]].push_back({(int) w.length(), {index[u], w[0]-'a'}});
        }

        if(not (index.count(startLang) and index.count(targetLang)))
            printf("impossivel\n");
        else
        {
            vector<vector<int>> distance(27, vector<int>(index.size(), 1e6));
            priority_queue<iii, vector<iii>, greater<iii>> pq;

            int start{index[startLang]}, target{index[targetLang]};
            int minPath = 1e6;

            distance[26][start] = 0;
            pq.push({0, {start, 26}});

            while(not pq.empty())
            {
                iii current = pq.top();
                pq.pop();

                int node = current.second.first;
                int dist = current.first;
                int firstChar = current.character;

                if(dist>distance[firstChar][node]) continue;
                distance[firstChar][node] = dist;

                if(node==target)
                    minPath = min(dist, minPath);

                for(auto it: adj[node])
                    if(it.character!=firstChar)
                        pq.push({dist+it.first, it.second});
            }

            if(minPath==1e6)
                printf("impossivel\n");
            else
                printf("%d\n", minPath);
        }
    }
    return 0;
}