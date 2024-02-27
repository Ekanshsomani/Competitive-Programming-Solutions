// 10258
// rank - npSolve, tPenalty, team
// tPenalty: firstCorrectSubmission Time + 20*nIncSub

#include <iostream>
#include <array>
#include <vector>
#include <bitset>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

struct contestant{
    int team;
    int npSolve{0};
    int tPenalty{0};
    int nIncSub[11] = {0}; //value - incorrect submissions
    bitset<11> solved = {0};
};

bool operator< (const contestant& c1, const contestant& c2){
    int a {c1.npSolve}, b {c1.tPenalty}, c {c1.team};
    int d {c2.npSolve}, e {c2.tPenalty}, f {c2.team};
    return a>d || (a==d&&b<e) || (a==d && b==e && c<f);
}

int main(){
    
    // Input: 
    // number of test cases; blank line
    // cId, pId, time, L
    // L: C, I, R, U, or E.
    

    int t;
    cin >> t;
    cin.ignore();
    cin.ignore();

    int cId, pId, time;
    char L;
    string submission;

    while(t--){
        array<contestant, 101> data;
        bitset<101> participation;

        while(getline(cin, submission) && submission.length()!=0){
            istringstream in(submission);
            in >> cId >> pId >> time >> L;
            if(!participation[cId]){
                data[cId].team = cId;
                participation[cId] = 1;
            }
            
            if(L=='C' && !data[cId].solved[pId]){
                data[cId].npSolve++;
                data[cId].tPenalty += time + data[cId].nIncSub[pId]*20;
                data[cId].solved[pId] = 1;
            }
            else if(L=='I' && !data[cId].solved[pId]) data[cId].nIncSub[pId]++;
        }

        vector<contestant> scoreBoard;
        for(int i=0; i<101; i++) if(participation[i]) scoreBoard.push_back(data[i]);

        sort(scoreBoard.begin(), scoreBoard.end());

        for(auto it: scoreBoard) cout << it.team << ' ' << it.npSolve << ' ' << it.tPenalty << endl;
        if(t) cout << endl;

        
    }
    return 0;
}