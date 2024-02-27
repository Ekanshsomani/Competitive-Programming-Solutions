#include <iostream>
using namespace std;

int arr[1000];

int main()
{
    int t{1};
    int n;
    while(scanf("%d", &n)&& n)
    {
        for(int i=0; i<n; i++) scanf( "%d" ,&arr[i]);

        printf("Case %d:\n", t++);

        int m;
        cin >> m;
        while(m--)
        {
            int q;
            cin >> q;

            int minSum{arr[0]+arr[1]};
            for(int i=0; i<n-1; i++)
                for(int j=i+1; j<n; j++)
                    if(abs(q-(arr[i]+arr[j]))<abs(q-minSum)) 
                        minSum = arr[i]+arr[j];
            printf("Closest sum to %d is %d.\n", q, minSum);
        }
    }
    return 0;
}