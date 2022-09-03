#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct aluno {
	int matricula;
	string nome;
	double media;
};

aluno scanAluno() {
	aluno a;
	cin >> a.matricula; cin.ignore();
	getline(cin, a.nome);
	cin >> a.media; cin.ignore();

	return a;
}

void printAluno(aluno a) {
	cout << a.nome << endl;
	cout << fixed << setprecision(1) << a.media << endl;
}

int main() {
	aluno vec[10];
	int n, m;
	cin >> n;

	for(int i = 0; i < n; i++) {
		vec[i] = scanAluno();
	}

	cin >> m;

	for(int i = 0; i < n; i++) {
		if(vec[i].matricula == m) {
			printAluno(vec[i]);
			return 0;
		}
	}

	cout << "NAO ENCONTRADA";

	return 0;
}