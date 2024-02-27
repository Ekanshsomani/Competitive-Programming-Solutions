#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, a;
    vector<int> arr;

    while(cin >> n and n)
    {
        arr.clear();
        for(int i=0; i<n; i++)
        {
            cin >> a;
            if(a)
                arr.push_back(a);
        }
        
        int l = arr.size();

        if(l==0)
            printf("0\n");
        else
        {
            for(int i=0; i<l-1; i++)
                printf("%d ", arr[i]);
            printf("%d\n", arr[l-1]);
        }
    }

    return 0;
}