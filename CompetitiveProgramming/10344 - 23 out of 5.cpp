#include <iostream>
using namespace std;

int arr[5], expr[9];
bool vis[5], pos;

// -2 = +, -1 = -, 0 = *

inline int calculate()
{
    int s {expr[0]};
    for(int i=1; i<9; i+=2)
    {
        switch (expr[i])
        {
        case (-2):
            s+=expr[i+1];
            break;
        case (-1):
            s-=expr[i+1];
            break;
        case (0):
            s*=expr[i+1];
            break;
        default:
            break;
        }
    }
    return s;
}

void backtrack(int index)
{
    if(pos)
        return;
    
    if(index == 8)
    {
        for(int i=0; i<5; i++)
            if(!vis[i])
            {
                expr[8] = arr[i];
                if(calculate()==23)
                    pos=true;
            }
        return;
    }

    for(int i=0; i<5; i++)
        if(!vis[i])
        {
            vis[i] = 1;
            expr[index] = arr[i];
            for(int j=-2; j<1; j++)
            {
                expr[index+1] = j;
                backtrack(index+2);
            }
            vis[i] = 0;

            if(pos)
                return;
        }
    return;
}

int main()
{
    while(cin >> arr[0] and arr[0]>0)
    {
        for(int i=1; i<5; i++)
            cin >> arr[i];

        pos = false;
        backtrack(0);
        if(pos)
            cout << "Possible" << endl;
        else
            cout << "Impossible" << endl;
        
    }
    return 0;
}