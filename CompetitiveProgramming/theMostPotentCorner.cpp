// N-dimensional cube. (1-15)
// Potency = weights of N-neighboring corners
// Two neighboring corners with max potency sum
// corner coordinates - represented by N-bits(either 0 or 1).
// Neighboring corners - Only one bit is different.

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int corners = (1 << n);
        vector<int> weights(corners);
        for(int i=0; i<corners; i++) cin >> weights[i];

        vector<int> potency(corners);
        for(int i=0; i<corners; i++){
            int cPotency {0};
            for(int j=0; j<n; j++){
                int k = i^(1<<j);
                cPotency += weights[k];
            }
            potency[i] = cPotency;
        }

        int maxPot{0};
        for(int i=0; i<corners; i++){
            for(int j=0; j<n; j++){
                int k = i^(1<<j);
                maxPot = max(maxPot, potency[i]+potency[k]);
            }
        }

        cout << maxPot << endl;
    }
    return 0;
}
