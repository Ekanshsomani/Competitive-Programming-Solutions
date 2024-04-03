#include <bits/stdc++.h>
using namespace std;

set<string> ans;
vector<int> graph[20];
char nodes[20];
int n;

void backtrack(string s, int vis)
{
    if(s.size()==n)
    {
        ans.insert(s);
        return;
    }

    for(int i=0; i<n; i++)
        if(not (vis&(1<<i)))
        {
            bool addable{true};
            for(auto it: graph[i])
                if(not (vis&(1<<it)))
                    {addable = false; break;}
            if(addable)
                backtrack(s+nodes[i], vis|(1<<i));
        }
}

int main()
{
    string line;

    int testcases;
    cin >> testcases;
    cin.ignore();
    cin.ignore();
    while(testcases--)
    {
        getline(cin, line);
        n = (line.size()+1)>>1;
        for(int i=0; i<n; i++)
            nodes[i] = line[i<<1];
        
        getline(cin, line);
        for(int i=0; i<line.size(); i+=4)
        {
            int i1 = (find(nodes, nodes+n, line[i]) - nodes);
            int i2 = find(nodes, nodes+n, line[i+2]) - nodes;
            graph[i2].push_back(i1);
        }
        cin.ignore();

        backtrack("", 0);
        for(auto it: ans)
        {
            for(int i=0; i<n; i++)
                cout << it[i] << (i==n-1 ? "\n" : " ");
        }
        if(ans.size()==0)
            printf("NO\n");
        
        if(testcases)
        {
            printf("\n");
            ans.clear();
            for(int i=0; i<n; i++)
                graph[i].clear();
        }
    }
    return 0;
}