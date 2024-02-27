#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<char> gridA[5], gridB[5];

vector<string> passwords;

void backtrack(int gridIndex, string p)
{   
    if(gridIndex==5)
    {
        if(passwords.size()==0)
            passwords.push_back(p);
        else if(passwords.back() != p)
            passwords.push_back(p);
        return;
    }

    for(auto it: gridA[gridIndex])
        if(gridB[gridIndex].count(it))
            backtrack(gridIndex+1, p+it);
}

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int k;
        cin >> k;

        for(int i=0; i<6; i++)
            for(int j=0; j<5; j++)
            {
                char a;
                cin >> a;
                gridA[j].insert(a);
            }

        for(int i=0; i<6; i++)
            for(int j=0; j<5; j++)
            {
                char a;
                cin >> a;
                gridB[j].insert(a);
            }
            
        backtrack(0, "");

        if(k>passwords.size())
            printf("NO\n");
        else
            cout << passwords[k-1] << endl;

        if(testcases)
        {
            passwords.clear();
            for(int i=0; i<5; i++)
            {
                gridA[i].clear();
                gridB[i].clear();
            }
        }
    }
    return 0;
}