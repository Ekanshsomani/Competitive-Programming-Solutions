// 10576

#include <iostream>
using namespace std;

int report[12];
int s, d;

bool verifyPostings()
{
    for(int i=0; i<8; i++)
        if(report[i]+report[i+1]+report[i+2]+report[i+3]+report[i+4]>=0) 
            return false;
    return true;
}

int backtrack(int i)
{
    if(i==12 && verifyPostings())
    {
        int sum{0};
        for(auto it: report) sum += it;
        if(sum>=0)
            return sum;
        else return -1;
    }
    else if(i>=12)
        return -1;

    report[i] = s;
    int a{backtrack(i+1)};
    report[i] = -d;
    int b{backtrack(i+1)};

    return max(a, b);
}

int main()
{
    while(cin >> s >> d)
    {
        int a{backtrack(0)};
        if(a==-1) cout << "Deficit";
        else cout << a;
        cout << endl;
    }
    return 0;
}
