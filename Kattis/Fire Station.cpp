#include <bits/stdc++.h>

using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e7;

// firestations - 100
// intersections - 500
// minimize max firestation distance
// calculation of max firestation distance - O(V + (V+E)logV) ~ V^2logV
// V^3logV

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int f, V;
        cin >> f >> V;
        V++;

        vi fire(f);
        for(int i=0; i<f; i++)
            cin >> fire[i];

        vii adj[V];

        cin.ignore();
        string line;
        while(getline(cin, line) and line.size()>0)
        {
            istringstream iss(line);
            int u, v, w;
            iss >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        vb isStation(V, false);
        for(auto it: fire)
            isStation[it] = true;

        int minDist = INF;
        int newStation{0};
        for(int s=0; s<V; s++)
        {
            if(isStation[s]) continue;

            vi dist(V, minDist); dist[s] = 0; // INF = 1e9 here

            for(auto it: fire)
                dist[it] = 0;

            set<ii> pq; // balanced BST version
            for (int u = 0; u < V; ++u) // dist[u] = INF
                pq.emplace(dist[u], u); // but dist[s] = 0

            // sort the pairs by non-decreasing distance from s
            while (!pq.empty())  // main loop
            {
                auto [d, u] = *pq.begin(); // shortest unvisited u
                pq.erase(pq.begin());
                
                for (auto &[v, w] : adj[u]) 
                { // all edges from u
                    if (dist[u]+w >= dist[v]) continue; // not improving, skip
                    pq.erase(pq.find({dist[v], v})); // erase old pair
                    dist[v] = dist[u]+w; // relax operation
                    pq.emplace(dist[v], v); // enqueue better pair
                }
            }

            int newDist = *max_element(next(dist.begin()), dist.end());
            if(newDist < minDist)
            {
                newStation = s;
                minDist = newDist;
            }
        }

        cout << (newStation ? newStation : 1) << "\n";
        if(testcases)
            printf("\n");
    }
    return 0;
}