#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// while iterating for first c specimen:

int main()
{
    int specimen[10], chambers[5][2];
    int testcase{1};

    int c, s;
    while(cin >> c >> s)
    {
        printf("Set #%d\n", testcase++);

        int sum = 0;
        for(int i=0; i<s; i++)
        {
            cin >> specimen[i];
            sum += specimen[i];
        }
        double am {sum/(1.0*c)};
        double imbalance{0};

        sort(specimen, specimen+s);

        if(s<=c)
        {
            for(int i=0; i<s; i++)
            {
                imbalance += fabs(am - specimen[i]);
                printf(" %d: %d\n", i, specimen[i]);
            }

            for(int i=s; i<c; i++)
            {
                printf(" %d:\n", i);
                imbalance += am;
            }
        }
        else
        {
            for(int i=s-c; i<s; i++)
            {
                chambers[i-(s-c)][0] = specimen[i];
            }

            for(int i=0; i<s-c; i++)
            {
                chambers[i][1] = specimen[s-(c+i+1)];
            }

            for(int i=0; i<s-c; i++)
            {
                printf(" %d: %d %d\n", i, chambers[i][0], chambers[i][1]);
                imbalance += fabs(chambers[i][0]+chambers[i][1]-am);
            }

            for(int i=(s-c); i<c; i++)
            {
                printf(" %d: %d\n", i, chambers[i][0]);
                imbalance += fabs(chambers[i][0]-am);
            }
        }

        printf("IMBALANCE = %.5f\n\n", imbalance);
    }
    return 0;
}