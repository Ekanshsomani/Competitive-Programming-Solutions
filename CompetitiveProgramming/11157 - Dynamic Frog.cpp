#include <iostream>
#include <vector>
using namespace std;

// The Code in comments works here but gives runtime error on onlineJudge
/*

int minimumLeap(int start, int end, vector<int> small)
{
    int maxLeap{0}, l{(int)small.size()};
    for(int i=2; i<l; i++)
        maxLeap = max(maxLeap, small[i]-small[i-2]);

    int oddStart{small[1]}, evenStart{small[0]}, oddEnd, evenEnd;

    if(l%2==0)
    {
        oddEnd = small[l-1];
        evenEnd = small[l-2];
    }
    else
    {
        oddEnd = small[l-2];
        evenEnd = small[l-1];
    }

    int a {max(max(end-oddEnd, end-evenEnd), max(oddStart-start, evenStart-start))};
    maxLeap = max(maxLeap, a);

    return maxLeap;
}
/*

int main()
{
    vector<int> big(102);
    vector<vector<int>> small(102);
    int b;
    big[0] = 0;
    
    int n, end, testcases;
    cin >> testcases;
    for(int t=1; t<=testcases; t++)
    {
        cin >> n >> end;
        
        for(int i=0; i<b; i++)
            small[i].clear();
        b = 0;

        char type, garbage;
        int distance; 
        for(int i=0; i<n; i++)
        {
            cin >> type >> garbage >> distance;

            if(type=='S')
                small[b].push_back(distance);
            else
            {
                b++;
                big[b] = distance;
            }
        }

        b++;
        big[b] = end;

        int maxLeap{0};
        for(int i=0; i<b; i++)
            if(small[i].size()<2)
                maxLeap = max(maxLeap, big[i+1]-big[i]);
            else
                maxLeap = max(maxLeap, minimumLeap(big[i], big[i+1], small[i]));

        printf("Case %d: %d\n", t, maxLeap);
    }

    return 0;
}
*/

int main()
{
    int n, d, size, minLeap;

    vector<int> stone;
    int testcases;
    cin >> testcases;
    for(int t=1; t<=testcases; t++)
    {
        cin >> n >> d;
        
        size = n+2;
        stone.clear();
        stone.push_back(0);

        for(int i=0; i<n; i++)
        {
            char type, garbage;
            int distance;
            cin >> type >> garbage >> distance;
            stone.push_back(distance);

            if(type=='B')
            {
                size++;
                stone.push_back(distance);
            }
        }

        stone.push_back(d);

        minLeap = 0;
        for(int i=2; i<size; i++)
            minLeap = max(minLeap, stone[i]-stone[i-2]);
        
        printf("Case %d: %d\n", t, minLeap);
    }
    return 0;
}