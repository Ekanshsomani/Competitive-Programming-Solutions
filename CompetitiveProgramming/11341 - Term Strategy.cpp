#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// state -> (idx, remHrs); -> 10*100
int memo[10][100];
int n, m;
int grades[10][100], start[10];

int totalScore(int idx, int remHrs)
{
    int &ans = memo[idx][remHrs];
    if(ans!=-1)
        return ans;

    int upBound{min(1+start[idx]+remHrs, m)};

    if(idx==(n-1))
        return ans = *max_element(grades[idx]+start[idx], grades[idx]+upBound);

    remHrs += start[idx];
    for(int i=start[idx]; i<upBound; i++)
        ans = max(ans, grades[idx][i]+totalScore(idx+1, remHrs-i));

    return ans;
}

int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        cin >> n >> m;
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin >> grades[i][j];

        memset(start, -1, sizeof start);
        int minHrs{0};
        bool pos{true};
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(grades[i][j]>=5)
                {
                    start[i] = j;
                    minHrs += j+1;
                    break;
                }
                if(j==(m-1))
                    pos = false;
            }
        

        if(minHrs>m or not pos)
        {
            printf("Peter, you shouldn't have played billiard that much.\n");
            continue;
        }

        memset(memo, -1, sizeof memo);
        double average{totalScore(0, m-minHrs)/(1.00*n) + 1e-9};
        printf("Maximal possible average mark - %.2f.\n", average);
    }
    
    return 0;
}