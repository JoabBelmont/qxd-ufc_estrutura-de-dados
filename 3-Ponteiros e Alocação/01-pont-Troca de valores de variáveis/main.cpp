#include <iostream>

// Implemente a função 'troca'.
void troca(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

}

int main() {
	int x, y;
	std::cin >> x;
	std::cin >> y;

	// Chame a função 'troca' para trocar os valores de x e y.
	troca(&x, &y);

	std::cout << x << " " << y << std::endl;
	return 0;
}