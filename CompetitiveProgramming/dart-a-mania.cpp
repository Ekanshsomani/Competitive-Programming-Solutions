// 735
#include <iostream>
using namespace std;

inline void printas()
{
    printf("**********************************************************************\n");
}

int arr[] = 
{
     0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 24, 26, 27, 28, 30, 32, 33, 34, 36, 38, 39, 40, 42, 45, 48, 50, 51, 54, 57, 60
};
int n{43};

// i <= j <= k

int main()
{
    int num;
    while(cin >> num && num>0)
    {
        if(num>180)
        {
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", num);
            printas();
            continue;
        }

        int c{0}, p{0};
        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++)
                for(int k=j; k<n; k++)
                    if(arr[i]+arr[j]+arr[k]==num)
                    {
                        c++;
                        if(arr[i]==arr[j] && arr[j]==arr[k]) 
                            p++;
                        else if(arr[i]==arr[j] || arr[j] == arr[k] || arr[k]==arr[i])
                            p+= 3;
                        else
                            p+=6;
                    }

        if(c)
        {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", num, c);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", num, p);
        }
        else
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", num);
        printas();
    }
    printf("END OF OUTPUT\n");
    return 0;
}