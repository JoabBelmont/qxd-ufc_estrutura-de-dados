#include <iostream>
#include <iomanip>

using namespace std; 

bool primo(int n_) { // diz se um número é primo ou não
    for (int i = 2; i < n_; i++) {
        if(n_ % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int numA, numB;
    cin >> numA >> numB;

    for (numA; numA <= numB; numA++) {
        if(primo(numA)) {
            cout << numA << endl; // imprime a soma de todos os números primos até o úlitmo número informado
        }
    }

    return 0;
}