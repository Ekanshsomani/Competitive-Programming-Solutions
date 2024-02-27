#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// another way to solve the trainsorting question
// O(n^2) time complexity

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int n;
        cin >> n;

        vector<int> cars(n);
        for(int i=0; i<n; i++)
            cin >> cars[i];
        
        vector<int> increaslis(n, 1), decreaslis(n, 1);
        for(int i=n-1; i>-1; i--)
            for(int j=i+1; j<n; j++)
                if(cars[i]<cars[j])
                    increaslis[i] = max(increaslis[i], increaslis[j]+1);
                else if(cars[i]>cars[j])
                    decreaslis[i] = max(decreaslis[i], decreaslis[j]+1);

        int trainLength{1};
        for(int i=0; i<n; i++)
            trainLength = max(trainLength, increaslis[i]+decreaslis[i]);

        printf("%d\n", trainLength-1);
    }
}