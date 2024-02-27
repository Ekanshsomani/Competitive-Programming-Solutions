#include <iostream>
#include <string>
#include <set>
using namespace std;

int a, b, n;
set<pair<int, int>> state;

int steps[20000];
string task[] = {"fill ", "empty ", "pour "};
string jug[] = {"A", "B", "A B", "B A"};

int ans[20000], minSteps{20000};

void backtrack(int x, int y, int index)
{

    if(state.count({x, y}) or index >= minSteps)
        return;
    if(y==n)
    {
        minSteps = index;
        for(int i=0; i<index; i++)
            ans[i] = steps[i];
        return;
    }

    state.insert({x,y});

    steps[index] = 0;
    steps[index+1] = 0;
    backtrack(a, y, index+2);

    steps[index] = 0;
    steps[index+1] = 1;
    backtrack(x, b, index+2);

    steps[index] = 1;
    steps[index+1] = 0;
    backtrack(0, y, index+2);

    steps[index] = 1;
    steps[index+1] = 1;
    backtrack(x, 0, index+2);

    steps[index] = 2;
    steps[index+1] = 2;
    ((x+y)>b)?backtrack(x+y-b, b, index+2):backtrack(0, y+x, index+2);

    steps[index] = 2;
    steps[index+1] = 3;
    ((x+y)>a)?backtrack(a, x+y-a, index+2):backtrack(x+y, 0, index+2);

    state.erase({x, y});
}

int main()
{
    while(cin >> a)
    {
        cin >> b >> n;
        minSteps = 20000;
        state.clear();

        backtrack(0, 0, 0);

        for(int i=0; i<minSteps; i+=2)
        {
            cout << task[ans[i]] << jug[ans[i+1]] << endl;
        }
        cout << "success" << endl;
    }
    return 0;
}