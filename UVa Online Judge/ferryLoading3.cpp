#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// ingenuity in this solution is out of the world.
// like...  how the fuck did anyone come up with it?
// I genuinely need to learn writing my algos on paper first
// so that I can come up with solutions like these.

int main(){
    int testcases;
    cin >> testcases;
    while(testcases--){
        int capacity, crossTime, cars;
        cin >> capacity >> crossTime >> cars;
        
        vector<int> totalTime(cars);
        vector<stack<int>> sides(2);
        for(int i=0; i<cars; i++){
            int time;
            string bank;
            cin >> time >> bank;
            if(bank[0]=='l') sides[0].push(i);
            else sides[1].push(i);
            totalTime[i] = time;
        }

        int side{0}, time{0};
        while(!sides[0].empty()||!sides[1].empty()){
            int nextArrive;
            if(sides[0].empty())
                nextArrive = totalTime[sides[1].front()];
            else if(sides[1].empty())
                nextArrive = totalTime[sides[0].front()];
            else
                nextArrive = min(totalTime[sides[0].front()], totalTime[sides[1].front()]);
            
            int currentCapacity = 0;

            cout << "time: " << time << ", nextArrive: " << nextArrive << endl;

            time = max(time, nextArrive);

            while(!sides[side].empty() && totalTime[sides[side].front()]<=time && currentCapacity < capacity){
                currentCapacity++;
                totalTime[sides[side].front()] = time + crossTime;

                cout << sides[side].front() << ": " << time << ", " << totalTime[sides[side].front()] << endl;

                sides[side].pop();
            }

            time += crossTime;
            side = (side+1)%2;
        }

        for(int i=0; i<cars; i++)
            cout << totalTime[i] << endl;
        if(testcases)
            cout << endl;
    }
    return 0;
}