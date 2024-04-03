#include <bits/stdc++.h>

using namespace std;

const int INF = 10000;

int am[500][500], parent[500][500];

int main()
{
    int V;
    cin >> V;

    string names[V];
    unordered_map<string, int> nameIdx;
    for(int i=0; i<V; i++)
    {
        cin >> names[i];
        nameIdx[names[i]] = i;
        for(int j=0; j<V; j++)
        {
            am[i][j] = INF;
            parent[i][j] = i;
        }
    }

    for(int i=0; i<V; i++)
    {
        string file;
        int u, k;
        cin >> file >> k;
        cin.ignore();
        u = nameIdx[file];
        while(k--)
        {
            string line;
            getline(cin, line);
            istringstream iss(line);
            iss >> file;

            while(iss >> file)
            {
                if(not isalpha(file.back())) file.pop_back();
                am[u][nameIdx[file]] = 1;
            }
        }
    }

    for(int k=0; k<V; k++)
        for(int u=0; u<V; u++)
            for(int v=0; v<V; v++)
                if(am[u][v] > am[u][k]+am[k][v])
                {
                    am[u][v] = am[u][k]+am[k][v];
                    parent[u][v] = parent[k][v];
                }

    int cycleSize{INF}, u;
    for(int i=0; i<V; i++)
        if(am[i][i]<cycleSize)
        {
            cycleSize = am[i][i];
            u = i;
        }

    if(cycleSize==INF)
        printf("SHIP IT\n");
    else
    {
        stack<int> path;
        int v = u;
        int s = cycleSize;
        while(s--)
        {
            path.push(v);
            v = parent[u][v];
        }

        while(cycleSize--)
        {
            cout << names[path.top()] << (cycleSize ? " " : "\n");
            path.pop();
        }
    }
    return 0;
}