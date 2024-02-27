#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool dfsCheck(vector<int> adj[], int V, vector<int>& vis, int pathvis[]){
    vis[V] = 1;
    pathvis[V] = 1;

    for(auto it: adj[V]){
        if(!vis[it]){
            if(dfsCheck(adj, it, vis, pathvis)){return true;}
        }
        else if(pathvis[it]){
            return true;
        }
    }
    vis[V] = 0; //Check this line. It seems redundant but code doesn't work without it.
    return false;
}

bool isCyclic(int V, vector<int> adj[]){
    vector<int> vis(V, 0);
    int pathvis[V];

    for(int i=0; i<V; i++){
        if(vis[i]==0){
            if(dfsCheck(adj, i, vis, pathvis)){
                return true;
            }
        }
    }

    return false;
}