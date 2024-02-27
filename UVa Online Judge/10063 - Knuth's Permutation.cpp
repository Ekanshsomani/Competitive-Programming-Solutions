#include <iostream>
#include <list>
#include <string>
using namespace std;

list<char> per;
string s;

void backtrack(int index)
{
    if(index==s.size())
    {
        for(auto it: per)
            cout << it;
        cout << endl;
        return;
    }
    
    for(auto it = per.begin(); it!=per.end(); it++)
    {
        per.insert(it, s[index]);
        backtrack(index+1);
        it = per.erase(prev(it));
    }

    per.push_back(s[index]);
    backtrack(index+1);
    per.pop_back();
}

int main()
{
    int t{0};
    while(cin >> s)
    {
        if(t++) cout << endl;
        
        backtrack(0);

        
        per.clear();
    }
    return 0;
}