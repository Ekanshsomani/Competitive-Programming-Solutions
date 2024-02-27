// 599
// have edges in an unordered map;
// create a bitset to record visitations
    // index of bitset is same as chars position in vector
// perform bfs

#include <iostream>
#include <unordered_map>
#include <vector>
#include <bitset>
#include <string>
using namespace std;

void dfs(unordered_map<char, vector<char>> adj, char c, bitset<26> *vis, int* nodes)
{
    (*vis)[c-'A'] = 1;
    (*nodes)++;

    //cout << "set vis[i] as 1 for char: " << c << 
    //" and current nodes are " << *nodes << endl;

    for(auto it: adj[c])
        if(!(*vis)[it-'A']) dfs(adj, it, vis, nodes);
}

int main()
{
    int testcases;
    cin >> testcases;
    cin.ignore();
    while(testcases--)
    {
        unordered_map<char, vector<char>> adj;
        string line;
        while(getline(cin,line) && line[0]!='*')
        {
            adj[line[1]].push_back(line[3]);
            adj[line[3]].push_back(line[1]);
        }

        bitset<26> vis, ver;
        int nvertices{0};

        getline(cin, line);
        for(int i=0; i<line.length(); i+= 2){
            ver[line[i]-'A'] =  1;
            nvertices++;
        }

        int trees{0}, acorns{0};
        for(int i=0; i<26; i++){
            if(ver[i]&!vis[i])
            {
                //cout << "It came here for char: " << i+'A' << "with ver[i]: " 
                //<< " and vis[i]: " << vis[i] << endl;

                int nodes{0};
                dfs(adj, i+'A', &vis, &nodes);
                if(nodes == 1) acorns ++;
                else trees++;
                
                //cout << "vis[i] after searching: " << vis[i] << " and connected nodes were " 
                //<< nodes << endl;
            }
        }

        cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s)." << endl;
    }
    
    return 0;
}