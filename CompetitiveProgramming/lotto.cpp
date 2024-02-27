// 441

#include <iostream>
using namespace std;

int s[13];

int main()
{
    int k, t{0};
    while(cin >> k, k)
    {
        if(t++) printf("\n");

        for(int i=0; i<k; i++) cin >> s[i];

        for(int a=0; a<k-5; a++)
            for(int b=a+1; b<k-4; b++)
                for(int c=b+1; c<k-3; c++)
                    for(int d=c+1; d<k-2; d++)
                        for(int e=d+1; e<k-1; e++)
                            for(int f=e+1; f<k; f++)
                                printf("%d %d %d %d %d %d\n", s[a], s[b], s[c], s[d], s[e], s[f]);
    }
    return 0;
}