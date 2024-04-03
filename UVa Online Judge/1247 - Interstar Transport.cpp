#include <bits/stdc++.h>

using namespace std;

const int INF = 10000;

int dist[26][26], steps[26][26], parent[26][26];

void printPath(int i, int j) 
{
    if (i != parent[i][j]) printPath(i, parent[i][j]);
    // printf(" %d-%d-%c %c", dist[i][j], steps[i][j], parent[i][j]+'A', j+'A');
    printf(" %c", j+'A');
}

int main()
{
    memset(dist, INF, sizeof dist);
    memset(steps, 0, sizeof steps);
    bitset<26> onList;

    int garbage, E;
    cin >> garbage >> E;
    while(E--)
    {
        char u, v;
        int w;
        cin >> u >> v >> w;
        u -= 'A'; v -= 'A';
        dist[u][v] = w; dist[v][u] = w;
        onList[v] = true; onList[u] = true;
    }
    // printf("Took in weights for dist\n");

    for(int u=0; u<26; u++)
    {
        dist[u][u] = 0;
        for(int v=0; v<26; v++)
            parent[u][v] = u;

        if(not onList[u])
        {
            int d{1};
            bool found{false};
            while(not found)
            {
                if(u-d >= 0 and onList[u-d])
                {
                    found = true; 
                    dist[u][u-d] = 0;
                    dist[u-d][u] = 0;
                }
                if(u+d < 26 and onList[u+d])
                {
                    found = true;
                    dist[u][u+d] = 0;
                    dist[u+d][u] = 0;
                }
                d++;
            }
        }
    }
    // printf("Completely created dist\n");

    for(int k=0; k<26; k++)
        for(int u=0; u<26; u++)
            for(int v=0; v<26; v++)
            {
                int d = dist[u][k] + dist[k][v];
                int s = steps[u][k] + steps[k][v] + 1;
                if(dist[u][v]>d)
                {
                    dist[u][v] = d;
                    steps[u][v] = s;
                    parent[u][v] = parent[k][v];
                }
                else if(dist[u][v]==d and steps[u][v]>s)
                {
                    steps[u][v] = s;
                    parent[u][v] = parent[k][v];
                }
            }
            
    int queries;
    cin >> queries;
    while(queries--)
    {
        char start, target;
        cin >> start >> target;
        // cout << start << " " << target << endl;
        start -= 'A'; target -= 'A';

        // printf("%d-%d-%c %c", dist[start][target], steps[start][target], parent[start][target]+'A', start+'A');
        printf("%c", start+'A');
        printPath(start, target);
        printf("\n");
    }
    return 0;
}