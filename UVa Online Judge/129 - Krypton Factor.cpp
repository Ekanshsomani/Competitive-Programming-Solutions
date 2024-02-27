#include <iostream>
#include <string>
using namespace std;

int n, base;
int seqindex;
char allowed;

bool validString(string s)
{
    for(int sublength = 1; sublength<= s.size()/2; sublength++)
    {
        int i = s.size()-2*sublength;
        if(s.substr(i, sublength) == s.substr(i+sublength, sublength))
            return false;
    }
    return true;
}

void printString(string s)
{
    int groups{0}, length{0};
    for(int i=0; i<s.size();  i++)
    {
        if(length==4)
        {
            groups++;
            if(groups==16)
            {
                printf("\n");
                groups = 0;
            }
            else
                printf(" ");
            length = 0;
        }
        printf("%c", s[i]);
        length++;
    }
    printf("\n%d\n", s.size());
}

void backtrack(string s)
{
    seqindex++;
    if(seqindex==n)
    {
        printString(s);
        return;
    }
    else if(seqindex>n)
        return;

    for(char i='A'; i<allowed; i++)
        if(validString(s+i))
           backtrack(s+i);
    return;
}

int main()
{
    while(cin >> n >> base and n)
    {
        seqindex = 0;
        allowed = 'A'+base;

        for(char i='A'; i<allowed and seqindex<n; i++)
        {
            string s(1, i);
            backtrack(s);
        }
    }
    return 0;
}