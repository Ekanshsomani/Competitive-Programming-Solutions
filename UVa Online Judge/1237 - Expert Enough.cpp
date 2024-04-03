// 1237

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int d;
        cin >> d;

        vector<string> maker(d);
        vector<int> lowest(d), highest(d);

        for(int i=0; i<d; i++) cin >>  maker[i] >> lowest[i] >> highest[i];

        int q;
        cin >> q;
        while(q--)
        {
            int p;
            cin >> p;

            int found{0};
            int index;
            for(int i=0; i<d; i++)
            {
                if(p>=lowest[i] && p<=highest[i])
                {
                    if(found)
                    {
                        found++;
                        break;
                    }
                    found = 1;
                    index = i;
                }
            }

            if(found == 1) cout << maker[index] <<  endl;
            else cout << "UNDETERMINED" << endl;
        }
        if(t) cout << endl;
    }
    return 0;
}