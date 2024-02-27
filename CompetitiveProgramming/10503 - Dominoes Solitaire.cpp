// 10503
// n <= m <= 14;

#include <iostream>
#include <bitset>
using namespace std;

int n, m;
pair<int, int> pieces[14];
bitset<14> used;

int lt, rt;

bool backtrack(int space, int pre)
{
    if(space==n)
        if(pre==rt)
            return true;
        else 
            return false;

    bool pos = false;
    for(int i=0; i<m and not pos; i++)
        if(not used[i])
        {
            int temp;
            if(pre==pieces[i].first)
                temp = pieces[i].second;
            else if(pre==pieces[i].second)
                temp = pieces[i].first;
            else
                continue;
            
            used[i] = 1;
            pos = backtrack(space+1, temp);
            used[i] = 0;
        }
    return pos;
}

int main()
{
    int a, b;
    int ignore;
    while(cin >> n and n>0)
    {
        cin >> m;
        cin >> ignore >> lt;
        cin >> rt >> ignore;

        for(int i=0; i<m; i++)
            cin >> pieces[i].first >> pieces[i].second;

        if(backtrack(0, lt))
            printf("YES\n");
        else
            printf("NO\n");

        used.reset();
    }
    return 0;
}