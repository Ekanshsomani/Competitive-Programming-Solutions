#include <bits/stdc++.h>

#define ii pair<int, int>

using namespace std;

inline bool isDoublet(const string &a, const string &b)
{
    if(a.length()!=b.length())
        return false;

    int diff{0};
    int l = a.size();
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
    string names[210];

    int testcases;
    cin >> testcases;
    cin.ignore();
    while(testcases--)
    {
        
        
        int l{0};
        string line;
        while(getline(cin, line) and line[0]!='*')
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
        
        bool vis[l];
        while(getline(cin, line) and line.size()>0)
        {
            cout << line << " ";
            istringstream iss(line);
            string a, b;
            iss >> a >> b;
            

            memset(vis, false, sizeof vis);
            queue<ii> q;

            int source{nameIdx[a]}, target{nameIdx[b]};
            q.push({0, source});
            vis[source] = true;
            
            while(not q.empty())
            {
                int node = q.front().second;
                int step = q.front().first;
                q.pop();

                if(node==target)
                {
                    cout << step << "\n";
                    break;
                }

                for(auto it: adj[node])
                    if(not vis[it])
                    {
                        vis[it] = true;
                        q.push({step+1, it});
                    }
            }
        }

        if(testcases)
        {
            cout << "\n";
            nameIdx.clear();
        }
    }
}