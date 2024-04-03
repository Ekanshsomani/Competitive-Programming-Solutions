#include <bits/stdc++.h>

#define UNVISITED -1

using namespace std;

vector<int> *adj;
vector<int> dfsNum, dfsLow;
vector<bool> onStack;
stack<int> st;
int n, id;
unordered_map<string, int> nameIdx;
string names[25];

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
        while(st.top()!=node)
        {
            cout << names[st.top()] << ", ";
            onStack[st.top()] = false;
            st.pop();
        }
        cout << names[node] << "\n";
        onStack[node] = false;
        st.pop();
    }
}

int main()
{
    int m, test{0};
    while(cin >> n >> m and (n or m))
    {
        if(test++)
            cout << "\n";
        cout << "Calling circles for data set " << test << ":\n";
        if(m==0)
            continue;
        adj = new vector<int>[n];
        
        int i{0};
        while(m--)
        {
            string a, b;
            cin >> a >> b;
            if(not nameIdx.count(a))
            {
                names[i] = a;
                nameIdx[a] = i;
                i++;
            }
            if(not nameIdx.count(b))
            {
                names[i] = b;
                nameIdx[b] = i;
                i++;
            }

            int c{nameIdx[a]}, d{nameIdx[b]};
            if(find(adj[c].begin(), adj[c].end(), d)==adj[c].end())
                adj[c].push_back(d);
        }

        dfsNum.assign(n, UNVISITED);
        dfsLow.assign(n, UNVISITED);
        onStack.assign(n, false);
        id = 0;


        for(int i=0; i<n; i++)
            if(dfsNum[i]==UNVISITED)
            {
                getCycle(i);

                while(not st.empty())
                {
                    cout << names[st.top()] << (st.size()==1 ? "\n" : ", ");
                    st.pop();
                }
            }
        nameIdx.clear();
    }
    return 0;
}