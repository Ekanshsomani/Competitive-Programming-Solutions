#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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