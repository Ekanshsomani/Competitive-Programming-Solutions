#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(int V, vector<int> adj[], int src){
    int node, vis[V]={0}, dis[V]={0};

    queue<int> q;
    q.push(src);
    vis[src] = 1;
    
    while(!q.empty()){
        node = q.front();
        q.pop();
        
        for(auto it: adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it] = 1;
                dis[it] = dis[node]+1;
            }
        }
    }

    vector<int> dist;
    for(int i=0; i<V; i++){
        if(vis[i]){dist.push_back(dis[i]);}
        else{dist.push_back(-1);}
    }
    return dist;
}

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    vector<int> adj[N];

    for(int i=0; i<M; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    return bfs(N, adj, src);
}