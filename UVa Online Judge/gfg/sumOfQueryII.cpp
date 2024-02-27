#include <iostream>
#include <vector>
using namespace std;

class SumSegmentTree{
private:
    vector<int> st, data;
    int n;
    int left(int p)
        {return (p<<1);}
    int right(int p)
        {return (p<<1)+1;}
    
    void build(int p, int L, int R)
    {
        if(L==R)
        {
            st[p] = data[L];
            return;
        }
        
        build(left(p), L, ((L+R)>>1));
        build(right(p), ((L+R)>>1)+1, R);
        st[p] = st[left(p)]+st[right(p)];
    }
    
    int rsq(int p, int i, int j, int L, int R)
    {
        if(i>R || j<L) return 0;
        if(i<=L && j>=R) return st[p];

        int p1 {left(p)}, p2 {right(p)};
        return rsq(p1, i, j, L, (L+R)>>1) + rsq(p2, i, j, ((L+R)>>1)+1, R);
    }
public:
    SumSegmentTree(int arr[], int _n)
    {
        n = _n;
        for(int i=0; i<n; i++) data.push_back(arr[i]);
        st.assign(4*n, 0);
        build(1, 0, n-1);
    }
    int rsq(int i, int j) {return rsq(1, i, j, 0, n-1);}
};

class Solution{
public:
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        vector<int> ans;
        SumSegmentTree st(arr, n);
        for(int i=0; i<2*q; i+=2)
            ans.push_back( st.rsq(queries[i]-1, queries[i+1]-1));
        return ans;
    }
};

