#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int diameter[20000], height[20000];
    int heads, knights;
    while(cin >> heads >> knights and (heads or knights))
    {
        for(int i=0; i<heads; i++)
            cin >> diameter[i];
        
        for(int i=0; i<knights; i++)
            cin >> height[i];

        sort(diameter, diameter+heads);
        sort(height, height+knights);

        int k{0}, coins{0};
        for(int h=0; h<heads; h++)
        {
            k = lower_bound(height+k, height+knights, diameter[h]) - height;
            if(k==knights)
            {
                k++;
                break;
            }
            if(k==(knights-1) and h<(heads-1))
            {
                k = knights+1;
                break;
            }
            coins += height[k];
            k++;
        }

        if(k>knights)
            printf("Loowater is doomed!\n");
        else
            printf("%d\n", coins);
    }
    return 0;
}