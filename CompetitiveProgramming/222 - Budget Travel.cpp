// destinationDist
// gallonCapacity milesPerGallon OriginationCityCost NumberofGasStations
// stationDist pricePerGallon

#include <iostream>
#include <cmath>
using namespace std;

float dest, tankCap, aver, cost;
float maxDist;
int stNum;
float minBudget;

float stations[50*2];

void backtrack(int index, float totalDist, float budget)
{
    if(totalDist+maxDist >= dest)
    {
        minBudget = min(minBudget, budget);
        return;
    }

    while(stations[index]<(totalDist+0.5*maxDist) and (index+2)<(stNum*2) and stations[index+2]<=(totalDist+maxDist))
        index+=2;

    while(index<stNum*2 and stations[index]<=(totalDist+maxDist))
    {
        backtrack(index+2, stations[index], budget + 2 + round((stations[index+1]*(stations[index]-totalDist))/aver)/100);
        index += 2;
    }
    
}

int main()
{
    int t{1};
    while(cin >> dest && dest>0)
    {
        cin >>  tankCap >> aver >> cost >> stNum;
        //printf("%f\n%f %f %f %f\n", dest, tankCap, aver, cost, stNum);
        

        maxDist = tankCap*aver;
        minBudget = 10000001;

        for(int i=0; i<2*stNum; i+=2)
        {
            cin >> stations[i] >> stations[i+1];
            //printf("%f %f\n", stations[i], stations[i+1]);
        }

        backtrack(0, 0, cost);

        printf("Data Set #%d\n", t++);
        printf("minimum cost = $%.2f\n", minBudget);
    }
    return 0;
}