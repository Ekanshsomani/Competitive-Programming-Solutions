#include <iostream>
using namespace std;

int arr[5], n;
int minSwaps;
int swapMaps;

bool isSort()
{
    for(int i=0; i<n-1; i++)
        if(arr[i]>arr[i+1])
            return false;
    return true;
}

void swap(int i)
{
    int temp = arr[i];
    arr[i] = arr[i+1];
    arr[i+1] = temp;
}

void backtrack(int swaps)
{
    if(isSort())
    {
        if(swaps==minSwaps)
        {
            swapMaps++;
            return;
        }
        minSwaps = swaps;
        swapMaps = 1;
        return;
    }
    if(swaps==minSwaps)
        return;
    
    for(int i=0; i<n-1; i++)
        if(arr[i]>arr[i+1])
        {
            swap(i);
            backtrack(swaps+1);
            swap(i);
        }
}

int main()
{
    int t{1};
    while(cin >> n and n>0)
    {
        for(int i=0; i<n; i++)
            cin >> arr[i];

        if(isSort())
        {
            printf("There are 0 swap maps for input data set %d.\n", t++);
            continue;
        }

        minSwaps = n<<1;
        swapMaps = 0;
        backtrack(0);

        printf("There are %d swap maps for input data set %d.\n", swapMaps, t++);

    }
    return 0;
}