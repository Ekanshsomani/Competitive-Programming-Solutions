#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(int V, vector<int> adj[]){
    int node, vis[V+1]={0};
    
    queue<int> q;
    q.push(1);
    vis[1] = 1;

    vector<int> final;
    while(!q.empty()){
        node = q.front();
        q.pop();
        final.push_back(node);
        
        for(auto it: adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it] = 1;
            }
        }
    }

    return final;
}