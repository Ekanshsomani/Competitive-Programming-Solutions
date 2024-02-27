// 574

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi s;
int t, n, arr[20];
bool solution;
map<vi, bool> found;

void backtrack(int size, int index, int sum)
{
    if(sum==t)
    {
        if(found[s])
            return;

        solution = true;
        found[s] = true;

        for(int i=0; i<size; i++)
            cout << s[i] << ((i+1==size)?"\n":"+");
        return;
    }

    if(t<sum or index==n)
        return;

    for(int i=index; i<n; i++)
    {
        s.push_back(arr[i]);
        backtrack(size+1, i+1, sum+arr[i]);
        s.pop_back();
    }
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    while(cin >> t >> n and (t or n))
    {
        for(int i=0; i<n; i++) 
            cin >> arr[i];
        
        found.clear();
        solution = false;
        cout << "Sums of " << t << ":\n";
        backtrack(0, 0, 0);
        
        if(!solution)
            cout << "NONE\n";
    }
    return 0;
}