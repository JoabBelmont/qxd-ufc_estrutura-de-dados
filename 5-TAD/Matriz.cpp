// Arquivo de Implementacao do TAD Matriz
#include <iostream>
#include <iomanip>
#include "Matriz.h"
using namespace std;

// Aloca espaco dinamicamente para matriz com m linhas e n colunas
Matriz::Matriz(int m, int n) {
	lin = m;
	col = n;
	mat = new int*[n];
	for(int i = 0; i < n; i++) {
		mat[i] = new int[m] { 0 }; // Inicializa
	}
}

// Destrutor: Libera a memoria que foi alocada dinamicamente no construtor
Matriz::~Matriz() {
	for(int i = 0; i < lin; i++) {
		delete[] mat[i];
	}
	delete[] mat;
	cout << "Matriz liberada." << endl;
}

// Retorna o numero de linhas da matriz
int Matriz::linhas() {
	return lin;
}

// Retorna o numero de colunas da matriz
int Matriz::colunas() { 
	return col;
}

// Retorna o valor da celula [i][j] da matriz
int Matriz::getValor(int i, int j) {
	return mat[i][j];
}

// Atribui valor a celula [i][j] da matriz
void Matriz::setValor(int valor, int i, int j) {
	this->mat[i][j] = valor;
}

// Imprimir a matriz 
void Matriz::print() {
	for(int i = 0; i < lin; i++) {
		for(int j = 0; j < col; j++) {
			cout << setw(7) << mat[i][j];
		}
		cout << "\n";
	}
}

// Soma matrizes
Matriz *Matriz::soma(Matriz& B) {
	if(!(B.lin == lin && B.col == col)) {
		cout << "Não eh possivel realizar a soma." << endl;
		return nullptr;
	}
	Matriz * C = new Matriz(lin, col);
	for(int i = 0; i < lin; i++) {
		for(int j = 0; j < col; j++) {
			C->setValor((getValor(i, j) + B.getValor(i, j)), i, j);
		}
	}
	return C;
}

// Multiplica matrizes
Matriz *Matriz::multiplica(Matriz& B) {
	Matriz * C = new Matriz(lin, B.col);
	int acc { 0 };

	if(B.lin != col) {
		cout << "Não eh possivel realizar a multiplicação." << endl;
		return nullptr;
	}
	for(int i = 0; i < lin; i++) {
		for(int j = 0; j < B.col; j++) {
			for(int k = 0; k < B.lin; k++) {
				acc += getValor(i, k) * B.getValor(k, j);
			}
			C->setValor(acc, i, j);
			acc = 0;
		}
	}
	return C;
}