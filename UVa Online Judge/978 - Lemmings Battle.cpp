// 978

#include <iostream>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

int main()
{
    int testCases;
    cin >> testCases;
    while(testCases--)
    {
        int battlefields, sgreen, sblue;
        cin >> battlefields >> sgreen >> sblue;

        multiset<int, greater<int>> blue, green;
        
        int power;
        for(int i=0; i<sgreen; i++)
        {
            cin >> power;
            green.insert(power);
        }

        for(int i=0; i<sblue; i++)
        {
            cin >> power;
            blue.insert(power);
        }

        while(!(blue.empty() || green.empty()))
        {
            stack<int> surGreen, surBlue;
            battlefields = min({battlefields, (int)blue.size(), (int)green.size()});

            for(int i=0; i< battlefields; i++)
            {
                int blem = *blue.begin();
                int glem = *green.begin();

                blue.erase(blue.begin());
                green.erase(green.begin());

                if(blem>glem)
                {
                    blem -= glem;
                    surBlue.push(blem);
                }
                else if(glem>blem)
                {
                    glem -= blem;
                    surGreen.push(glem);
                }
            }

            while(!surGreen.empty()) 
            {
                green.insert(surGreen.top());
                surGreen.pop();
            }

            while(!surBlue.empty())
            {
                blue.insert(surBlue.top());
                surBlue.pop();
            }
        }

        if(green.empty() && blue.empty())
        {
            cout << "green and blue died" << endl;
        }
        else if(green.empty())
        {
            cout << "blue wins" << endl;
            for(auto it: blue) cout << it << endl;
        }
        else if(blue.empty())
        {
            cout << "green wins" << endl;
            for(auto it: green) cout << it << endl;
        }

        if(testCases) cout << endl;
    }
    return 0;
}