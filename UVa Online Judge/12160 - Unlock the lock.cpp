#include <bits/stdc++.h>
using namespace std;

int main()
{
    int presses[10000], test{1};
    int start, target, buttons;
    while(cin >> start >> target >> buttons and (start or target or buttons))
    {
        int val[buttons];
        for(int i=0; i<buttons; i++)
            cin >> val[i];

        memset(presses, -1, sizeof presses);
        queue<int> q;
        q.push(start);
        presses[start] = 0;

        while(not q.empty())
        {
            int node {q.front()};
            q.pop();

            if(node==target)
                break;

            for(int i=0; i<buttons; i++)
            {
                int adj = (node+val[i])%10000;
                if(presses[adj]==-1)
                {
                    presses[adj] = presses[node]+1;
                    q.push(adj);
                }
            }
        }

        printf("Case %d: ",  test++);
        if(presses[target]==-1)
            printf("Permanently Locked\n");
        else
            printf("%d\n", presses[target]);
    }
    return 0;
}