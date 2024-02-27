#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
    int frosh;
    while(cin >> frosh && frosh>0)
    {
        map<set<int>, int> popularity;
        while(frosh--)
        {
            set<int> combination;
            
            for(int i=0; i<5; i++)
            {
                int course;
                cin >> course;
                combination.insert(course);
                
            }

            if(popularity.count(combination)) popularity[combination]++;
            else  popularity[combination] = 1;
        }

        map<int, int> popFreq;
        for(auto it: popularity)
            (popFreq.count(it.second)) ? (popFreq[it.second]++) : (popFreq[it.second]=1);
        cout << popFreq.rbegin()->first * popFreq.rbegin()->second << endl;
    }
    return 0;
}