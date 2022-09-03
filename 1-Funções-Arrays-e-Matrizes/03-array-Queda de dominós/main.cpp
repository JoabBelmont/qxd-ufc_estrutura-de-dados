#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, vec[50];
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> vec[i]; // informa o número de dominós
    }

    for(int i = 0; i < n - 1; i++) { // 
        if(vec[i] > vec[i + 1]) { // se não estiverem crescentes, encerra o programa
            cout << "precisa de ajuste" << endl;
            return 0;
        }
    }
    cout << "ok" << endl; // se sim, executa até o final
    return 0;
}