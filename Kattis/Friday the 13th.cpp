#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int year, months;
        cin >> year >> months;

        int occurrence{1}, firstDay{0};
        while(months--)
        {
            int days;
            cin >> days;
            firstDay = (firstDay+days)%7;
            if(firstDay == 0)
                occurrence++;
        }
        printf("%d\n", occurrence);
    }
    return 0;
}