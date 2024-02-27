// 11742

#include <iostream>
#include <algorithm>
using namespace std;

int p[8];

int find(int num)
{
    for(int i=0; i<8; i++)
        if(p[i]==num)
            return i;
    return -1;
}

int main()
{
    int n, m;
    while(cin >> n >> m && n)
    {
        int c[3*m];

        for(int i=0; i<3*m; i+=3)
            cin >> c[i+1] >> c[i+2] >> c[i];
        
        for(int i=0; i<n; i++) p[i] = i;

        int a{0};
        do{
            
            bool s{1};
            for(int i=0; (i<3*m)&&s; i+= 3)
                if(c[i]>=0 && abs(find(c[i+2])-find(c[i+1]))>c[i])
                    s = 0;
                else if(c[i]<0 && abs(find(c[i+2])-find(c[i+1]))<abs(c[i]))
                    s = 0;
            if(s) a++;

        }while(next_permutation(p, p+n));

        cout << a << endl;
    }
    return 0;
}