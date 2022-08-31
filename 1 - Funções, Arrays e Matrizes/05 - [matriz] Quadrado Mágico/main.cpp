#include <iostream>
#include <iomanip>

using namespace std;

int setAllInVector(int *_v, int _n) { //Seta todos os índices do vetor para o valor especificado
    for(int i = 0; i < 3; i++) {
        _v[i] = _n;
    }
}

bool allAreEqual(int *_v) { //Verifica se todos os valores no vetor são iguais
    for(int i = 0; i < 2; i++) {
        if(_v[i] != _v[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int matrix[3][3];
    int sum[3], count = 0;

    setAllInVector(sum, 0);

    for(int i = 0; i < 3; i++) { //Dá entrada na matriz
        for(int j = 0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }

    //-------------LINHAS-------------
    for(int i = 0; i < 3; i++) { //Soma os valores das linhas
        for(int j = 0; j < 3; j++) {
            sum[i] = sum[i] + matrix[i][j];
        }
    }
    if(allAreEqual(sum)) 
        count++;
    else {
        cout << "nao" << endl;
        return 0;
    }
    setAllInVector(sum, 0);

    //-------------COLUNAS-------------
    for(int j = 0; j < 3; j++) { //Soma os valores das colunas
        for(int i = 0; i < 3; i++) {
            sum[j] = sum[j] + matrix[i][j];
        }
    }
    if(allAreEqual(sum)) 
        count++;
    else {
        cout << "nao" << endl;
        return 0;
    }
    setAllInVector(sum, 0);

    //-------------DIAGONAIS-------------
    for(int i = 0, j = 0; i < 3; i++, j++) { //Principal
        sum[0] += matrix[i][j];
    }
    for(int i = 0, j = 2; i < 3; i++, j--) { //Secundária
        sum[1] += matrix[i][j]; 
    }
    if(sum[0] == sum[1])
        count++;
    else {
        cout << "nao" << endl;
        return 0;
    }
    
    if(count == 3) {
        cout << "sim" <<endl;
    }

    return 0;
}