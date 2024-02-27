// 524

#include <iostream>
#include <bitset>
using namespace std;

int ring[16], n;
bitset<32> is_prime;
bitset<17> used;

inline void createSieve()
{
    for(int i=0; i<32;  i++)
        is_prime[i] = (i&1)?true:false;

    is_prime[2] = true;
    for(int i=3; i<32; i+=2)
        if(is_prime[i])
            for(int j=i<<1; j<32; j+=i)
                is_prime[j] = false;
}

inline void searchRings(int index)
{
	if(index == n - 1 and is_prime[ring[index] + ring[n]])
    {
        for(int i=0; i<n; i++)
            cout << ring[i] << (i + 1 == n?"\n":" ");
        return;
    }

    for(int i=2; i<=n; i++)
        if(!used[i] && is_prime[ring[index]+i])
        {
            used[i] = true;
            ring[index+1] = i;
            searchRings(index+1);
            used[i] = false;
        }
    
}

int main()
{   
    createSieve();
    int t{0}; 
    while(cin >> n)
    {
        if(t++) cout << endl;
        cout << "Case " << t << ':' << endl;

        ring[0] = 1;
        ring[n] = 1;

        searchRings(0);
    }
    return 0;
}