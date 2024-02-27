// 624

#include <iostream>
using namespace std;


int duration[20];

int main()
{
    int tape;
    while(cin >> tape)
    {
        int tracks;
        cin >> tracks;
        for(int i=0; i<tracks; i++) 
            cin >> duration[i];

        int minDiff{tape}, chosen;
        for(int i=1; i<(1<<tracks); i++)
        {
            int s{0};
            for(int j=0; j<tracks; j++)
                if(i&(1<<j)) s+= duration[j];
            
            if(tape-s>=0 && tape-s<minDiff)
            {
                minDiff = tape - s;
                chosen = i;
            }
            else if(tape-s>=0 && tape-s==minDiff)
                for(int j=0; j<tracks; j++)
                {
                    int a{i&(1<<j)}, b{chosen&(1<<j)};
                    if(a!=b)
                    {
                        if(a)
                            chosen = i;
                        break;
                    }
                }
        }

        for(int i=0; i<tracks; i++)
            if(chosen&(1<<i))
                cout << duration[i] << ' ';
        
        cout << "sum:" << tape-minDiff << endl;
    }
    return 0;
}