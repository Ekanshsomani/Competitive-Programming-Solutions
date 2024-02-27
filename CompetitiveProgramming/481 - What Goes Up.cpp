#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> values;
    int value;
    while(cin >> value)
        values.push_back(value);

    int size = values.size();
    vector<int> parent(size), endVal, index(1, 0); 
    // endVal - Stores the smallest last element available for the 
    // ith length of subseQ
    // index - stores the index of element in endVal;
    parent[0] = -1;
    endVal.push_back(values[0]);
    for(int i=1; i<size; i++)
    {
        int j = lower_bound(endVal.begin(), endVal.end(), values[i]) - endVal.begin();

        if(j==endVal.size())
        {
            parent[i] = index[index.size()-1];
            endVal.push_back(values[i]);
            index.push_back(i);
        }
        else
        {
            if(j)
                parent[i] = index[j-1];
            else
                parent[i] = -1;

            index[j] = i;
            endVal[j] = values[i];
        }
    }

    list<int> ans;
    int i = index[index.size()-1];
    while(i!=-1)
    {
        ans.push_front(values[i]);
        i = parent[i];
    }

    printf("%d\n-\n", endVal.size());
    for(auto it: ans)
        printf("%d\n", it);
    return 0;
}