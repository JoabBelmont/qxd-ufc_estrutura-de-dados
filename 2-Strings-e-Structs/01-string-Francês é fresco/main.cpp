#include <iostream>
#include <string>

using namespace std;

bool isVowel(char _c) { // diz se um caractere é uma vogal ou não
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    for(int i = 0; i < 5; i++) {
        if(_c == vowels[i] || _c == toupper(vowels[i])) { 
            return true;
        }
    }
    return false;
}

int main() {
    string txt;
    getline(cin, txt);
    for(int i = 0; txt[i]; i++) {
        if(isspace(txt[i]) && isVowel(txt[i - 1]) && txt[i + 1] == txt[i - 1]) { 
            i++; // Se detectar um espaço e o sucessor for igual ao antecedente, pula o espaço e reseta o loop
            continue;
        } else
            cout << txt[i]; // se não, printa o caractere atual
    }

    return 0;
}