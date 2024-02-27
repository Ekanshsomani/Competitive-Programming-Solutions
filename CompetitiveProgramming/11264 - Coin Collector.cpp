#include <iostream>
using namespace std;

int main()
{

    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int n;
        cin >> n;

        int sum{0}, previous{0}, coins{0}, value;
        for(int i=0; i<n; i++)
        {
            cin >> value;
            if((sum+previous)<value)
            {
                coins++;
                sum += previous;
            }
            previous = value;
        }

        printf("%d\n", coins);
    }
    return 0;
}