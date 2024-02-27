#include <iostream>
#include <vector>
#include <queue>
#include <string>
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

string findOrder(string dict[], int N, int K) {
    vector<int> adj[K];
    for(int i=0; i<N-1; i++){
        string s1 = dict[i];
        string s2 = dict[i+1];
        int len = min(s1.size(), s2.size());
        for(int ptr=0; ptr<len; ptr++){
            if(s1[ptr]!=s2[ptr]){
                adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
            }
        }
    }

    vector<int> topo = topoSort(K, adj);
    string ans = "";
    for(auto it: topo){
        ans = ans + char(it+'a');
    }
    return ans;
}