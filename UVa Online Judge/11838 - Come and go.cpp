#include <bits/stdc++.h>

#define UNVISITED -1

using namespace std;

vector<int> *adj;
vector<int> dfsNum, dfsLow;
vector<bool> onStack;
stack<int> st;
int n, id, cycles;

inline void getCycle(int node)
{
    st.push(node);
    onStack[node] = true;
    dfsNum[node] = dfsLow[node] = id++;
    

    for(auto it: adj[node])
    {
        if(dfsNum[it]==UNVISITED) getCycle(it);
        if(onStack[it])
            dfsLow[node] = min(dfsLow[node], dfsLow[it]);
    }

    if(dfsNum[node]==dfsLow[node])
    {
        cycles++;
        while(st.top()!=node)
        {
            onStack[st.top()] = false;
            st.pop();
        }
        onStack[node] = false;
        st.pop();
    }
}

int main()
{
    int m;
    while(cin >> n >> m and (n or m))
    {
        adj = new vector<int>[n];
        int v, w, p;
        while(m--)
        {
            cin >>  v >> w >> p;
            adj[v-1].push_back(w-1);
            if(p==2)
                adj[w-1].push_back(v-1);
        }

        cycles = 0;
        dfsNum.assign(n, UNVISITED);
        dfsLow.assign(n, UNVISITED);
        onStack.assign(n,  false);
        for(int i=0; i<n; i++)
            if(dfsNum[i]==UNVISITED)
                getCycle(i);

        printf("%d\n", (cycles>1 ? 0 : 1));
    }
    return 0;
}