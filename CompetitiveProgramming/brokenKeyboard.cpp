#include <iostream>
#include <list>
#include <string>
using namespace std;

int main(){
    string line;

    while(getline(cin, line)){
        list<char> monitorText;
        list<char>::iterator j = monitorText.end();

        for(auto it:line){
            switch(it){
                case '[': j=monitorText.begin();
                    break;
                case ']': j=monitorText.end();
                    break;
                default: monitorText.insert(j, it); // remember this syntax
            }
        }

        for(auto it: monitorText) cout << it;
        cout << "\n";
    }
    return 0;
}