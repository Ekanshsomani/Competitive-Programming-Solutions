// UVa 11085

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// Preprocess code;

// Preprocess 1: Generate All Possible Outcomes
/*
int colPos[9];

bool validPlace(int row, int col)
{
    for(int i=1; i<col; i++)
        if(colPos[i]==row || abs(i-col)==abs(colPos[i]-row)) return false;
    return true;
}

void backtrack(int index)
{
    if(index==9)
    {
        for(int i=1; i<=8; i++)
            cout << colPos[i] << ' ';
        cout << endl;
        return;
    }

    for(int i=1; i<=8; i++)
        if(validPlace(i, index))
        {
            colPos[index]=i;
            backtrack(index+1);
        }

}
/**/

// Preprocess 2: Check for uniqueness
/*
vector<queue<int>> uniqueBoards;
queue<int> q;

void getUnique()
{
    int t=92;
    while(t--)
    {
        
        for(int i=0; i<8; i++)
        {
            int a;
            cin >> a;
            q.push(a);
        }

        bool unique{true};
        for(int i=0; i<8 && unique; i++)
        {
            q.push(q.front());
            q.pop();
            for(const auto& it: uniqueBoards)
                if(q==it) 
                {
                    unique = false;
                    break;
                }
        }

        if(unique) uniqueBoards.push_back(q);

        q = queue<int>();
    }

    for(auto it: uniqueBoards)
    {
        while(!it.empty())
        {
            cout << it.front() << ' ';
            q.pop();
        }
        cout << endl;
    }
}

/**/



int main()
{
    
    
    return 0;
}