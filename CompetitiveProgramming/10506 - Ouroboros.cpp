// 10506
// n, m;

#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
#include <bitset>
using namespace std;

int length, base;
set<string> permutations;
bitset<65536> vis;

void createString(string s)
{
    if(s.length() == length)
    {
        permutations.emplace_hint(permutations.end(), s);
        return;
    }

    for(int i=0; i<base; i++)
    {
        char temp = '0'+i;
        createString(s+temp);
    }
    return;
}

bool valid(string ob)
{
    string s;
    bitset<65536> used;
    for(int i=0; i<ob.size(); i++)
    {
        
        if(i<=(ob.size()-length)) 
            s = ob.substr(i, length);
        else
            s = ob.substr(i) + ob.substr(0, length+i-ob.size());

        // cout << ob << ": " << s << endl;
        int index = distance(permutations.begin(), permutations.find(s));

        if(used[index])
        {
            //cout << "returning false for ob, i,index,s:" << ob << ", " << i << ", " << index << ", " << s << endl;
            return false;
        }
        used[index] = 1;
    }
    return true;
}

bool backtrack(string ob)
{
    if(ob.size()<length)
        for(char i='0'; i<(base+'0'); i++)
            backtrack(ob+i);

    if(not valid(ob))
    {
        cout << "Invalid for: " << ob << endl;
        return false;
    }
    if(vis.count() == permutations.size())
    {
        cout << ob << endl;
        return true;
    }



    for(char i='0'; i<(base+'0'); i++)
    {
        string s = ob.substr(ob.size()-length+1) + i;
        int index = distance(permutations.begin(), permutations.find(s));
        cout << "ob: " << ob << " vis[index]: " << vis[index] << " for s: " << s << endl;
        if(not vis[index])
        {
            vis[index].flip();
            if(backtrack(ob+i)) return true;
            vis[index].flip();
        }
    }
    return false;
}

int main()
{
    
    while(cin >> length)
    {
        cin >> base;
        
        createString("");
        string ob{""};

        /*
        for(char i = '0'; i<(1+'0'); i++)
        {   string s{""};
            for(int j=0; j<length; j++)
                s += i;
            vis[distance(permutations.begin(), permutations.find(s))] = 1;
            ob +=s;
        }
        /**/

        backtrack(ob);
        /*
        cout << validob("1111000010100110") << endl;
        cout << validob("000111222121102202101201002") << endl;
        /**/
        permutations.clear();
    }
    return 0;
}