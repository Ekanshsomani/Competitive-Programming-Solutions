// 11242

#include <iostream>
#include <set>
using namespace std;

int front[10], rear[10];

int main()
{
    int f, r;
    while(cin >> f >> r, f){
        for(int i=0; i<f; i++) cin >> front[i];
        for(int i=0; i<r; i++) cin >> rear[i];

        multiset<float> ratios;
        for(int i=0; i<f; i++)
            for(int j=0; j<r; j++)
            {
                float itf{(float)front[i]}, itr{(float)rear[j]};
                ratios.insert(itr/itf);
            }

        float max{0};
        float prev = *ratios.begin();
        for(auto it:ratios)
        {
            if(it/prev > max) max = it/prev;
            prev = it;
        }

        printf("%.2f\n", max);
    }
    return 0;
}