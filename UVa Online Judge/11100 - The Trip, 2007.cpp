#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int bags[10000];
    int count, maxCount, index;
    vector<int> pieces[10000];

    int t{0}, n;
    while(cin >> n and n)
    {
        for(int i=0; i<n; i++)
            pieces[i].clear();

        if(t++)
            printf("\n");

        for(int i=0; i<n; i++)
            cin >> bags[i];

        sort(bags, bags+n);

        count = 1;
        maxCount = 0;
        for(int i=1; i<n; i++)
        {
            if(bags[i]!=bags[i-1])
            {
                maxCount = max(maxCount, count);
                count = 0;
            }
            count++;
        }
        maxCount = max(maxCount, count);

        /*
        for(int i=0; i<n-1; i++)
            printf("%d ", bags[i]);
        printf("%d\n", bags[n-1]);
        /**/

        index = 0;
        for(int i=0; i<n; i++)
        {
            pieces[index].push_back(bags[i]);
            index++;
            if(index==maxCount)
                index = 0;
        }

        printf("%d\n", maxCount);
        for(int i=0; i<maxCount; i++)
        {
            for(const auto& it: pieces[i])
            {
                printf("%d", it);
                printf((it==pieces[i].back())?"\n":" ");
            }
        }
    }
    return 0;
}