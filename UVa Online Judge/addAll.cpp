// 10954
#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    while(cin >> n && n>0)
    {
        multiset<int> nums;
        while(n--)
        {
            int a;
            cin >> a;
            nums.insert(a);
        }

        int total{0};
        while(nums.size()>1){
            int a = *nums.begin();
            int b = *next(nums.begin());
            nums.erase(nums.begin());
            nums.erase(nums.begin());
            
            int cost = a+b;
            total += cost;
            nums.insert(cost);
        }

        cout << total << endl;
    }
}