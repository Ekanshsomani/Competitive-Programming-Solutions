#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int junctions, streets;
        cin >> junctions >> streets;
        
        vector<int> adj[junctions];
        while (streets--)
        {
            int f, t;
            cin >> f >> t;
            adj[f].push_back(t);
            adj[t].push_back(f);
        }

        vector<int> placed(junctions, -1);
        queue<int> nodes;
        
        int guards{0};
        bool noFighting{true};

        for(int i=0; i<junctions; i++)
        {
            if(placed[i]==-1)
            {
                nodes.push(i);
                placed[i] = 0;
                int colorFreq[2]{1, 0};

                while((not nodes.empty()) and noFighting)
                {
                    int a = nodes.front();
                    nodes.pop();

                    for(auto it: adj[a])
                        if(placed[it]==-1)
                        {
                            placed[it] = 1-placed[a];
                            colorFreq[placed[it]]++;
                            nodes.push(it);
                        }
                        else if(placed[it]==placed[a])
                        {
                            noFighting = false;
                            break;
                        }
                }

                if(colorFreq[0] and colorFreq[1])
                    guards += min(colorFreq[0], colorFreq[1]);
                else
                    guards += max(colorFreq[0], colorFreq[1]);
            }
            if(not noFighting)
                break;
        }

        if(noFighting)
            printf("%d\n", guards);
        else
            printf("-1\n");
    }
    return 0;
}