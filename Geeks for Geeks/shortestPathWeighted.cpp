#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> createPath(vector<int>& dis, int a, int b, 
vector<vector<int>> adj[]){
    vector<int> ans;

    for(auto it:adj[b]){
        int node = it[0];
        int dist = it[1];

        if(dis[node] == dis[b]-dist){
            if(node!=a) {ans = createPath(dis, a, node, adj);}
            else{ans = {a};}
            ans.push_back(b);
            return ans;
        }
    }

    return {-1};
}

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
    vector<int> dis(V);
    for(int i=0; i<V; i++)dis[i]=1e9;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});
    dis[S] = 0;

    int node, dist;
    while(!pq.empty()){
        dist = pq.top().first;
        node = pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            if(it[1]+dist<dis[it[0]]){
                dis[it[0]] = it[1]+dist;
                pq.push({dis[it[0]], it[0]});
            }
        }
    }

    return dis;
}

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<vector<int>> adj[n+1];
    
    int a, b, dist;
    for(int i=0; i<m; i++){
        a = edges[i][0];
        b = edges[i][1];
        dist = edges[i][2];
        adj[a].push_back({b, dist});
        adj[b].push_back({a, dist});
    }

    vector<int> dis = dijkstra(n+1, adj, 0);

    if(dis[n]==1e9)return {-1};

    return createPath(dis, 0, n, adj);
}