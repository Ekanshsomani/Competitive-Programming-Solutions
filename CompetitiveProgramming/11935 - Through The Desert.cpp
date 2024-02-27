#include <iostream>
using namespace std;

int main()
{
    float consumed, maxconsumed;

    int dist, consumption, lastDist, leakage;
    string a, b;
    while(cin >> dist >> a >> b >> consumption and consumption>0)
    {
        maxconsumed = 0;
        consumed = 0;
        lastDist = 0;
        leakage = 0;

        while(cin >> dist >> a and a!="Goal")
        {
            consumed += consumption*(dist-lastDist)/100.0 + leakage*(dist-lastDist);
            lastDist = dist;
            if(a=="Leak")
                leakage++;
            else if(a=="Mechanic")
                leakage = 0;
            else if(a=="Fuel")
                cin >> b >> consumption;
            else
            {
                cin >> b;
                if(consumed>maxconsumed)
                    maxconsumed = consumed;
                consumed = 0;
            }
        }

        consumed += consumption*(dist-lastDist)/100.0 + leakage*(dist-lastDist);
        if(consumed>maxconsumed)
            maxconsumed = consumed;

        printf("%.3f\n", maxconsumed);
    }
    return 0;
}