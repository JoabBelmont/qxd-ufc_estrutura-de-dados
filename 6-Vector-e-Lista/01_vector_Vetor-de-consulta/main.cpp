#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> matchingStrings(vector<string> query, vector<string> search);
vector<string> fillVector(vector<string> vec, int size);

int main() {
	vector<string> query;
	vector<string> search;
	int size;

	cin >> size;
	query = fillVector(query, size);

	cin >> size;
	search = fillVector(search, size);

	for(int i = 0; i < size; i++) {
		cout << matchingStrings(query, search)[i];
		cout << ((i != size - 1) ? " " : "\n");
	}

	return 0;
}

vector<int> matchingStrings(vector<string> query, vector<string> search) {
	int count { 0 };
	vector<int> result;
	for(int i = 0; i < (int)search.size(); i++) {
		for(int j = 0; j < (int)query.size(); j++) {
			if(search[i] == query[j]) count++;
		}
		result.push_back(count);
		count = 0;
	}
	return result;
}

vector<string> fillVector(vector<string> vec, int size) {
	for(int i = 0; i < size; i++) {
		string line;
		cin >> line;
		vec.push_back(line);
	}
}