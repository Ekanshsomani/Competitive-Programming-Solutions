#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    int exDeg[V]={0};
    int safe[V] = {0};
    vector<int> rev[V];
    queue<int> q;


    for(int i=0; i<V; i++){
        exDeg[i] = adj[i].size();
        if(!exDeg[i]){q.push(i);}
        for(auto it:adj[i]){
            rev[it].push_back(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        safe[node] = 1;
        for(auto it: rev[node]){
            exDeg[it]--;
            if(!exDeg[it]){q.push(it);}
        }
    }

    vector<int> ans;

    for(int i=0; i<V; i++){
        if(!safe[i]){ans.push_back(i);}
    }

    return ans;
}