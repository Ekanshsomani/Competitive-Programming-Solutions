// 11402

#include <iostream>
#include <bitset>
#include <bit>
#include <vector>
#include <string>
using namespace std;

class SegmentTree{
private:
    bitset<4*1024000> st, isSet;
    vector<pair<bool, bool>> lazy;
    string data;
    int n;

    // in st nodes:
        // 0 -> Buccaneer Pirates
        // 1 -> Barbary Pirates
    // lazy:
        // 00 -> DoNothing
        // 01 -> Inverse st
        // 10 -> St to 0
        // 11 -> St to 1

    inline int left(int p) {return (p<<1);}
    inline int right(int p) {return  (p<<1)+1;}
    inline void setNode(int node)
    {
        int p1 {left(node)},p2{right(node)};
        st[node] = (st[p1] == st[p2] && isSet[p1] && isSet[p2]) ? st[p1] : 0;
        isSet[node] =  (st[p1] == st[p2] && isSet[p1] && isSet[p2]);
    }
    void build(int p,  int l, int r)
    {
        // set value from data if leaf node
        // else recurse on left and right childs to get there val
        // then setNode
        if(l==r)
        {
            st[p] = data[l]-'0';
            isSet[p] = 1;
            return;
        }

        build(left(p), l, (l+r)>>1);
        build(right(p), ((l+r)>>1)+1, r);
        setNode(p);
    }
    
    void updateLazy(int node)
    {
        // set lazy for left and right child
        // now if we don't need to inverse value
            // then set value for node and make isSet 1
        // if we need to inverse value and our node isSet
        // simply flip the switch
        // else  updateLazy for left and right child
        //  then set node; 
        lazy[left(node)] = lazy[node];
        lazy[right(node)] = lazy[node];

        if(lazy[node].first)
        {
            st[node] = lazy[node].second;
            isSet[node] = 1;
        }
        else if(isSet[node])
            st.flip(node);
        else
        {
            updateLazy(left(node));
            updateLazy(right(node));
            setNode(node);
        }
        lazy[node] = {0,0};
    }
    
    void updateRange(int node, int i, int j, int l, int r, pair<bool, bool> val)
    {
        // updateLazy if lazy[node]!=00 
        // check if i>r or j<l -> return 0;
        // check if leaf node between i,j
        // check if i<=l & j>=r 
            // mark child in lazy (confirm have to do) 
            // if node is not set and we have to inverse
                // update the children
            // if we don't have to inverse
                // simply set the node
            // if we have to inverse but the node is set
                // simply flip the node
        // if none of the above happened
            // pass the range onto children
            // set current node again
        if(!(!lazy[node].first&&!lazy[node].second)) 
            updateLazy(node);
        if(i>r || j<l) return;
        if(l==r && l>=i && l<=j)
        {
            if(val.first)
                st[node] = val.second;
            else
                st[node].flip();        
            return;
        }
        if(i<=l && j>=r)
        {
            lazy[left(node)] = val;
            lazy[right(node)] = val;
            if(!val.first && !isSet[node])
            {
                updateLazy(left(node));
                updateLazy(right(node));
                setNode(node);
            }
            else if(val.first)
            {
                st[node] = val.second;
                isSet[node] = 1;
            }
            else
                st[node].flip();        
            return;
        }

        updateRange(left(node), i, j, l, (l+r)>>1, val);
        updateRange(right(node), i, j, ((l+r)>>1)+1, r, val);
        setNode(node);
    }

    int queryRange(int node, int i, int j,  int l,  int r)
    {
        // updateLazy if lazy[node]!=00
        // if the segment is out range
            // return 0;
        // if leaf node
            // return 1 if its 1 else 0.
        // if the segment is completely inside range and the segment is set, return length of segment
        // return the sum of childs otherwise

        if(lazy[node].first || lazy[node].second) updateLazy(node);
        if(i>r || j<l) return 0;
        if(l==r) return st[node]?1:0;
        if(i<=l && j>=r && isSet[node]) return st[node]?(l-r+1):0;

        return 
        queryRange(left(node), i, j, l, (l+r)>>1) +
        queryRange(right(node), i, j, ((l+r)>>1)+1, r);
    }

    void printData(int node, int l, int r)
    {
        // print the segment if its set (leaf node is set by default)
        // print left and right children if its not set
        if(isSet[node])
        {
            for(int i=l; i<=r; i++)
                cout << st[node];
            return;
        }
        printData(left(node), l, (l+r)>>1);
        printData(right(node), ((l+r)>>1)+1, r);
    }

public:
    SegmentTree(string pirates)
    {
        n = pirates.size();
        data = pirates;
        lazy.assign(4*n, {0, 0});
        build(1, 0, n-1);
    }

    void updateRangeBuccaneer(int i, int j)
        {updateRange(1, i, j, 0, n-1, {1, 1}); printData(1, 0, n-1);}
    
    void updateRangeBarbary(int i, int j)
        {updateRange(1, i, j, 0, n-1, {1, 0}); printData(1, 0, n-1);}

    void updateRangeInverse(int i, int j)
        {updateRange(1, i, j, 0, n-1, {0, 1}); printData(1, 0, n-1);}

    int godsQuery(int i, int j)
    {
        //cout << "Went into gods query for i,j: " << i << ',' << j << endl;
        return queryRange(1, i, j, 0, n-1);
    }
};

int main()
{
    int testcases;
    cin >> testcases;
    for(int i=1; i<=testcases; i++)
    {
        string pirates;

        int insets;
        cin >> insets;
        while(insets--)
        {
            int repeat;
            cin >> repeat;
            cin.ignore();

            string s;
            cin >> s;

            while(repeat--) pirates += s;
        }

        SegmentTree st(pirates);

        int gq{0};
        cout << "Case " << i << ':' << endl;

        int queries;
        cin >> queries;
        while(queries--)
        {
            int a, b;
            char type;
            cin >> type >> a >> b;

            cout << "modified values for type,a,b: " << type << ',' << a << ',' << b << ": ";

            if(type=='F')
                st.updateRangeBuccaneer(a, b);
            else if(type=='E')
                st.updateRangeBarbary(a, b);
            else if(type=='I')
                st.updateRangeInverse(a, b);
            else if(type=='S')
            {
                gq++;
                cout << 'Q' << gq  << ": " << st.godsQuery(a, b) << endl;
            }
            cout << endl;
        }
    }
    return 0;
}