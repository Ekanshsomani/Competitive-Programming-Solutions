#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<pair<pair<int, int>, int>> elephants;
    int weight, iq, i{1};
    while(cin >> weight >> iq)
        elephants.push_back({{weight, iq}, i++});
    sort(elephants.begin(), elephants.end());

    int size = elephants.size();
    vector<int> parent(size, -1), maxSubLength(size, 1);
    int maxLength(1), maxIdx{0};
    for(int i=1; i<size; i++)
    {
        for(int j=0; j<i; j++)
            if( elephants[i].first.first>elephants[j].first.first and
                elephants[i].first.second<elephants[j].first.second and 
                maxSubLength[i]<=maxSubLength[j])
            {
                maxSubLength[i] = maxSubLength[j]+1;
                parent[i] = j;
            }
        if(maxSubLength[i]>maxLength)
        {
            maxLength = maxSubLength[i];
            maxIdx = i;
        }
    }

    int* ans = new int(maxLength);
    for(int i=1; i<=maxLength; i++)
    {
        ans[maxLength-i] = elephants[maxIdx].second;
        maxIdx = parent[maxIdx];
    }

    printf("%d\n", maxLength);
    for(int i=0; i<maxLength; i++)
        printf("%d\n",  ans[i]);
}