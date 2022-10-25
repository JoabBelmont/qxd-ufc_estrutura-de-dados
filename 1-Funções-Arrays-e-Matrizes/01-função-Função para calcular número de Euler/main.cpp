#include <iostream>
#include <iomanip>

using namespace std; 

double fatorial(int n_) { // retorna o fatorial do número "n"
    double temp = 1; 
    while (n_ > 0) {
        temp *= n_;
        n_--;
    }

    return temp;
}

double euler(int n_) { // retorna a soma até o enésimo da equação de euler
    double temp = 1; 
    for (int i = 1; i <= n_; i++) {
        temp = (1 / fatorial(i)) + temp;
    }

    return temp;
}

int main() {
    int n;

    cin >> n;
    cout << fixed << setprecision(6) << euler(n); // só imprime até o sexto dígito

    return 0;
}
