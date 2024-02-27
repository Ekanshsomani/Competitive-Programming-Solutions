#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int testCases;
    cin >> testCases;
    while(testCases--)
    {
        int ferryLength, cars;
        cin >> ferryLength >> cars;
        ferryLength *= 100;

        vector<stack<int>> sides(2);
        vector<int> length(cars);

        for(int i=0; i<cars; i++)
        {
            int cl;
            string bank;
            cin >> cl >> bank;
            ( (bank[0]=='l') ? sides[0] : sides[1]).push(i);
            length[i] = cl;
            /*
            if(bank[0]=='l') sides[0].push(i);
            else sides[1].push(i);
            /**/
        }

        int bank {0}, crosses {0};

        while(!(sides[0].empty()&&sides[1].empty())){
            int occLength{0};
            while(!sides[bank].empty() && occLength<ferryLength-length[sides[bank].front()])
            {
                occLength += length[sides[bank].front()];
                sides[bank].pop();
            }
            bank = (bank+1)%2;
            crosses++;
        }

        cout << crosses << endl;
    }
    return 0;
}