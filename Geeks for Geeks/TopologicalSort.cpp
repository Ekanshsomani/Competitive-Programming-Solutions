#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int i, stack<int>& st, vector<int> adj[], int vis[]){
    vis[i] = 1;
    for(auto it: adj[i]){
        if(!vis[it]){
            dfs(it, st, adj, vis);
        }
    }
    st.push(i);
}

vector<int> topoSort(int V, vector<int> adj[]){
    stack<int> st;
    int vis[V]={0};
    vector<int> ans;

    for(int i=0; i<V; i++){
        if(!vis[i]){
            dfs(i, st, adj, vis);
        }
    }

    for(int i=0; i<V; i++){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}