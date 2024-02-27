#include <iostream>
#include <bitset>
#include <string>
using namespace std;

bitset<256> vis;
int n, initial, finalState;
string state;

int next_state(int x)
{
    int a{0};
    a |= (x>>(n-1))^((x>>1)&1);
    for(int i=1; i<n-1; i++)
        a |= ((x>>1)&(1<<i))^((x<<1)&(1<<i));
    a |= ((x<<(n-1))&(1<<(n-1)))^((x<<1)&(1<<(n-1)));
    return a;
}

int main()
{
    while(cin >> initial)
    {
        cin >> n >> state;
        cout << initial << ' ' << n << ' ' << state << endl;

        finalState = 0;
        for(int i=0; i<n; i++)
            finalState |= ((state[i]-'0')<<(n-1-i));

        

        bool reachable{false};
        do
        {
            if(vis[initial])
                break;

            vis[initial] = 1;

            if(initial==finalState)
            {
                reachable = true;
                break;
            }
        }
        while((initial = next_state(initial)));

        if(reachable)
            printf("REACHABLE\n");
        else
            printf("GARDEN OF EDEN\n");

        vis.reset();
    }

    return 0;
}