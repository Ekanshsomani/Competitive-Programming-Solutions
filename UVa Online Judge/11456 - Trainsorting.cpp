#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// smalest possible wt for increasing subSeq length i+1
    // every time find the first weight greater than x
// largest possible wt for decreasing subSeq length i+1
    // every time find the first weight less than x

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int n;
        cin >> n;
        if(n==0)
        {
            printf("0\n");
            continue;
        }

        vector<int> cars(n);
        for(int i=0; i<n; i++)
            cin >> cars[i];

        vector<int> smallestWt, largestWt;
        smallestWt.push_back(cars[n-1]); 
        largestWt.push_back(cars[n-1]);
        int maxLength{1};
        for(int i=n-1; i>-1; i--)
        {
            int j1 = lower_bound(smallestWt.begin(), smallestWt.end(), cars[i]) - smallestWt.begin();
            int j2 = lower_bound(largestWt.begin(), largestWt.end(), cars[i], greater<int>()) - largestWt.begin();

            if(j1==smallestWt.size())
                smallestWt.push_back(cars[i]);
            else
                smallestWt[j1] = cars[i];
            
            if(j2==largestWt.size())
                largestWt.push_back(cars[i]);
            else
                largestWt[j2] = cars[i];
            int trainLength{j1+j2+1};
            maxLength = max(maxLength, trainLength);
        }

        printf("%d\n", maxLength);
    }
    return 0;
}