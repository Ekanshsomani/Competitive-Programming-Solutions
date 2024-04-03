#include <bits/stdc++.h>
using namespace std;

inline bool isDoublet(const string &a, const string &b)
{
    if(a.length()!=b.length())
        return false;

    int diff{0};
    int l = a.length();
    for(int i=0; i<l; i++)
        if(diff>1)
            break;
        else if(a[i]!=b[i])
            diff++;
    
    return (diff == 1);
}

int main()
{
    unordered_map<string, int> nameIdx;
    string names[25000];
    
    int l{0};
    string line;
    while(getline(cin, line) and line.length()>0)
    {
        names[l] = line;
        nameIdx[line] = l;
        l++;
    }

    vector<int> adj[l];
    for(int i=0; i<l; i++)
        for(int j=i+1; j<l; j++)
            if(isDoublet(names[i], names[j]))
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }

    int test{0}, parent[l];
    string a, b;
    while(cin >> a >> b)
    {
        memset(parent, -1, sizeof parent);

        int source{nameIdx[a]}, target{nameIdx[b]};
        queue<int> q;
        q.push(source);
        parent[source] = source;

        while(not q.empty())
        {
            int node = q.front();
            q.pop();

            if(node==target)
                break;
            
            for(auto it: adj[node])
                if(parent[it]==-1)
                {
                    parent[it] = node;
                    q.push(it);
                }
        }

        if(test++)
            cout << endl;
        if(parent[target]==-1)
            printf("No solution.\n");
        else
        {
            stack<int> st;
            int node = target;
            while(node != source)
            {
                st.push(node);
                node = parent[node];
            }

            cout << names[source] << endl;
            while(not st.empty())
            {
                cout << names[st.top()] << endl;
                st.pop();
            }
        }
    }
    return 0;
}