#include <iostream>
#include <map>
using namespace std;

int length, maxReplace;

map<string, int> mutations;
char elements[4]{'A', 'C', 'G', 'T'};

void generateMutation(string dna, int replaced)
{
    if(!mutations.count(dna))
        mutations.insert({dna, replaced});
    else if(mutations[dna]<=replaced)
        return;
    else
        mutations[dna] = replaced;

    if(replaced == maxReplace) 
        return;

    for(int i=0; i<length; i++)
    {
        char temp = dna[i];
        for(int j=0; j<4; j++)
        {
            dna[i] = elements[j];
            generateMutation(dna, replaced+1);
        }
        dna[i] = temp;
    }
    return;
}

int main()
{
    int testcases;
    cin >> testcases;

    while(testcases--)
    {
        mutations.clear();

        cin >> length >> maxReplace;
        string ordna;
        cin >> ordna;

        generateMutation(ordna, 0);

        cout << mutations.size() << endl;
        for(auto it: mutations)
            cout << it.first << endl;
    }
    return 0;
}