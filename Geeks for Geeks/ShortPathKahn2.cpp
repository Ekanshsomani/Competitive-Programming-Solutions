#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]){
    int inDeg[V]={0};
    for(int i=0; i<V; i++){
        for(auto re:adj[i]){inDeg[re]++;}
    }

    queue<int> q;
    for(int i=0; i<V; i++){
        if(!inDeg[i]){q.push(i);}
    }

    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto it: adj[node]){
            inDeg[it]--;
            if(!inDeg[it]){q.push(it);}
        }
    }

    return ans;
}

vector<int> shortestPath(int N, int M, vector<vector<int>>& edges){
    vector<pair<int, int>> adj[N];

    for(int i=0; i<M; i++){
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }

