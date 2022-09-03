#include <iostream>
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

void printAluno(Aluno a) {
	cout << a.nome << " ";
	cout << (a.nota >= 7.0 ? "aprovado(a) em " : "reprovado(a) em ")
	<< a.disciplina << endl;
}

int main() {
	Aluno aluno = scanAluno();
	printAluno(aluno);

	return 0;
}
