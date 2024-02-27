#include <iostream>
using namespace std;

int main()
{
    int bachelors, spinsters;
    int garbage, minAge;
    int t{1};
    while(cin >> bachelors >> spinsters and (bachelors or spinsters))
    {
        minAge = 60;

        for(int i=0; i<bachelors; i++)
        {
            cin >> garbage;
            minAge = min(minAge, garbage);
        }

        for(int i=0; i<spinsters; i++)
            cin >> garbage;

        printf("Case %d: ", t++);
        (bachelors>spinsters)?printf("%d %d\n", bachelors-spinsters, minAge):printf("0\n");
    }

    return 0;
}