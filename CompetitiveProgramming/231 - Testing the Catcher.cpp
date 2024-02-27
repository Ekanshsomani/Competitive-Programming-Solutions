// how can I count the longest decreasing subSequence

// array indexVal, vector largestPos
    // at every index i, it storest the largest possible element for subSeq
    // of length i+1.
    // indexVal stores the index of that element in values;
    // intialize 
        // largestPos[0] = values[0];
        // indexVal[0] = 0;
// for int i=1 to size-1
    // binary search to get the location j of first element less than
    // arr[i] in largestPos

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int test{1};
    vector<int> heights, largestPos;
    int val;
    while(cin >> val and val>-1 )
    {
        heights.push_back(val);
        while(cin >> val and val>-1)
            heights.push_back(val);

        int size = heights.size();
        largestPos.push_back(heights[0]);

        for(int i=1; i<size; i++)
        {
            auto it = upper_bound(largestPos.begin(), largestPos.end(), 
                heights[i], greater<int>());

            if(it==largestPos.end())
                largestPos.push_back(heights[i]);
            else
                *it = heights[i];
        }
        if(test>1) printf("\n");
        printf("Test #%d:\n  maximum possible interceptions: %d\n", 
        test++, largestPos.size());

        largestPos.clear();
        heights.clear();
    }
    return 0;
}