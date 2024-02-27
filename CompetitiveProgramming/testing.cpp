#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream file1("input.txt"), file2("output.txt");

    string line1, line2;
    int i{0};

    while(getline(file1, line1) and getline(file2, line2))
    {
        i++;
        if(line1!=line2)
            cout << i << ": " << line1 << "   |   " << line2 << endl;
    }
}