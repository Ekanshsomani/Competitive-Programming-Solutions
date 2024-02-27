#include <iostream>
#include <array>
using namespace std;

int n, m, l;
// n -> Train Capacity
// m -> 0 (start) to m(end) stations
// l -> number of orders
// max orders: 22

int trainState[7] = {0};
array<int,3> arr[22];

int maxProfit{0};

void changeState(int start, int end, int val)
{
    for(int i=start; i<end; i++)
        trainState[i] += val;
    return;
}

bool checkState(int start, int end, int val)
{
    for(int i=start; i<end; i++)
        if(trainState[i]>val) return false;
    return true;
}

void backtrack(int index, int profit)
{
    if(index==l)
    {
        maxProfit = max(maxProfit, profit);
        return;
    }

    array<int, 3> order = arr[index];
    if(checkState(order[0], order[1], n-order[2]))
    {
        changeState(order[0], order[1], order[2]);
        backtrack(index+1, profit + order[2]*(order[1]-order[0]));
        changeState(order[0], order[1], -order[2]);
    }
    backtrack(index+1, profit);
}

int main()
{
    while(cin >> n >> m >> l and n>0)
    {
        for(int i=0; i<l; i++)
            cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        maxProfit = 0;
        backtrack(0, 0);

        cout << maxProfit << endl;
    }
    return 0;
}