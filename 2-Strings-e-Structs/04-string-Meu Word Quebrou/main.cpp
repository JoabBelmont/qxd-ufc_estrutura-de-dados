#include <iostream>
#include <string>

using namespace std;

int main() {
	string txt;
	char mod;

	getline(cin, txt);
	cin >> mod;

	for(int i = 0; txt[i]; i++) {
		if(mod == 'M') {
			txt[i] = islower(txt[i]) ? toupper(txt[i]) : txt[i];
		}
		if(mod == 'm') {
			txt[i] = isupper(txt[i]) ? tolower(txt[i]) : txt[i];
		}
		if(mod == 'p') {
			if(i == 0 || (txt[i - 1] == ' ' && txt[i + 1] == ' ') || (txt[i - 1] == ' ' && i == txt.size() - 1)) {
				txt[i] = tolower(txt[i]);
			} else if(txt[i - 1] == ' ' && txt[i + 1] != ' ') {
				txt[i] = toupper(txt[i]);
			}
		}
		if(mod == 'i') {
			txt[i] = islower(txt[i]) ? toupper(txt[i]) : tolower(txt[i]);
		}
	}

	cout << txt;

	return 0;
}
