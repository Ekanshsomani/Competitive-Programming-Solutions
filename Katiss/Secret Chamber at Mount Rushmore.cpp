#include <bits/stdc++.h>

using namespace std;

bool am[26][26];

inline bool compare(string &a, string &b)
{
    int l = a.size();
    if(l != b.size()) return false;

    for(int i=0; i<l; i++)
    {
        int u = a[i]-'a';
        int v = b[i]-'a';
        if(not am[u][v])
            return false;
    }
    return true;
}

int main()
{
    for(int u=0; u<26; u++)
    {
        for(int v=0; v<26; v++)
            am[u][v] = false;
        am[u][u] = true;
    }

    int E, queries;
    cin >> E >> queries;
    while(E--)
    {
        char u, v;
        cin >> u >> v;
        am[u-'a'][v-'a'] = true;
    }

    for(int k=0; k<26; k++)
        for(int u=0; u<26; u++)
            for(int v=0; v<26; v++)
                am[u][v] |= am[u][k] & am[k][v];
    
    while(queries--)
    {
        string a, b;
        cin >> a >> b;
        if(compare(a, b)) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}