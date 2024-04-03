// 10172
// Cargo - cubic box (fixed size), NamingTag (Destination)
// Each country - Unique ID number (1 to n)
// Cargo Station:
    // A - By Air to X at some convenient time
    // B - Queue of cargoes to be carried to some other country
// Circular ring arrangement of cargo stations

// Cargo carriers - (Stacks, carry cargo between stations, follow ring arrangement)
// 2 minute travel time between stations
// unloading/loading per box - 1 minute

// Input:
// SET (number of sets)
// N, S, Q
    // N -> Number of stations
    // S -> Stack Capacity (carrier)
    // Q -> Queue Capacity (platform)
// qi, .... qi cargos

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n, s, q;
        cin >> n >> s >> q;

        vector<stack<int>> circle(n);
        stack<int> carrier;    

        int qi{0}, temp{0};
        for(int i=0; i<n; i++){            
            cin >> qi;
            while(qi--){
                cin >> temp;
                circle[i].push(temp-1);
            }
        }

        bool empty = 0;
        int cs {0}, time{0};
        while(!empty){
            // unloading
            while(!carrier.empty() && (carrier.top() == cs || circle[cs].size()<q)){
                if(carrier.top()!=cs) circle[cs].push(carrier.top());
                carrier.pop();
                ++time;
            }

            // loading
            while(carrier.size()<s && !circle[cs].empty()){
                carrier.push(circle[cs].front());
                circle[cs].pop();
                ++time;
            }

            // transportation
            empty = carrier.empty();
            if(empty){
                for(int i=0; i<n; i++){
                    if(!circle[i].empty()){
                        empty = 0;
                        break;
                    }
                }
            }

            if(!empty){
                cs = (cs+1)%n;
                time +=2;
            }
        }

        cout << time << endl;
    }

    return 0;
}
