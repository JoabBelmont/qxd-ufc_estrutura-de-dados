#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void prints(vector<int> a, int n);
void counterPrint(vector<int> a, int n);
void inv(vector<int> v, int c, int d);
int sum(vector<int> a,int n);
int mult(vector<int> a, int n);
int smlrVect(vector<int> a, int n);
 
int main() {
	string txt;
	getline(cin, txt);

	stringstream ss;
	ss << txt;

	vector<int> vet;
	int token;

	while(ss >> token)
		vet.push_back(token);
 
	std::cout << "vet : [ ";
	prints(vet, vet.size());
	std::cout << "]";
	std::cout << endl;

	std::cout << "rvet: [ ";
	counterPrint(vet, vet.size());
	std::cout << "]";
	std::cout << endl;
	
	std::cout <<"sum : " <<sum(vet, vet.size())<< endl;
	std::cout <<"mult: "<< mult(vet, vet.size()) << endl;
	std::cout <<"min : " << smlrVect(vet, vet.size()) << endl;
	std::cout << "inv : [ ";
	counterPrint(vet, vet.size());
	std::cout << "]";
	std::cout << endl;
}

void prints(vector<int> a, int n) {
	if(n == 1) { std::cout << a[n - 1] << " "; }
	else {
		prints(a, n - 1);
		std::cout << a[n - 1] << " ";
	}
}

void counterPrint(vector<int> a, int n) {
	if(n == 1) { std::cout << a[n - 1] << " "; } 
	else {
		std::cout << a[n - 1] << " ";
		counterPrint(a, n - 1);
	}

}

void inv(vector<int> v, int c, int d) {
	if(c < d) {
		int aux = v[c];
		v[c] = v[d - 1];
		v[d - 1] = aux;
		inv(v, c + 1, d - 1);
	}
}

int sum(vector<int> a,int n) {
	if(n == 1) { return a[n - 1]; }
	else{ return a[n - 1] + sum(a, n - 1); }
}

int mult(vector<int> a, int n) {
	if(n == 1) { return a[n - 1]; }
	else { return a[n - 1] * mult(a, n - 1); }
}

int smlrVect(vector<int> a, int n) {
	if(n == 1) {
		return a[n - 1];
	} else {
		int menor = smlrVect(a, n - 1);
		if(menor < a[n - 1] ){ return menor; }
		else{
			return a[n - 1];
		}
	}
}