#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

vector<int> correctOrder; 
int *currentOrder;

inline int getScore(int size)
{
    vector<int> maxLength(size, 1);
    maxLength[0] = 1;

    int maxScore{1};
    for(int i=1; i<size; i++)
    {
        for(int j=0; j<i; j++)
            if(
                (correctOrder[currentOrder[j]] <correctOrder[currentOrder[i]])
                and (maxLength[i]<=maxLength[j])
            )
            {
                maxLength[i] = maxLength[j]+1;
            }
        maxScore = max(maxScore, maxLength[i]);
    }
    return maxScore;
}

int main()
{
    string line;
    int n;
    while(getline(cin, line))
    {
        if(line.size()<3)
        {
            n = stoi(line);
            correctOrder.clear();
            delete currentOrder;
            currentOrder = new int(n);

            getline(cin, line);
            istringstream ss(line);

            int rank;
            while(ss>>rank)
                correctOrder.push_back(rank);
            continue;
        }

        istringstream ss(line);
        int rank;
        for(int i=0; i<n; i++)
        {
            ss >> rank;
            currentOrder[rank-1] = i;
        }

        printf("%d\n", getScore(n));
    }
    return 0;
}