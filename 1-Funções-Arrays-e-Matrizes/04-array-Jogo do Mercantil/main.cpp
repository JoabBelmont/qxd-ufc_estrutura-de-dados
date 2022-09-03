#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int prodct_qnty, wins_1st = 0, wins_2nd = 0;
    float prodct_value[50], guess_1st[50];
    char choice_2nd[50];

    cin >> prodct_qnty;

    for(int i = 0; i < prodct_qnty; i++) {
        cin >> prodct_value[i]; // informa o valor real do produto
    }
    for(int i = 0; i < prodct_qnty; i++) {
        cin >> guess_1st[i]; // imforma o chute do primeiro contestante
    }
    for(int i = 0; i < prodct_qnty; i++) {
        cin >> choice_2nd[i]; // imforma a escolha do segundo contestante (maior ou menor)
    }

    for(int i = 0; i < prodct_qnty; i++) {
        if(prodct_value[i] == guess_1st[i]) { // se igual ao valor do produto, incrementa as vitórias do primeiro contestante
            wins_1st++;
            continue; 
        }
        if(choice_2nd[i] == 'M' && prodct_value[i] > guess_1st[i] || choice_2nd[i] == 'm' && prodct_value[i] < guess_1st[i]) {
            wins_2nd++; // se a escolha do segundo contestante for certa, incrementa as do segundo contestante
            continue;
        }
        wins_1st++; // se não, o primeiro contestante recebe um ponto
    }

    if(wins_1st == wins_2nd)
        cout << "empate";
    else if(wins_1st > wins_2nd)
        cout << "primeiro";
    else
        cout << "segundo";

    return 0;
}