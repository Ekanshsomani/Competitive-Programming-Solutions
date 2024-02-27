#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        vector<int> values(n);
        for(int i=0; i<n; i++)
            cin >> values[i];

        vector<int> smallestPos, decreasingSeqLength(n, 1);
        smallestPos.push_back(values[n-1]);
        for(int i=n-2; i>-1; i--)
        {
            int j = 
                lower_bound(smallestPos.begin(), smallestPos.end(), values[i]) - 
                smallestPos.begin();

            if(j==smallestPos.size())
                smallestPos.push_back(values[i]);
            else
                smallestPos[j] = values[i];
            decreasingSeqLength[i] = j+1;
        }

        int maxWavio{1};

        smallestPos.clear();
        smallestPos.push_back(values[0]);
        for(int i=1; i<n; i++)
        {
            int j = 
                lower_bound(smallestPos.begin(), smallestPos.end(), values[i]) - 
                smallestPos.begin();
            
            if(j==smallestPos.size())
                smallestPos.push_back(values[i]);
            else
                smallestPos[j] = values[i];
            
            maxWavio = max(maxWavio, min(j+1, decreasingSeqLength[i]));
        }

        printf("%d\n", 2*(maxWavio-1)+1);
    }
}