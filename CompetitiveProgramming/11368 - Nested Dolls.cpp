#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>&a, pair<int, int> &b)
{
    if(a.first==b.first) // prevents nesting if the first element are equal
        return a.second > b.second;
    return a.first < b.first;
}

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int m;
        cin >> m;

        vector<pair<int, int>> dolls(m);
        for(int i=0; i<m; i++)
            cin >> dolls[i].first >> dolls[i].second;
        sort(dolls.begin(), dolls.end(), compare);

        // simulates nesting over second value (greedy approach);
        // find the largest value smaller than y
        // replaces it with y;
        deque<int> nestedDoll;
        nestedDoll.push_back(dolls[0].second);
        for(int i=1; i<m; i++)
        {
            auto it = lower_bound(nestedDoll.begin(), nestedDoll.end(), 
                dolls[i].second);
            if(it == nestedDoll.begin())
                nestedDoll.push_front(dolls[i].second);
            else
                *(prev(it)) = dolls[i].second;
        }

        printf("%d\n", nestedDoll.size());
    }
    return 0;
}