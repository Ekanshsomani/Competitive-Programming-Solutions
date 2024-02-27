// 11926
// 1 million minutes; from now - 0
// at most one task
// Two types of tasks:
    // One Time Tasks - start-end
    // Repeating Tasks - start-end (First occurrence) & repetition interval
// touching is fine [1,5] && [5,60]


// 30 test cases
// n, m <=100
    // n - one time tasks, m - repeating tasks
// start, end - n lines
// start, end, rInt - m lines
// 0 0

#include <iostream>
#include <bitset>
using namespace std;

#define MAX 1000001

int main(){
    int n, m;
    bitset<MAX> calendar;

    while(cin >> n >> m && (n||m)){
        int conflict{0}, s, e, r;
        
        for(int i=0; i<n; i++){
            cin >> s >> e;
            if(!conflict){
                for(int j=s; j<e; j++){
                    if(calendar[j]) conflict = 1;
                    calendar[j] = 1;
                }
            }
        }

        for(int i=0; i<m; i++){
            cin >> s >> e >> r;
            while(s<MAX && !conflict){
                for(int j=s; (j<e && j<MAX); j++){
                    if(calendar[j]) conflict = 1;
                    calendar[j] = 1;
                }
                s+= r;
                e+= r;
            }
        }

        if(conflict) cout << "CONFLICT" << endl;
        else cout << "NO CONFLICT" << endl;

        calendar.reset();
    }
    return 0;
}