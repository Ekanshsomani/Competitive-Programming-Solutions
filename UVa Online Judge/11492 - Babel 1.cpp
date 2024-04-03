#include <bits/stdc++.h>

#define ii pair<int, int>

using namespace std;

int main()
{
    int n;
    while(cin >> n and n)
    {
        vector<ii> adj[n+2];

        string startLang, targetLang;
        cin >> startLang >> targetLang;

        unordered_map<string, vector<string>> dict;

        unordered_map<string, int> wordIdx, lgcolor;
        vector<string> names(n+2);
        int idx{0}, color{0};

        for(int i=0; i<n; i++)
        {
            string l1, l2, p;
            cin >> l1 >> l2 >> p;
            dict[l1].push_back(p);
            dict[l2].push_back(p);

            if(not lgcolor.count(l1))
            {
                lgcolor[l1] = color;
                color++;
            }
            if(not lgcolor.count(l2))
            {
                lgcolor[l2] = color;
                color++;
            }
            if(not wordIdx.count(p))
            {
                wordIdx[p] = idx;
                names[idx] = p;
                idx++;
            }
        }
        names[n] = "";
        names[n+1] = "";

        for(auto it: dict[startLang])
            adj[n].push_back({wordIdx[it], color});

        for(auto it: dict[targetLang])
            adj[wordIdx[it]].push_back({n+1, color+1});

        for(auto it: dict)
        {
            vector<string> &temp = it.second;
            int currcol = lgcolor[it.first];
            int l = temp.size();
            for(int i=0; i<l; i++)
                for(int j=i+1; j<l; j++)
                    if(temp[i][0]!=temp[j][0])
                    {
                        int node1 = wordIdx[temp[i]];
                        int node2 = wordIdx[temp[j]];

                        adj[node1].push_back({node2, currcol});
                        adj[node2].push_back({node1, currcol});
                    }
        }

        vector<vector<bool>> vis(n+2, vector<bool>(color+3, false));
        priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;
        pq.push({0, {n, color+2}});
        while(not pq.empty())
        {
            int node = pq.top().second.first;
            int cost = pq.top().first;
            int prevCol = pq.top().second.second;
            pq.pop();

            if(vis[node][prevCol]) continue;
            vis[node][prevCol] = true;

            if(node==n+1)
            {
                printf("%d\n", cost);
                break;
            }

            for(auto it: adj[node])
                if(it.second!=prevCol)
                    pq.push({names[it.first].size()+cost, it});
        }

        if(not vis[n+1][color+1])
            printf("impossivel\n");
    }
    return 0;
}