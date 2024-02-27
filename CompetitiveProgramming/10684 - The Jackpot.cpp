#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n and n)
    {
        int maxsum{0}, sum{0};
        for(int i=0; i<n; i++)
        {
            int num;
            cin >> num;
            sum += num;
            maxsum = max(maxsum, sum);
            if(sum<0)
                sum = 0;
        }

        if(maxsum>0)
            printf("The maximum winning streak is %d.\n", maxsum);
        else
            printf("Losing streak.\n");
    }
    return 0;
}