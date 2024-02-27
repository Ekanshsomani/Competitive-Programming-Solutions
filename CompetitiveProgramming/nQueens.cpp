// 11195
// We trade in more space for less time in this prob.
// How:
    // It is posssible to label all diagonals on the chess board (just like we do with rows)
    // r+c & r-c can give us those labels
    // add n-1 to r-c so that it can't get negative
    // 2n-1 left diagonals and 2n-1 right diagonals
// n<15

#include <iostream>
#include <vector>
using namespace std;

int ans{0};
int n, ok;
vector<int> colBits; // stores the bits for each column in int form (each bit indicates a row)

void countAns(int rw, int rd, int ld, int col)
{
    if(rw == ok) {ans++; return;}

    int pos = ok & (~(rw | rd | ld));
    while(pos)
    {
        int p = pos & -pos;
        pos -= p;
        if(colBits[col] & p) continue;
        countAns(rw|p, (rd|p)<<1, (ld|p)>>1, col+1);
    }
}

int main()
{
    int t{1};
    while(scanf("%d",&n),n)
    {
        colBits.assign(n, 0);
        ok = (1<<n)-1;
        ans = 0;

        char c;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                cin >> c;
                if(c=='*') colBits[j] = (colBits[j]<<1)+1;
                else colBits[j] = colBits[j]<<1;
            }

        countAns(0,0,0,0);
        printf("Case %d: %d\n", t++, ans);

    }
    return 0;
}