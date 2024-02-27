#include <iostream>
using namespace std;

int main()
{
    int sumArray[100][100]; //, arr[100][100];

    int n;
    while(cin >> n)
    {
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                cin >> sumArray[i][j];
                // arr[i][j] = sumArray[i][j];

                if(i) sumArray[i][j] += sumArray[i-1][j];
                if(j) sumArray[i][j] += sumArray[i][j-1];
                if(i and j) sumArray[i][j] -= sumArray[i-1][j-1];
            }

        int maxSum{-n*n*128};
        for(int row=0; row<n; row++)
            for(int col=0; col<n; col++)
                for(int i=row; i<n; i++)
                    for(int j=col; j<n; j++)
                    {
                        int s = sumArray[i][j];
                        if(col) s-= sumArray[i][col-1];
                        if(row) s-= sumArray[row-1][j];
                        if(row and col) s+= sumArray[row-1][col-1];

                        if(s>maxSum) maxSum = s;
                    }

        printf("%d\n", maxSum);
    }
   return 0;
}