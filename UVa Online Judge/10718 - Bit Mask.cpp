#include <iostream>
using namespace std;

// start from MSB
    // if its on in n:
        // check if turning all the bit below it on in m still keeps
        // m less than l, if yes, than turn this bit in m;
        // Because duh, anything else will keep m<l (We're going dooown)
        // we can call this bit necessary bit (for keeping m in range)
    // else
        // check if turning on this bit in m still keeps it less than or equal to u
        // if yes then turn this bit on

int main()
{
    unsigned long long n, l, m, u, on, temp;
    while(cin >> n >> l >> u)
    {
        m = 0;
        for(int i=0; i<=32; i++)
        {
            on = n&(1LL<<(32-i));
            if(on)
            {
                temp = on - 1;
                temp |= m;
                if(temp<l)
                    m |= on;
            }
            else
            {
                temp = m;
                temp |= (1LL<<(32-i));
                if(temp<=u)
                    m = temp;
            }
        }

        printf("%llu\n", m);
    }
    return 0;
}