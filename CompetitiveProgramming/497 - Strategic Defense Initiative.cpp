#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    cin.ignore();
    cin.ignore();

    string line;
    while(testcases--)
    {
        vector<int> values;
        while(getline(cin, line) and line!="")
            values.push_back(stoi(line));

        int size = values.size();
        vector<int> smallestPos, parent(size, -1), idxVal(size);
        smallestPos.push_back(values[0]);

        for(int i=1; i<size; i++)
        {
            int j = lower_bound(smallestPos.begin(), smallestPos.end(), values[i])
            - smallestPos.begin();
            if(j)
                parent[i] = idxVal[j-1];
            else
                parent[i] = -1;

            if(j==smallestPos.size())
                smallestPos.push_back(values[i]);
            else
                smallestPos[j] = values[i];

            idxVal[j] = i;
        }

        list<int> ans;
        int i = idxVal[smallestPos.size()-1];
        while(i!=-1)
        {
            ans.push_front(values[i]);
            i = parent[i];
        }

        printf("Max hits: %d\n", smallestPos.size());
        for(auto it: ans)
            printf("%d\n", it);
        if(testcases)
            printf("\n");
    }
    return 0;
}