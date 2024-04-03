// 11572
// Given a sequence of integers, find the length of the 
// longest contiguous subsequence containing no repeated 
// elements.

#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        unordered_map<int, int> lastIndex;
        int length{0}, maxlength{0}, beforeRepeat{0};
        
        int n;
        cin >> n;
        for(int i=1; i<=n; i++)
        {
            int snowid;
            cin >> snowid;

            int seen = lastIndex[snowid];
            if(seen)
            {
                beforeRepeat = max(beforeRepeat, seen);
                length = i - beforeRepeat - 1;
            }
            
            length++;
            maxlength = max(maxlength, length);
            lastIndex[snowid] = i;
        }

        cout << maxlength << endl;
    }
    return 0;
}