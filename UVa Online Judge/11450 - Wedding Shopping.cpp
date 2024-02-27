#include <iostream>
#include <cstring>
using namespace std;

// state represented by: money(available), garment type;

int memo[210][25], garments[25][25], models[25];

int maxSpent(int budget, int g)
{
    if(budget<=0)
        return -1;

    int &ans = memo[budget][g];
    if(ans!=-1)
        return ans;
    else if(g==0)
    {
        for(int i=0; i<models[g]; i++)
            if(garments[g][i]<=budget)
                ans = max(ans, garments[g][i]);
        return ans;
    }
    else
    {
        for(int i=0; i<models[g]; i++)
        {
            int k = maxSpent(budget-garments[g][i], g-1);
            if(k!=-1)
                ans = max(ans, garments[g][i]+k);
        }
        return ans;
    }
    return ans;
}

int main()
{

    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int budget, types;
        cin >> budget >> types;

        for(int i=0; i<types; i++)
        {
            cin >> models[i];
            for(int j=0; j<models[i]; j++)
                cin >> garments[i][j];
        }

        memset(memo, -1, sizeof memo);

        int score = maxSpent(budget, types-1);
        if(score<0)
            printf("no solution\n");
        else
            printf("%d\n", score);
    }
    return 0;
}