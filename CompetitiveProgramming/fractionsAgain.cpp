// 10976
// x*y = k*(x+y)
// x = k*y/(y-k)
// => (k*y)%(y-k) = 0

#include <iostream>
using namespace std;

int main()
{
    int k;
    while(cin >> k)
    {
        int cnt{0};
        for(int y=k+1; y<=2*k; y++)
            if((k*y)%(y-k)==0) cnt++;

        printf("%d\n", cnt);

        for(int y=k+1; y<=2*k; y++)
            if((k*y)%(y-k)==0)
                printf("1/%d = 1/%d + 1/%d\n", k, (k*y)/(y-k), y);
    }
    return 0;
}