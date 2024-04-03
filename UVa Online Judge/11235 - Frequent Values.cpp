// 11235
// record frequency, then use maxSegmentTree to answer range max query

#include <iostream>
#include <vector>
using namespace std;

// SegmentTree modified for max query
class SegmentTree {
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
    SegmentTree(int _n):n(_n), st(_n << 2), data(_n)
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

int main()
{
    int n, q;
    while(cin >> n >> q && n>0)
    {
        SegmentTree freqs(n);

        while(q--)
        {
            int i, j;
            cin >> i >> j;
            cout << freqs.rmq(i-1, j-1) << endl;
        }
    }
}