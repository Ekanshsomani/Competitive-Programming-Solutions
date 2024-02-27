// 11565

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int bound = (int)sqrt(c);
        bool found{0};
        for(int x=-bound; (x<=bound)&&!found; x++)
            for(int y=-bound; (y<=bound)&&!found; y++)
            {
                int z = a-(x+y);
                if(x!=y && y!=z && x!=z && x*y*z==b && (x*x+y*y+z*z)==c)
                {
                    found = 1;
                    cout << x << ' ' << y << ' ' << z << endl;
                }
            }

        if(!found) cout << "No solution." << endl;
    }
    return 0;
}