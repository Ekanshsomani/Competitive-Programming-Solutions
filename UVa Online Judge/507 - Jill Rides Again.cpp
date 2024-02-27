#include <iostream>
using namespace std;

int main()
{

    int testcases;
    cin >> testcases;
    for(int t=1; t<=testcases; t++)
    {
        int stops;
        cin >> stops;
        stops--;

        pair<int, int> maxRange;
        int maxSum{0}, sum{0}, start{1};
        for(int i=0; i<stops; i++)
        {
            int niceness;
            cin >> niceness;
            sum += niceness;
            if(sum<0)
            {
                sum = 0;
                start = i+2;
            }
            else if(sum>maxSum)
            {
                maxSum = sum;
                maxRange = {start, i+2};
            }
            else if(sum==maxSum and (i+2-start)>(maxRange.second-maxRange.first))
                maxRange = {start, i+2};
        }

        if(maxSum>0)
            printf("The nicest part of route %d is between stops %d and %d\n", t, maxRange.first, maxRange.second);
        else
            printf("Route %d has no nice parts\n", t);
    }
    return 0;
}