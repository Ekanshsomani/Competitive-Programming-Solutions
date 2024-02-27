// 10226

#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    cout << fixed;
    cout << setprecision(4);

    int testCases;
    cin >> testCases;
    cin.ignore();
    cin.ignore();

    while(testCases--)
    {
        map<string,  int> population;
        int total{0};

        string line;
        while(getline(cin, line) && line.length()>0) 
        {
            population.count(line) ? (++population[line]) : (population[line]=1);
            total++;
        }

        for(auto it:  population)
        {
            float percent;
            percent = (100.0 * ((float)it.second))/total;
            cout << it.first << ' ' << percent << endl;
        }

        if(testCases) cout << endl;
    }
    return 0;
}