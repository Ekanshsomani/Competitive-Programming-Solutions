// 1062
// rail & road >> containers >> stacks >> ships [A-Z] (26)
// No limit on stack capacity.
// Containers labelled by ship letter on which they need to be loaded.

// test case - single (1-1000 characters)
// last line - end.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string containers;
    int t{0};
    
    while(cin >> containers && containers[0]!='e'){
        vector<char> stacks(1, containers[0]);
        
        for(int i=1; i<containers.length(); i++){
            int minDiff = 'Z' + 1;
            int k = -1;
            
            for(int j=0; j<stacks.size(); j++){
                if(containers[i]<=stacks[j] && stacks[j]-containers[i]< minDiff){
                    k = j;
                    minDiff = stacks[j] - containers[i];
                }
            }

            if(k==-1)
                stacks.push_back(containers[i]);
            else
                stacks[k] = containers[i];
        }

        cout << "Case " << ++t << ": " << stacks.size() << endl;
    }
    return 0;
}