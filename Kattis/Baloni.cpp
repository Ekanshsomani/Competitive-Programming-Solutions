#include <bits/stdc++.h>

using namespace std;

int flying[1000001];

int main()
{
    int n;
    cin >> n;

    int arrows{0};
    memset(flying, 0, sizeof flying);
    while(n--)
    {
        int h;
        cin >> h;
        if(flying[h]==0)
        {
            arrows++;
            flying[h]++;
        }

        flying[h]--;
        flying[h-1]++;
    }

    printf("%d\n", arrows);
    return 0;
}