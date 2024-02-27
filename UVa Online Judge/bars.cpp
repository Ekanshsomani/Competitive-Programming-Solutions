// 12455

#include <iostream>
using namespace std;

int p[20];

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int length, bars;
        cin >> length >> bars;
        for(int i=0; i<bars; i++)
            cin >> p[i];
        
        bool possible{0};
        for(int i=0; (i<(1<<bars)) && !possible; i++)
        {
            int sum{0};
            for(int j=0; (j<bars) && (sum<length); j++)
                if(i&(1<<j))
                    sum += p[j];
            
            if(sum==length) 
                possible = 1;
        }
        if(possible) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}
