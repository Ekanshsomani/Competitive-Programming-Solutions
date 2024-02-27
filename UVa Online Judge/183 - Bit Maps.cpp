#include <iostream>
#include <bitset>
using namespace std;

bitset<200> bMap[200];
string dMap;
int dIndex;

// Converting and printing from B to D.

inline int all(int r, int c, int length, int breadth)
{
    int prevBit = bMap[r][c];
    for(int i=r; i<r+breadth; i++)
        for(int j=c; j<c+length; j++)
            if(bMap[i][j]!=prevBit)
                return -1;
    return prevBit;
}

string btod(int r, int c, int length, int breadth)
{

    int val{all(r,c,length, breadth)};
    if(val==1) return "1";
    else if(val==0) return "0";
    else
    {
        int nl{((length%2==0) ? (length>>1) : ((length>>1)+1))};
        int nb{((breadth%2==0) ? (breadth>>1) : ((breadth>>1)+1))};

        if(breadth==1)
            return("D" + 
            btod(r, c, nl, breadth) + btod(r, c+nl, length>>1, breadth)
            );
        if(length==1)
            return("D" +
            btod(r, c, length, nb) + btod(r+nb, c, length, breadth>>1)
            );

        return ( "D"+
            btod(r, c, nl, nb) + btod(r, c+nl,  length>>1, nb) +
            btod(r+nb, c, nl, (breadth>>1)) + btod(r+nb, c+nl, length>>1, breadth>>1)
        );
    }
}

inline void printDMap(int column, int row)
{
    string s{btod(0, 0, column, row)};

    int num{0};
    for(auto it: s)
    {
        if(num==50)
        {
            printf("\n");
            num = 0;
        }
        num++;
        printf("%c",it);
    }
    printf("\n");
}

// Converting and Printing from D to B.

inline void setAll(int r, int c, int length, int breadth)
{
    bool setBit = dMap[dIndex]-'0';
    for(int i=r; i<r+breadth; i++)
        for(int j=c; j<c+length; j++)
            bMap[i][j] = setBit;
    return;
}

void dtob(int r, int c, int length, int breadth)
{
    if(dMap[dIndex]!='D')
    {
        setAll(r, c, length, breadth);
        dIndex++;
        return;
    }

    int nl{((length%2==0) ? (length>>1) : ((length>>1)+1))};
    int nb{((breadth%2==0) ? (breadth>>1) : ((breadth>>1)+1))};
    dIndex++;

    if(breadth==1)
    {
        dtob(r, c, nl, breadth);
        dtob(r, c+nl, length>>1, breadth);
        return;
    }
    if(length==1)
    {
        dtob(r, c, length, nb); 
        dtob(r+nb, c, length, breadth>>1);
        return;
    }
    dtob(r, c, nl, nb);
    dtob(r, c+nl,  length>>1, nb);
    dtob(r+nb, c, nl, (breadth>>1));
    dtob(r+nb, c+nl, length>>1, breadth>>1);
    return;
}

inline void printBMap(int column, int row)
{
    dtob(0, 0, column, row);
    int num{0};
    for(int i=0; i<row; i++)
        for(int j=0; j<column; j++)
        {
            if(num==50)
            {
                printf("\n");
                num = 0;
            }
            num++;
            cout << bMap[i][j];
        }
    printf("\n");
}

int main()
{
    char a;
    while(cin >> a and a!='#')
    {
        int row, column;
        cin >> row >> column;

        if(a=='B')
        {
            char b;
            for(int i=0; i<row; i++)
                for(int j=0; j<column; j++)
                {
                    cin >> b;
                    bMap[i][j] = b-'0';
                }
            
            printf("D%4d%4d\n", row, column);
            printDMap(column, row);
        }
        else if(a=='D')
        {
            cin >> dMap;
            dIndex = 0;

            printf("B%4d%4d\n", row, column);
            printBMap(column, row);
        }
    }
    return 0;
}