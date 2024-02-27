#include <iostream>
#include <iomanip>
using namespace std;


int board[9] = {0};
int scoreBoard[9][9];

bool validPlace(int x, int y)
{
    for(int i=1; i<x; i++)
        if(board[i] == y || abs(board[i]-y) == abs(i-x)) return 0;
    return 1;
}

int getScore(int index)
{
    if(index==9)
        return 0;

    int maxScore{0};
    for(int i=1; i<=8; i++)
        if(validPlace(index, i))
        {
            board[index] = i;
            maxScore = max(scoreBoard[i][index] + getScore(index+1), maxScore);
        }
    
    return maxScore;
}

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        for(int i=1; i<=8; i++)
            for(int j=1; j<=8; j++)
                cin >> scoreBoard[i][j];

        cout << right << setw(5) << getScore(1) << "\n";
    }
    return 0;
}