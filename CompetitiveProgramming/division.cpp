// 725

#include <iostream>
using namespace std;

// fghij - 01234 to 98765
// but abcdef/fghij = n
// => fghij*n = abcdef <= 98765

int main()
{
    int t{0};
    int n;
    while(scanf("%d", &n) && n)
    {
        if(t++) printf("\n");

        bool exists{0};
        for(int i=1234; n*i<=98765; i++)
        {
            int j{n*i}, used{i<10000}, temp;
            temp = i; while(temp) {used |= 1<<(temp%10); temp /= 10;}
            temp = j; while(temp) {used |= 1<<(temp%10); temp /= 10;}
            
            if(used == (1<<10)-1)
            {
                exists = 1;
                printf("%0.5d / %0.5d = %d\n", j, i, n);
            }

        }
        if(!exists) printf("There are no solutions for %d.\n",n);
    }
    return 0;
}