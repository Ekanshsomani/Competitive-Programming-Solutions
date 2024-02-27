#include <iostream>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

int t, p, s;
string topics[16];
map<int, unordered_set<int>> adj;

bool compare(const string&a, const string&b)
{
    if(a.length()==b.length())
        return a<b;
    return a.length()>b.length();
}

int topicidx(string a)
{
    for(int i=0; i<t; i++)
        if(topics[i]==a)
            return i;
    return -1;
}

set<int> subset;

void backtrack(int index, int size)
{
    if(size == s)
    {
        for(auto it: subset)
            cout << (topics[it]) << ((it==*(subset.rbegin()))?"\n":" ");
        return;
    }
    if(index==t)
        return;
    
    bool addable{true};
    for(auto it: adj[index])
        if(subset.count(it))
            addable = false;

    if(addable)
    {
        subset.insert(index);
        backtrack(index+1, size+1);
        subset.erase(index);
    }
    backtrack(index+1, size);
}

int main()
{
    int testcases;
    cin >> testcases;
    int setNum{1};
    while(testcases--)
    {
        cin >> t >> p >> s;

        for(int i=0; i<t; i++)
            cin >> topics[i];

        sort(topics, topics+t, compare);

        adj.clear();
        for(int i=0; i<p; i++)
        {
            string a, b;
            cin >> a >> b;
            int j,k;
            j = topicidx(a);
            k = topicidx(b);
            
            if(!adj.count(j)) adj[j] = {};
            if(!adj.count(k)) adj[k] = {};

            adj[j].insert(k);
            adj[k].insert(j);
        }

        for(int i=0; i<t; i++)
            transform(topics[i].begin(), topics[i].end(), topics[i].begin(), ::toupper);

        cout << "Set " << setNum++ << ":\n";
        backtrack(0, 0);
        cout << "\n";
    }
}