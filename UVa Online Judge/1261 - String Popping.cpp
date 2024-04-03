#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> memo;

bool canEmpty(string in)
{
    if(in.empty()) return true;
    if(memo.count(in)) return memo[in];

    int i{0};
    while(i<in.size())
    {
        int j{i};
        while(in[j]==in[i])
            j++;

        if(j>(i+1) and canEmpty(in.substr(0, i)+in.substr(j)))
            return memo[in] = true;
            
        i = j;
    }
    return memo[in] = false;
}

int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        string s;
        cin >> s;

        if(canEmpty(s)) printf("1\n");
        else printf("0\n");
    }
    
    return 0;
}