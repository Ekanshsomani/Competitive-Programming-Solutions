#include <iostream>
using namespace std;

int main()
{
    int arr[100000];
    int n, k, rdAtI;

    int testcases;
    cin >> testcases;
    for(int t=1; t<=testcases; t++)
    {
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> arr[i];

        k = 0;
        for(int i=n-2; i>-1; i--)
        {
            rdAtI = arr[i+1]-arr[i];
            if(rdAtI>k)
                k = rdAtI;
            else if(rdAtI==k)
                k = rdAtI+1;
        }
        if(arr[0]>k)
            k = arr[0];
        else if(arr[0]==k)
            k = arr[0]+1;

        printf("Case %d: %d\n", t, k);
    }
    return 0;
}