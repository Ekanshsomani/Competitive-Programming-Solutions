#include <bits/stdc++.h>
using namespace std;

int friends, budget, tea, dishTypes;
int price[100], favor[100];

// states - (idx, remMoney) = 
    // (idx-1, remMoney), 
    // (idx-1, remMoney-price[idx])+favor[idx], 
    // (idx-1, remMoney-2*price[idx])+2*favor[idx]

inline int getMaxFavor()
{
    vector<int> memo(budget+1, 0), bought(budget+1, 0);
    int maxDishes = friends<<1;

    for(int i=0; i<dishTypes; i++)
        for(int j=budget; j>=price[i]; j--)
        {
            if(j>=(2*price[i]) && bought[j-2*price[i]]<(maxDishes - 1) && 
            (memo[j-2*price[i]]+2*favor[i])>memo[j])
            {
                memo[j] = memo[j-2*price[i]]+2*favor[i];
                bought[j] = bought[j-2*price[i]]+2;
            }
            else if(bought[j-price[i]]<maxDishes && 
            (memo[j-price[i]]+favor[i])>memo[j])
            {
                memo[j] = memo[j-price[i]]+favor[i];
                bought[j] = bought[j-price[i]]+1;
            }
        }
    
    return *max_element(memo.begin(), memo.end());
}

int main()
{
    int temp;
    
    while(cin >> friends >> budget >> tea >> dishTypes and 
    ( friends or budget or tea or dishTypes )
    )
    {
        friends++;
        budget *= friends;
        budget /= 1.1;
        budget -= tea;
        for(int i=0; i<dishTypes; i++)
        {
            cin >> price[i];
            favor[i] = 0;
            for(int j=0; j<friends; j++)
            {
                cin >> temp;
                favor[i] += temp;
            }
        }
        
        /*
        printf("Prices: ");
        for(int i=0; i<dishTypes; i++)
            printf("%d ", price[i]);
        printf("\n");

        printf("Favors: ");
        for(int i=0; i<dishTypes; i++)
            printf("%d ", favor[i]);
        printf("\n");
        /**/

        printf("%.2f\n", getMaxFavor()/(1.0*friends));

    }
    return 0;
}