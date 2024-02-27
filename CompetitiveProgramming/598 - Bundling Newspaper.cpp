#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int n; // number of newspapers
string newspaper[12];
int a, b; // size of subsets;
int ssize;

vector<int> subset;

void backtrack(int index, int size)
{
    if(size==ssize)
    {
        for(auto it: subset)
            cout << newspaper[it] << ((it==subset[size-1])?"\n":", ");
        return;
    }
    if(index==n)
        return;

    subset.push_back(index);
    backtrack(index+1, size+1);
    subset.pop_back();
    backtrack(index+1, size);
}

int main()
{
    int testcases;
    cin >>  testcases;
    cin.ignore();
    cin.ignore();

    string line, name;
    while(testcases--)
    {
        getline(cin, line);

        n = 0;
        while(getline(cin, name))
        {
            if(name.length()==0)
                break;
            newspaper[n] = name;
            n++;
        }
        /**/
        if(line=="*")
        {
            a = 1;
            b = n;
        }
        else if(line.length()>2)
        {
            istringstream ss(line);
            ss >> a >> b;
        }
        else
            a = b = stoi(line);

        /**/
        for(ssize=a; ssize<=b; ssize++)
        {
            cout << "Size " << ssize << endl;
            backtrack(0, 0);
            cout << endl;
        }
        /**/

        if(testcases)
            cout << endl;
    }
    return 0;
}