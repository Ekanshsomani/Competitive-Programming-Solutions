#include <iostream>
#include <cmath>
using namespace std;

int p, q, r, s, t, u;

inline double calculate(double x)
{
    return (p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u);
}

int main()
{
    while(cin >> p)
    {
        cin >> q >> r >> s >> t >> u;
        double low{0}, high{1};
        if(calculate(low)*calculate(high)>0)
            printf("No solution\n");
        else
        {
            double mid{(low+high)/2.0};
            double cm = calculate(mid);
            while(fabs(cm)>1.0e-7)
            {
                if(cm*calculate(low)>0)
                    low = mid;
                else
                    high = mid;

                mid = (low+high)/2.0;
                cm = calculate(mid);
            }

            printf("%.4f\n", mid);
        }
    }
    return 0;
}