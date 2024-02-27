#include <iostream>
#include <algorithm>
using namespace std;

// code can be made more efficient by only iterating over the array while the values
// are less than half of the budget. i.e:
    // arr[i]<=(budget>>1);

int main()
{
    int arr[10000], budget, n;
    int a, b, minDiff;
    while(cin >> n)
    {
        minDiff = 1000001;
        for(int i=0; i<n; i++)
            cin >> arr[i];

        sort(arr, arr+n);

        cin >> budget;

        for(int i=0; i<n; i++)
            if(binary_search(arr, arr+n, budget-arr[i]) and 
            abs(budget-2*arr[i])<minDiff)
            {
                if(arr[i]==(budget-arr[i]) and arr[i]!=arr[i+1])
                    continue;
                minDiff = abs(budget-2*arr[i]);
                a = (budget-2*arr[i]>0)?arr[i]:(budget-arr[i]);
                b =  (budget-2*arr[i]>0)?(budget-arr[i]):arr[i];
            }

        printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);
    }
    return 0;
}