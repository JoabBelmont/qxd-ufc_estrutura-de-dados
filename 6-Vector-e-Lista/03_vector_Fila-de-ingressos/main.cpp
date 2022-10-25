#include <iostream>
#include <vector>

using namespace std;

vector<int> fillVector(vector<int> vec, int vecSize);
vector<int> eraseId(vector<int> vecq, vector<int> vecl);
void showVector(vector<int> vec);

int main() {
	int queueSize { 0 }, leftQty { 0 };
	vector<int> queueId, leftId;

	cin >> queueSize;
	queueId = fillVector(queueId, queueSize);
	cin >> leftQty;
	leftId = fillVector(leftId, leftQty);

	queueId = eraseId(queueId, leftId);

	showVector(queueId);

	return 0;
}

vector<int> fillVector(vector<int> vec, int vecSize) {
	int aux;
	for(int i = 0; i < vecSize; ++i) {
		cin >> aux;
		vec.push_back(aux);
		aux = 0;
	}
	return vec;
}

vector<int> eraseId(vector<int> vecQ, vector<int> vecL) {
	for(int i = 0; i < (int)vecQ.size(); ++i) {
		for(int j = 0; j < (int)vecL.size(); ++j) {
			if(vecQ[i] == vecL[j]) {
				vecQ.erase(vecQ.begin() + i);
				i = -1;
			}
		}
	}
	return vecQ;
}

void showVector(vector<int> vec) {
	for(int i = 0; i < (int)vec.size(); ++i) {
		cout << vec[i] << " ";
	}
	cout << endl;
}