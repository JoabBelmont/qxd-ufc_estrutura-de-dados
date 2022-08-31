#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int matrix[3][3], count = 0;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }

    for(int j = 0; j < 3; j++) {
        for(int i = 0; i < 2; i++) {
            if(matrix[i][j] > matrix[i + 1][j]) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}