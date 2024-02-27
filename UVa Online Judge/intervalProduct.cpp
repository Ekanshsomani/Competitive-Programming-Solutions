// 12532
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class FenwickTree
{
private:
    vector<int> ft, data;
    int n;
    inline int parent(int node) {return node-(node&(-node));}
    inline int next(int node) {return node+(node&(-node));}

public:
    void insert(int val, int index)
    {
        while(index<n+1)
        {
            ft[index] += val;
            index = next(index);
        }
    }

    FenwickTree(int _n)
    {
        n = _n;
        ft.assign(n+1, 0);
        data.assign(n, 0);
    }

    FenwickTree(vector<int> &_arr)
    {
        data = _arr;
        n = data.size();
        ft.assign(n+1, 0);
        for(int i=1; i<=n; i++)
            insert(data[i-1], i);
    }

    void update(int val, int i)
    {
        int diff = val - data[i];
        data[i] = val;
        insert(diff, i+1);
    }

    int sum(int index)
    {
        index++;
        int s{0};
        while(index>0)
        {
            s += ft[index];
            index = parent(index);
        }
        return s;
    }
};


int main()
{
    int n, k;
    while(cin >> n >> k)
    {
        vector<int> arr(n);
        set<int> zeroIndex;
        for(int i=1; i<=n; i++)
        {
            int a;
            cin >> a;
            if(a>=0) arr[i-1] = 0;
            else if(a<0) arr[i-1] = 1;

            if(a==0) zeroIndex.insert(i);
        }

        FenwickTree ft(arr);

        char c;
        int a, b;
        while(k--)
        {
            cin >> c >> a >> b;
            if(c=='P')
            {
                auto lower{lower_bound(zeroIndex.begin(), zeroIndex.end(), a)};
                auto upper{upper_bound(zeroIndex.begin(), zeroIndex.end(), b)};
                if(lower!=upper || (a==b && zeroIndex.count(a))) cout << '0';
                else
                {
                    if((ft.sum(b-1)-ft.sum(a-2))%2) cout << '-';
                    else cout << '+';
                }
            }
            else
            {
                if(zeroIndex.count(a) && b!=0)
                    zeroIndex.erase(a);
                
                if(b>=0)
                    ft.update(0, a-1);
                else
                    ft.update(1, a-1);

                if(b==0 && !zeroIndex.count(a))
                    zeroIndex.insert(a);
            }
        }
        cout << endl;
    }
    return 0;
}