#include <iostream>
#include <vector>
using namespace std;

bool dfsCheck(vector<int> adj[], int vis[], int check[], vector<int>& vec, int node){
    vis[node] = 1;
    if(!adj[node].size()){
        vec.push_back(node);
        check[node] = 1;
    }
    else{
        for(auto it: adj[node]){
            if(!vis[it]){
                dfsCheck(adj, vis, check, vec, it);
            }
        }
        int a = 1;
        for(auto it: adj[node]){
            if(!check[it]){
                a = 0;
            }
        }
        if(a){
            check[node] = 1;
            vec.push_back(node);
        }
    }
}

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    int vis[V]={0};
    int check[V] = {0};
    vector<int> vec;


    for(int i=0; i<V; i++){
        if(!vis[i]){dfsCheck(adj, vis, check, vec, i);}
    }

    return vec;
}