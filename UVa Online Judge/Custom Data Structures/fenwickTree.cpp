/*
- A Fenwick tree or binary indexed tree is a data structure providing efficient methods
for calculation and manipulation of the prefix sums of a table of values.
 
- Space complexity for fenwick tree is O(n)
- Time complexity to create fenwick tree is O(nlogn)
- Time complexity to update value is O(logn)
- Time complexity to get prefix sum is O(logn)


- stores dynamic cumulative frequency
- stored in an array but the abstract rep is a tree

- for n-element array we have n+1 element fenwick tree
- 0 is a dummy node
- binary representation of the index number is used to deteremine 
which element's sum will be stored here.
- flip the first significant bit of an index number to get its parent

- Get Parent:
    - Get 2's complement of a number
    - AND with original number
    - Subtract from original number

- Get NEXT while updating (you will have to add the update these all):
    - 2's Complement of the number
    - AND with original number
    - ADD to original number

- 
*/

#include <vector>
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
        int s{0};
        while(index>0)
        {
            s += ft[index];
            index = parent(index);
        }
        return s;
    }
};