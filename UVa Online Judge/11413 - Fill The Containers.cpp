#include <iostream>
using namespace std;

int arr[1000000];
int vessels, containers;

bool isPossible(int capacity)
{
    int num{1}, currentFill{0};
    for(int i=0; i<vessels; i++)
    {
        if(currentFill+arr[i]>capacity) 
        {
            currentFill = 0;
            num++;
        }
        if(num>containers)
            return false;

        currentFill += arr[i];
    }
    return true;
}

int main()
{
    int left, right, mid, min;
    while(cin >> vessels >> containers)
    {
        left = 0;
        right = 0;
        for(int i=0; i<vessels; i++)
        {
            cin >> arr[i];
            right += arr[i];
            left = max(left, arr[i]);
        }
        

        if(vessels<containers)
            printf("%d\n", left);
        else
        {
            min = right;
            mid = (left+right)>>1;

            while(left<right)
            {
                if(isPossible(mid))
                {
                    right = mid;
                    min = mid;
                }
                else
                    left = mid+1;

                mid = (left+right)>>1;
            }
            
            printf("%d\n", min);
        }
        
    }
    return 0;
}