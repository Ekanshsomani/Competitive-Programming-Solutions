// 11849
#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    int jack, jill;
    while(cin >> jack >> jill && (jack>0 || jill >0))
    {
        unordered_set<int> cd;
        
        while(jack--)
        {
            int id;
            cin >> id;
            cd.insert(id);
        }

        int total = 0;
        while(jill--)
        {
            int id;
            cin >> id;
            if(cd.count(id)) total++;
        }
        cout << total << endl;
    }
}