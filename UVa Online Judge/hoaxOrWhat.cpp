// 11136

#include <iostream>
#include <set>
using namespace std;

int main()
{
    

    int days;
    while(cin >> days && days>0)
    {
        multiset<unsigned int> urn;
        unsigned long total{0};
        while(days--)
        {
            unsigned int bills;
            cin >> bills;

            while(bills--)
            {
                unsigned int amt;
                cin >> amt;
                urn.insert(amt);
            }

            total += *(urn.rbegin())-*(urn.begin());
            urn.erase(prev(urn.end()));
            urn.erase(urn.begin());
        }
        
        cout << total << endl;
    }
    return 0;
}