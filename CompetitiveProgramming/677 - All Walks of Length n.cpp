// 677
// length <= 5
// nodes <= 10

// nodes length
// matrix
// -9999
// KISS Principle Used - Keep it Short and Simple

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int vertices, length;
bool adj[10][10], vis[10], found;
vector<int> walk;

inline void printVec()
{
    printf("(");
    for(int i=0; i<walk.size()-1; i++)
        printf("%d,", walk[i]);
    printf("%d)\n", walk[walk.size()-1]);
}

void backtrack(int node,int steps)
{
    if(steps==length)
    {
        found = true;
        printVec();
        return;
    }
    
    for(int i=0; i<vertices; i++)
        if((adj[node][i]) and (not vis[i]))
        {
            vis[i]= true;
            walk.push_back(i+1);
            backtrack(i, steps+1);
            walk.pop_back();
            vis[i] = false;
        }
}

int main()
{
    walk.push_back(1);
    memset(vis, false, 10);
    vis[0] = true;
    int garbage, t{0};

    while(scanf("%d %d", &vertices, &length)==2)
    {
        if(t++) printf("\n");

        for(int i=0; i<vertices; i++)
            for(int j=0; j<vertices; j++)
                scanf("%d",  &adj[i][j]);

        found = false;
        backtrack(0, 0);
        if(!found)
            printf("no walk of length %d\n", length);
        scanf("%d", &garbage);

    }
    return 0;
}