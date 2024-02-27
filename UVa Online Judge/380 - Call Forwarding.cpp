// 380
// if cyclic request -> 9999

// source time duration target
// 0000
// time extension (non-decreasing order)
// 9000

// 8784 -max time val

// 9998

#include <iostream>
#include <array>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

priority_queue<array<int, 4>, vector<array<int, 4>>,  greater<array<int,4>>> act;
unordered_map<int, int> forwardState;
unordered_set<int> vis;

/**/
int getTarget(int ext)
{
    if(vis.count(ext))
        return 9999;

    vis.insert(ext);
    int a {(forwardState.count(ext)) ? getTarget(forwardState[ext]): ext};
    vis.erase(ext);
    return a;
}
/**/

int main()
{
    printf("CALL FORWARDING OUTPUT\n");

    int testcases;
    cin >> testcases;
    int t{1};
    while(testcases--)
    {
        int source, time, duration, target;
        while(cin >> source and source > 0)
        {
            cin >>  time >> duration >> target;

            act.push({time, 1, source, target});
            act.push({time+duration+1, 0, source, target});
        }

        printf("SYSTEM %d\n", t++);
        int extension;
        while(cin >> time && time<8785)
        {
            while(act.top()[0] <= time)
            {
                if(act.top()[1])
                    forwardState[act.top()[2]] = act.top()[3];    
                else
                    forwardState.erase(act.top()[2]);
                
                //printf("%04d, %04d, %04d, %04d at %04d\n", act.top()[0], act.top()[1], act.top()[2], act.top()[3], time);
                act.pop();
                }

            cin >> extension;
            
            printf("AT %04d CALL TO %04d RINGS %04d\n", time, extension, getTarget(extension));
        }
    }

    printf("END OF OUTPUT\n");
    return 0;
}