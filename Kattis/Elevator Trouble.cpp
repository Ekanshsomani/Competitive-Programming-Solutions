#include <bits/stdc++.h>

using namespace std;

int floors;

inline bool isInside(int f)
{
    return (f>0 and f<=floors);
}

int main()
{
    int start, target, up, down;
    cin >> floors >> start >> target >> up >> down;

    vector<bool> vis(floors+1, false);
    queue<pair<int, int>> q;
    q.emplace(0, start);
    vis[start] = true;
    while(not q.empty())
    {
        auto [pushes, u] = q.front();
        q.pop();

        if(u==target)
        {
            printf("%d\n", pushes);
            break;
        }

        int v{u+up};
        if(isInside(v) and not vis[v])
        {
            vis[v] = true;
            q.emplace(pushes+1, v);
        }
        v = u-down;
        if(isInside(v) and not vis[v])
        {
            vis[v] = true;
            q.emplace(pushes+1, v);
        }
    }

    if(not vis[target])
        printf("use the stairs\n");
    return 0;
}