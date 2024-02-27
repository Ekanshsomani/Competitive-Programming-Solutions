// 1260

#include <iostream>
#include <set>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        multiset<int> s;
        int sum{0};

        int n;
        cin >> n;

        int t{0};
        while(n--){
            int num;
            cin >> num;

            if(t++) sum += distance(s.begin(), s.lower_bound(num+1));
            s.insert(num);
        }

        cout << sum << endl;
    }
    return 0;
}