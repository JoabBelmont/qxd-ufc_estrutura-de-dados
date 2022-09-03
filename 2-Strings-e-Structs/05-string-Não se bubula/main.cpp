#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool isVowel(char _c) {
	char vowels[5] { 'a', 'e', 'i', 'o', 'u' };
	for(int i = 0; i < 5; i++) {
		if(_c == vowels[i]) {
			return true;
		}
	}
	return false;
}

int silCount(string _str) {
	int sil { 1 };
	for(int i = 0; _str[i]; i++) {
		if(isVowel(_str[i]) && !isVowel(_str[i + 1]) && _str[i + 1]) {
			sil++;
		}
	}
	
	return sil;
}

int wordCount(string _str) {
	int count {1};
	for(int i = 0; _str[i]; i++) {
		if(_str[i] == ' ') count++;
	}

	return count;
}

int main() {
	string txt;
	getline(cin, txt);

	stringstream ss;
	ss << txt;
	string word;

	int silEnd, silId {0}, wordId {0};

	while(ss >> word) {
		wordId++;
		for(int i = 0; word[i]; i++) {
			cout << word[i];
			if(isVowel(word[i]) && !isVowel(word[i + 1]) && silId == 0 && (silCount(word) > 1)) {
				silEnd = i;
				for(int j = 0; j < 2; j++) {
					for(int k = 0; k <= silEnd; k++) {
						cout << word[k];
					}
				}
				silId++;
			}
		}
		silId = 0;
		if(wordId != wordCount(txt))
			cout << " "; 
	}

	return 0;
}