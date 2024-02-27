#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(int V, vector<int> adj[], int src){
    int node, vis[V]={0}, dis[V]={0};

    queue<int> q;
    q.push(src);
    vis[src] = 1;
    
    while(!q.empty()){
        node = q.front();
        q.pop();
        
        for(auto it: adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it] = 1;
                dis[it] = dis[node]+1;
            }
        }
    }

    vector<int> dist;
    for(int i=0; i<V; i++){
        if(vis[i]){dist.push_back(dis[i]);}
        else{dist.push_back(-1);}
    }
    return dist;
}

int WordLadderLength(string beginWord, string endWord, vector<string>& wordList) {
    int M = beginWord.size();
    int N = wordList.size();
    int dcnt;
    vector<int> adj[N+1];

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            dcnt = 0;
            for(int k=0; k<M; k++){
                if(wordList[i][k]!=wordList[j][k]){dcnt++;}
            }
            if(dcnt==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int dcnt1, dcnt2;
    int endex = N+1;
    for(int i=0; i<N; i++){
        dcnt1 = 0;
        dcnt2 = 0;
        for(int j=0; j<M; j++){
            if(wordList[i][j]!=endWord[j]){dcnt1++;}

            if(wordList[i][j]!=beginWord[j]){dcnt2++;}
        }
        if(dcnt1==0){endex = i;}
        if(dcnt2==1){adj[N].push_back(i);}
    }

    vector<int> dist = bfs(N+1, adj, N);

    if(dist[endex]==-1){return 0;}
    else{return dist[endex]+1;}
}