// 732
// awesome question to learn recursion
#include <iostream>
#include <string>
using namespace std;

string word, anagram;


void printOperations(int ops, string anagram1, string word1, string stack, string operations){
    if(ops == (word.length()<<1) && anagram == anagram1) {
        cout << operations << endl;
        return;
    }

    if(word1.length())
        printOperations(ops+1, anagram1, word1.substr(1, word1.length()-1), stack+word1[0], operations+(ops?" i":"i"));
    
    int l = stack.length();
    if(l && stack[l-1] == anagram[anagram1.length()])
        printOperations(ops+1, anagram1+stack[l-1], word1, stack.substr(0, l-1), operations+" o");
}

int main(){
    while(cin >> word >> anagram){
        cout << "[\n";
        if(word.length()==anagram.length())
            printOperations(0, "", word, "", "");
        cout << "]\n";
    }
    return 0;
}