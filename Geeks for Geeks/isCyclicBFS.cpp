#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isCyclic(int V, vector<int> adj[]){
    int inDeg[V]={0};
    for(int i=0; i<V; i++){
        for(auto re:adj[i]){inDeg[re]++;}
    }

    queue<int> q;
    for(int i=0; i<V; i++){
        if(!inDeg[i]){q.push(i);}
    }

    int cnt;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;

        for(auto it: adj[node]){
            inDeg[it]--;
            if(!inDeg[it]){q.push(it);}
        }
    }

    if(V==cnt){return 0;}
    else{return 1;}
}