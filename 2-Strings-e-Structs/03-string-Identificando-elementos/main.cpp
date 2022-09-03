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
		for(int i = 0; word[i]; i++) { 
			if(isalpha(word[i])) { // Analisa se o carct. atual é uma letra
				cout << "str ";
				break;
			}
			if(word[i] == '.') { // se é uma ponto, seta o valor booleano
				point = true;
				continue;
			}
			if(isdigit(word[i])) { 
				if(i < word.size() - 1) { // se não for o último dígito do token, reseta o loop
					continue;
				} else { // se for:
					cout << (point ? "float " : "int "); // imprime dependendo do valor booleano
					point = false; // dps, reseta ele
				}
			}
		}
	}

	return 0;
}