#include <iostream>
#include <cmath>
using namespace std;

int n, used;
int pegs[50];

int backtrack(int ball)
{
    for(int i=0; i<used; i++)
    {
        int a = sqrt(pegs[i]+ball); // log(n) time complexity;
        if(a*a == (pegs[i]+ball))
        {
            pegs[i]=ball;
            return backtrack(ball+1);
        }
    }

    if(used<n)
    {
        pegs[used] = ball;
        used++;
        return backtrack(ball+1);
    }

    if(used==n)
        return ball-1;

    return -1;
}

int main()
{
    int testcases;
    cin >>  testcases;
    while(testcases--)
    {
        cin >> n;
        used = 0;
        cout << backtrack(1) << endl;
    }
    return 0;
}