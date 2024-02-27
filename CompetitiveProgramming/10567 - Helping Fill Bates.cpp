#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> states[52];
char ss[101];

int main()
{
    char a;
    int index{0};
    while((a=getchar())!='\n')
    {
        if(a<'a')
            states[a-'A'+26].push_back(index);
        else
            states[a-'a'].push_back(index);
        index++;
    }

    int i, num, first, last;
    bool match;

    int q;
    cin >> q;
    while(q--)
    {
        scanf("%s", ss);

        i = 0;
        num = 0;
        match = true;
        while(ss[i]!='\0' and match)
        {
            int state;
            if(ss[i]<'a')
                state = ss[i]-'A'+26;
            else
                state = ss[i]-'a';
            auto it = lower_bound(states[state].begin(), states[state].end(), num);

            if(i==0)
                first = *it;

            if(it==states[state].end())
                match = false;
            num = *it + 1;
            i++;
        }

        if(not match)
            printf("Not matched\n");
        else
        {
            last = num-1;
            printf("Matched %d %d\n", first, last);
        }
    }

    return 0;
}