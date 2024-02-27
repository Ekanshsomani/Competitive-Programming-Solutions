// 11933
// split n such that in its binary form, start from the left (LSB)
// first one that encounter goes into a, the next one goes into b.
// i.e. all the odd ones go into a.

#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n && n){
        int a{0}, temp{n}, oneIn{0}, currIn{0};

        while(temp){
            if(temp & 1){
                oneIn++;
                if(oneIn & 1) a += (1 << currIn);
            }
            currIn++;
            temp >>= 1;
        }

        cout << a << ' ' << n-a << endl;
    }
    return 0;
}
