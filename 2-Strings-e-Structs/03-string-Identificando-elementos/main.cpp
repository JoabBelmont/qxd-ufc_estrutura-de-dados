#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    bool point;
    string txt;
    getline(cin, txt);
    stringstream ss;

    ss << txt;

    string word;

    while(ss >> word) {
        for(int i = 0; i < word.size(); i++) {
            if(isalpha(word[i])) {
                cout << "str ";
                break;
            }
            if(word[i] == '.') {
                point = true;
                continue;
            }
            if(isdigit(word[i])) {
                if(i < word.size() - 1) {
                    continue;
                } else {
                    cout << (point ? "float " : "int ");
                    point = false;
                }
            }
            
        }
    }

    return 0;
}