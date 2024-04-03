#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<double, ii> dii;

double walkSpeed{10000.0/60.0};
double trainSpeed{40000.0/60.0};

inline double dist(const ii& a, const ii& b)
{
    return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        ii start, end;
        cin >> start.first >> start.second;
        cin >>  end.first >> end.second;
        cin.ignore();

        map<ii, vector<dii>> adj;
        vector<ii> vertices;

        double time{dist(start, end)/walkSpeed};
        adj[start] = {{time ,end}};
        adj[end] = {{time, start}};
        vertices.push_back(start);
        vertices.push_back(end);

        string line;
        while(getline(cin, line) and line.size()>0)
        {
            istringstream iss(line);
            ii prev, curr;
            iss >> prev.first >> prev.second;

            if(not adj.count(prev))
            {
                adj[prev] = vector<dii>();
                vertices.push_back(prev);
            }

            while(iss >> curr.first >> curr.second and (curr.first>-1 or curr.second>-1))
            {
                if(not adj.count(curr))
                {
                    adj[curr] = vector<dii>();
                    vertices.push_back(curr);
                }

                double time {dist(curr, prev)/trainSpeed};
                adj[curr].push_back({time, prev});
                adj[prev].push_back({time, curr});

                prev = curr;
            }
        }

        int n = vertices.size();
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
            {
                if(i==0 and j==1)
                    continue;
                ii& a = vertices[i];
                ii& b = vertices[j];
                double time{dist(a, b)/walkSpeed};
                adj[a].push_back({time, b});
                adj[b].push_back({time, a});
            }

        map<ii, bool> vis;
        for(int i=0; i<n; i++)
            vis[vertices[i]] = false;

        priority_queue<dii, vector<dii>, greater<dii>> pq;
        pq.push({0, start});
        
        while(not pq.empty())
        {
            ii node = pq.top().second;
            double time = pq.top().first;
            pq.pop();

            if(vis[node]) continue;
            vis[node] = true;

            if(node==end)
            {
                printf("%.0f\n", time);
                break;
            }

            for(auto it: adj[node])
                pq.push({it.first+time, it.second});
        }

        if(testcases)
            printf("\n");
    }
    return 0;
}