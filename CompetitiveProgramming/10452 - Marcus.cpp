#include <iostream>
using namespace std;

char path[] = {'I', 'E', 'H', 'O', 'V', 'A', '#'};
char cobbles[8][8];
int width, length;
pair<int, int> pos;

void backtrack(int index)
{
    if(index==7)
        return;

    if(pos.first+1<length && cobbles[pos.first+1][pos.second]==path[index])
    {
        pos.first++;
        cout << "forth";
    }
    else if(pos.second+1<width && cobbles[pos.first][pos.second+1]==path[index])
    {
        pos.second++;
        cout << "right";
    }
    else if(pos.second-1>-1 && cobbles[pos.first][pos.second-1]==path[index])
    {
        pos.second--;
        cout << "left";
    }
    else
    {
        cout << "Something isn't right\n";
    }
    printf((index==6)?"\n":" ");
    backtrack(index+1);
    return;
}

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        cin >> length >> width;
        for(int i=length-1; i>-1; i--)
            for(int j=0; j<width; j++)
                cin >> cobbles[i][j];


        for(int i=0; i<width; i++)
            if(cobbles[0][i]=='@')
                pos = {0,i};
        
        backtrack(0);
    }
    return 0;
}