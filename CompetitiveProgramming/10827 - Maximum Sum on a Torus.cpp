#include <iostream>
using namespace std;

int main()
{
    int torus[150][150], arr[75][75];

    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int n;
        cin >> n;

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin >> arr[i][j];

        for(int i=0; i<2*n; i++)
            for(int j=0; j<2*n; j++)
            {
                int s{arr[i%n][j%n]};
                if(i) s += torus[i-1][j];
                if(j) s += torus[i][j-1];
                if(i and j) s-= torus[i-1][j-1];

                torus[i][j] = s;
            }

        int maxSum{torus[n-1][n-1]};
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                for(int x=i; x<(i+n); x++)
                    for(int y=j; y<(j+n); y++)
                    {
                        int sum{torus[x][y]};
                        if(i) sum -= torus[i-1][y];
                        if(j) sum -= torus[x][j-1];
                        if(i and j) sum += torus[i-1][j-1];
                        maxSum = max(sum, maxSum);
                    }
        printf("%d\n", maxSum);
    }
    return 0;
}