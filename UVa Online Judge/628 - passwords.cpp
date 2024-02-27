// 628

#include <iostream>
#include <string>
using namespace std;

string dict[100];
int words, rules;
string rule;

void generatePass(int index, string pass)
{
    if(index==rule.size())
    {
        cout << pass << "\n";
        return;
    }

    if(rule[index]=='0')
        for(char i='0'; i<='9'; i++)
            generatePass(index+1, pass+i);
    else
        for(int i=0; i<words; i++)
            generatePass(index+1, pass+dict[i]);
}

int main()
{
    while(cin >> words)
    {
        for(int i=0; i<words; i++)
            cin >> dict[i];

        cout << "--\n";   
        cin >> rules;
        while(rules--)
        {
            cin >> rule;
            generatePass(0, "");
        }
    }
    return 0;
}