#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string txt;
    getline(cin, txt);

    stringstream ss;
    string currentStr, lastString;

    ss << txt; // joga a string pra ss
    ss >> currentStr; // e a ss pra outra var

    while(ss >> lastString) {
        if(lastString > currentStr) {
            currentStr = lastString;
        } else {
            cout << "nao";
            return 0;
        }
    }

    cout << "sim";
    return 0;
}