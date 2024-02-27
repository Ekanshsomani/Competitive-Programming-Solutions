#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int main()
{
    set<pair<double, double>> sprinkler;
    int num;
    double start, farthest;
    set<pair<double,double>>::iterator it;

    int n, l, w;
    while(cin >> n >> l >> w)
    {
        sprinkler.clear();

        for(int i=0; i<n; i++)
        {
            int x, r;
            cin >> x >> r;

            if(2*r<w)
                continue;

            double d = sqrt(r*r-w*w/4.0);
            sprinkler.insert({x-d, x+d});
        }

        it = sprinkler.begin();
        num = 1;
        start = 0;
        farthest = 0;
        while(it!=sprinkler.end())
        {
            while(it!=sprinkler.end() and (*it).first<= start)
            {
                farthest = max(farthest, (*it).second);
                it++;
            }

            if(farthest==start or farthest>=l)
                break;

            num++;
            start = farthest;
        } 

        if(farthest>=l)
            printf("%d\n", num);
        else
            printf("-1\n");
    }
    return 0;
}