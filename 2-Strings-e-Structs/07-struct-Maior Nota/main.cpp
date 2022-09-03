#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Aluno {
	string nome;
	int matricula;
	string disciplina;
	double nota;
};

Aluno scanAluno() {
	Aluno a;
	cin >> a.nome; cin.ignore();
	cin >> a.matricula; cin.ignore();
	cin >> a.disciplina; cin.ignore();
	cin >> a.nota; cin.ignore();

	return a;
}

void printMaior(Aluno a1, Aluno a2) {
	if(a1.nota > a2.nota) {
		cout << a1.nome << " , "; 
		cout << fixed << setprecision(1) << a1.nota << endl;
	} else if(a2.nota > a1.nota) {
		cout << a2.nome << " , ";
		cout << fixed << setprecision(1) << a2.nota << endl;
	} else {
		cout << a1.nome << " e " << a2.nome << " , "; 
		cout << fixed << setprecision(1) << a1.nota << endl;
	}
}

int main() {
	Aluno aluno1 = scanAluno(); 
	Aluno aluno2 = scanAluno();

	printMaior(aluno1, aluno2);

	return 0;
}