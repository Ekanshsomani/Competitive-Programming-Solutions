#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dfs(int V, vector<int> adj[]){
    int node, vis[V+1]={0};

    stack<int> s;
    s.push(1);
    vis[1] = 1;

    vector<int> final;
    while(!s.empty()){
        node = s.top();
        s.pop();
        final.push_back(node);
        
        for(auto it: adj[node]){
            if(!vis[it]){
                s.push(it);
                vis[it] = 1;
            }
        }
    }

    return final;
}