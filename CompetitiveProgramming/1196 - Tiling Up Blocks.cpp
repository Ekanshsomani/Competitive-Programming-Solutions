#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while(cin >> n and n)
    {
        vector<pair<int, int>> blocks(n);
        for(int i=0; i<n; i++)
            cin >> blocks[i].first >> blocks[i].second;
        sort(blocks.begin(), blocks.end());

        vector<int> smallestM(1, blocks[0].second);
        for(int i=1; i<n; i++)
        {
            auto it = upper_bound(smallestM.begin(), smallestM.end(), blocks[i].second);
            if(it==smallestM.end())
                smallestM.push_back(blocks[i].second);
            else
                *it = blocks[i].second;
        }
        printf("%d\n", smallestM.size());
    }
    printf("*\n");
}