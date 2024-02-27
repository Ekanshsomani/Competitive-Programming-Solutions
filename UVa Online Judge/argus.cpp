// 1203
// ps: a multiset or map would have been a faster structure for this question than pq;

#include <iostream>
#include <queue>
#include <string>
using namespace std;

priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, 
greater<pair<pair<int, int>, pair<int, int>>>> pq;

int main()
{
    string reg;
    while(cin >> reg && reg[0]!='#')
    {
        int query, period;
        cin >> query >> period;
        pq.push({{period, query}, {period, 1}});
    }

    int k;
    cin >> k;
    while(k--)
    {
        int period = pq.top().second.first;
        int query = pq.top().first.second;
        int factor = pq.top().second.second;
        factor++;

        pq.pop();
        pq.push({{factor*period, query}, {period, factor} });

        cout << query << endl;
    }

    return 0;
}