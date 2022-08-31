#include <iostream>
#include <iomanip>

using namespace std;

bool primo(int n_) {
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
            cout << numA << endl;
        }
    }

    return 0;
}