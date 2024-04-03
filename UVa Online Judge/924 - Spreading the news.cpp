#include <bits/stdc++.h>

#define ii pair<int, int>

using namespace std;

int main()
{
    int employees;
    cin >> employees;
    
    vector<int> adj[employees];
    for(int i=0; i<employees; i++)
    {
        int friends;
        cin >> friends;
        while(friends--)
        {
            int num;
            cin >> num;
            adj[i].push_back(num);
        }
    }

    bool vis[employees];

    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        memset(vis, false, sizeof vis);
        queue<int> q;
        int days{0}, boomSize{0}, boomDay{0};

        int start;
        cin >> start;
        q.push(start);
        vis[start] = true;


        while(not q.empty())
        {
            int l = q.size();
            if(l>boomSize and days)
            {
                boomSize = l;
                boomDay = days;
            }

            while(l--)
            {
                int node = q.front();
                q.pop();

                for(auto it: adj[node])
                    if(not vis[it])
                    {
                        vis[it] = true;
                        q.push(it);
                    }
            }

            days++;
        }

        if(boomDay)
            printf("%d %d\n", boomSize, boomDay);
        else
            printf("0\n");
    }
}