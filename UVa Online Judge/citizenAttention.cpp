// 10660

// col = ofNum%5;
// row = ofNum/5;

#include <iostream>
#include <limits.h>
using namespace std;

int pops[25*3], arr[5];

/*
s+= pops[a]*
                                (
                                    abs(i/5 - pops[a+1]) + abs(i%5 - pops[a+2]) +
                                    abs(j/5 - pops[a+1]) + abs(j%5 - pops[a+2]) +
                                    abs(k/5 - pops[a+1]) + abs(k%5 - pops[a+2]) +
                                    abs(l/5 - pops[a+1]) + abs(l%5 - pops[a+2]) +
                                    abs(m/5 - pops[a+1]) + abs(m%5 - pops[a+2])
                                );
*/

inline int getMinDist(int i,  int row, int col)
{
    return abs(i/5 - row) + abs(i%5 - col);
}

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int n;
        cin >> n;
        for(int i=0; i<3*n; i+=3)
            cin >>  pops[i+1] >> pops[i+2] >> pops[i];

        int minSum(INT_MAX);
        int minOffices[5];

        for(arr[0]=0; arr[0]<21; arr[0]++)
            for(arr[1]=arr[0]+1; arr[1]<22; arr[1]++)
                for(arr[2]=arr[1]+1;  arr[2]<23; arr[2]++)
                    for(arr[3]=arr[2]+1; arr[3]<24; arr[3]++)
                        for(arr[4]=arr[3]+1; arr[4]<25; arr[4]++)
                        {
                            int s{0};
                            for(int a=0; a<3*n; a+=3)
                            {
                                int mini(INT_MAX);
                                for(int i=0; i<5; i++)
                                {
                                    mini = min(getMinDist(arr[i], pops[a+1], pops[a+2]), mini);
                                }
                                s+=pops[a] * mini;
                            }
                            if(s<minSum)
                            {
                                minSum = s;
                                minOffices[0] = arr[0];
                                minOffices[1] = arr[1];
                                minOffices[2] = arr[2];
                                minOffices[3] = arr[3];
                                minOffices[4] = arr[4];
                            }
                        }
        
        for(int i=0; i<4; i++)
            cout << minOffices[i] << ' ';
        cout << minOffices[4] << endl;
    }
    return 0;
}