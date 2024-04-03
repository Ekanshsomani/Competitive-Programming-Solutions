#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin >> n and n)
    {
        vector<int> initial(n, 0);

        bool isValid{true};
        for(int i=0; i<n; i++)
        {
            int carId, won;
            cin >> carId >> won;
            int pos = i+won;
            if(pos<0 or pos>=n or initial[pos]!=0)
            {
                isValid = false;
                continue;
            }
            initial[pos] = carId;
        }

        if(isValid)
            for(int i=0; i<n; i++)
                cout << initial[i] << (i==n-1 ? "\n" : " ");
        else
            printf("-1\n");
    }
    return 0;
}