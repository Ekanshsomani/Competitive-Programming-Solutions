// doing sum and complex operations on arrayy segments
// in worst case log(N) instead of N;
// root-p: left-2*p, right-2*p+1
// leaf nodes ->  elements of the actual input array
// size upper bound 4n for n elements

#include <iostream>
#include <vector>
using namespace std;

// Private:
    // left
    // right
    // build
    // rmq
// public:
    // constructor
    // rmq

// rmq : Range minimum query

class MinSegmentTree {
private: 
    vector<int> st, data;
    int n;
    int left (int p) { return p << 1; }
    int right(int p) { return (p << 1) + 1; }
    void build(int p, int L, int R) 
    {
        if (L == R)
            st[p] = L;
        else 
        {
            build(left(p) , L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (data[p1] <= data[p2]) ? p1 : p2;
        }
    }

    int rmq(int p, int L, int R, int i, int j) 
    {
        if (i > R || j < L) return-1;
        if (i<=L&& j>=R) return st[p];
        
        int p1 = rmq(left(p) , L, (L+R) / 2, i, j);
        int p2 = rmq(right(p), (L+R) / 2 + 1, R, i, j);
        
        if (p1 ==-1) return p2;
        if (p2 ==-1) return p1; 
        return (data[p1] <= data[p2]) ? p1 : p2;
    }
public:
    MinSegmentTree(const vector<int> &_A) 
    {
        data = _A; n = (int)data.size();
        st.assign(4 * n, 0);
        build(1, 0, n- 1);
    }

    int rmq(int i, int j) { return rmq(1, 0, n- 1, i, j); }
};

class MaxSegmentTree {
private: 
    vector<int> st, data;
    int n;
    int left (int p) { return p << 1; }
    int right(int p) { return (p << 1) + 1; }
    void build(int p, int L, int R) 
    {
        if (L == R)
            st[p] = L;
        else 
        {
            build(left(p) , L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (data[p1] >= data[p2]) ? p1 : p2;
        }
    }

    int rmq(int p, int L, int R, int i, int j) 
    {
        if (i > R || j < L)
            return -1;

        if (L==R)
            return st[p];

        if (L >= i && R <= j && data[st[p]] <= st[p] - i + 1)
            return st[p];
        
        int p1 = rmq(left(p) , L, (L+R) >> 1, i, j);
        int p2 = rmq(right(p), ((L+R) >> 1) + 1, R, i, j);
        
        if (p1 ==-1) return p2;
        if (p2 ==-1) return p1;
        
        return (min(p1 - i + 1, data[p1]) >= min(p2 - i + 1, data[p2])) ? p1 : p2;
    }
public:
    MaxSegmentTree(int _n):n(_n), st(_n << 2), data(_n)
	{
		int frequency = 0;
		int previous = -100001;

		for(int i = 0; i < n; ++i)
		{
			int d;
			cin >> d;

			if(previous != d)
				frequency = 0;

			previous = d;
			data[i] = ++frequency;
		}

		build(1, 0, n - 1);
	}
    
    int rmq(int i, int j)
    {
        int p = rmq(1, 0, n - 1, i, j);
		return min(p - i + 1, data[p]);

    }
};

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
        return rsq(p1, i, j, L, (L+R)<<1) + rsq(p2, i, j, ((L+R)<<1)+1, R);
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
