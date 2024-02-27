#include <iostream>
#include <bitset>
using namespace std;

string digits[10]{
    "YYYYYYN", "NYYNNNN", "YYNYYNY",
    "YYYYNNY", "NYYNNYY", "YNYYNYY", 
    "YNYYYYY", "YYYNNNN", "YYYYYYY",
    "YYYYNYY"};
bitset<7> burned;

int n;
string countdown[10];
bool match;

void backtrack(int index, int num)
{
    if(index==n)
    {
        match = true;
        return;
    }
    
    if(match)
        return;

    string b = digits[num];
    string a = countdown[index];

    if(a.size()!=7)
        return;
        
    for(int i=0; i<7; i++)
        if(burned[i] and a[i]=='Y')
            return;

    for(int i=0; i<7; i++)
        if(a[i]!=b[i])
            if(b[i]=='N')
                return;
            else
            {
                burned[i]=1;
                a[i] = 'Y';
            }
    
    backtrack(index+1, num-1);
    return;
}

int main()
{
    while(cin >> n and n)
    {
        for(int i=0; i<n; i++)
            cin >> countdown[i];

        match = false;
        for(int i=n-1; i<10 and not match; i++)
        {
            burned.reset();
            backtrack(0, i);
        }

        if(match)
            printf("MATCH\n");
        else
            printf("MISMATCH\n");
    }
    return 0;
}