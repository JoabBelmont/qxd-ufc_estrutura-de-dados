#include <iostream>
#include <iomanip>

using namespace std;

double fatorial(int n_) {
    double temp = 1; 
    while (n_ > 0) {
        temp *= n_;
        n_--;
    }

    return temp;
}

double euler(int n_) {
    double temp = 1;
    for (int i = 1; i <= n_; i++) {
        temp = (1 / fatorial(i)) + temp;
    }

    return temp;
}

int main() {
    int n;

    cin >> n;
    cout << fixed << setprecision(6) << euler(n);

    return 0;
}