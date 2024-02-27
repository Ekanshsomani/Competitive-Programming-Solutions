// 750

#include <iostream>
using namespace std;

int board[9] = {0};
int soln{0};
int row, col, n;

bool validPlace(int x, int y)
{
    for(int i=1; i<x; i++)
        if(board[i] == y || abs(board[i]-y) == abs(i-x)) return 0;
    return 1;
}

void printBoards(int index)
{
    if(index==n+1)
    {
        soln++;
        if(soln<10) cout << ' ';
        cout << soln << "      ";
        for(int i=1; i<8; i++)
            cout << board[i] << ' ';
        cout << board[8] << endl;
        return;
    }
    if(index==col)
    {
        if(validPlace(col, board[col]))
            printBoards(index+1);
        return;
    }

    for(int i=1; i<=8; i++)
    {
        if(validPlace(index, i))
        {
            board[index] = i;
            printBoards(index+1);
        }
    }
}

int main()
{

    

    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8" << endl;
        cout << endl;

        cin >> row >> col;

        board[col] = row;

        soln = 0;
        printBoards(1);

        if(testcases) cout << endl;
    }

    return 0;
}