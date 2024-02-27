// create a sumArray[20][20][20]
// at every index i,j,k
    // a[i][j][k] = 
        // a[i-1][j][k] + a[i][j-1][k] + a[i][j][k-1] + a[i-1][j-1][k-1] -
        // a[i-1][j-1][k] - a[i][j-1][k-1] - a[i-1][j][k-1]
// for indices [i][j][k]
    // iterate over all indices [x][y][z] upto [a][b][c] 
        //  maximize sum = 
            // a[x][y][z] - a[i-1][y][z] - a[x][j-1][z] - a[x][y][k-1] + 
            // a[i-1][j-1][z] + a[x][j-1][k-1] + a[i-1][y][k-1] - 
            // a[i-1][j-1][k-1]
// O(n^6)

#include <iostream>
using namespace std;

int main()
{
    long long sumArray[20][20][20];

    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int a, b, c;
        cin >>  a >> b >> c;
        for(int i=0; i<a; i++)
            for(int j=0; j<b; j++)
                for(int k=0; k<c; k++)
                {
                    cin >> sumArray[i][j][k];
                    long long &s = sumArray[i][j][k];
                    if(i) s += sumArray[i-1][j][k];
                    if(j) s += sumArray[i][j-1][k];
                    if(k) s += sumArray[i][j][k-1];
                    if(i and j) s -= sumArray[i-1][j-1][k];
                    if(j and k) s -= sumArray[i][j-1][k-1];
                    if(i and k) s -= sumArray[i-1][j][k-1];
                    if(i and j and k) s += sumArray[i-1][j-1][k-1];
                }

        long long maxSum{sumArray[a-1][b-1][c-1]};
        for(int i=0; i<a; i++)
            for(int j=0; j<b; j++)
                for(int k=0; k<c; k++)
                    for(int x=i; x<a; x++)
                        for(int y=j; y<b; y++)
                            for(int z=k; z<c; z++)
                            {
                                long long sum{sumArray[x][y][z]};
                                if(i) sum -= sumArray[i-1][y][z];
                                if(j) sum -= sumArray[x][j-1][z];
                                if(k) sum -= sumArray[x][y][k-1];
                                if(i and j) sum += sumArray[i-1][j-1][z];
                                if(j and k) sum += sumArray[x][j-1][k-1];
                                if(i and k) sum += sumArray[i-1][y][k-1];
                                if(i and j and k) sum -= sumArray[i-1][j-1][k-1];

                                maxSum = max(sum, maxSum);
                            }
        
        printf("%lld\n", maxSum);
        if(testcases) printf("\n");
    }
    return 0;
}