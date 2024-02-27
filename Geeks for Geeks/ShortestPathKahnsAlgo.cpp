#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> shortestPath(int N, int M, vector<vector<int>>& edges){
    int inDeg[N]={0};
    int dist[N] = {2147483647};
    vector<pair<int, int>> adj[N];
    queue<int> q;

    for(int i=0; i<M; i++){
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        inDeg[edges[i][1]]++;
    }

    for(int i=0; i<N; i++){
        if(inDeg[i]==0){
            dist[i]=0;
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:adj[node]){
            inDeg[it.first]--;
            int tdist = dist[node]+it.second;
            if(tdist<dist[it.first]){dist[it.first]=tdist;}
            if(!inDeg[it.first]){q.push(it.first);}
        }
    }

    vector<int> ndist;
    for(int i=0; i<N; i++){
        ndist.push_back(dist[i]);
    }
    return ndist;
}