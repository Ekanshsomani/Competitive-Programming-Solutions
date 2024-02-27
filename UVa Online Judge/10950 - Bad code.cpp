// 10950

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

pair<char, string> code[100];
int printed, n;
string encrypted;

// code for each character [1,99]
// a code may or may not be preceded by 0 in encypted string

void backtrack(int index, string decrypted)
{
    if(printed>=100)
        return;
    if(index==encrypted.size())
    {
        printed++;
        cout << decrypted << endl;
        return;
    }
    
    if((encrypted[index]) == '0' and (index != (encrypted.size()-1)))
        backtrack(index+1, decrypted);

    for(int i=0; i<n; i++)
    {
        pair<char, string> it = code[i];
        if(index==(encrypted.size()-1) and it.second.size()==2)
            continue;
        if(index==(encrypted.size()-2) and encrypted[index+1]=='0' and it.second.size()==1)
            continue;
        if(it.second == encrypted.substr(index, it.second.size()))
        {
            backtrack(index+it.second.size(), decrypted+it.first);
        }
    }

    return;
}

int main()
{
    int t{1};
    while(cin >> n and n>0)
    {
        printed = 0;

        for(int i=0; i<n; i++)
            cin >> code[i].first >> code[i].second;
        
        sort(code, code+n);
        cin >> encrypted;

        cout << "Case #" << t++ << endl;
        backtrack(0, "");
        cout << endl;
    }
    return 0;
}