// 927

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;

    int c[21];

    while(testcases--)
    {
        int degree;
        cin >> degree;

        for(int i=0; i<=degree; i++) cin >> c[i];
        
        int d, k;
        cin >> d >> k;
        
        long long x = 1;
		long long ans = 0;
		long long current = 0;

		while(current < k)
		{
			current += x * d;
			
			if(k <= current)
			{		
				ans = 0;
				
				for(int i = 0; i <= degree; ++i)
					ans += c[i] * pow(x, i);
			}
			++x;
		}

		cout << ans << endl;

    }
    return 0;
}