#include <iostream>
#include <locale.h>
using namespace std;

int Euclid(int c, int m) {
	int loc = m;
	int u = 0;
	int v = 1;
	int t, g;
	while (c > 0) {
		t = m % c;
		g = u - m / c * v;
		m = c;
		u = v;
		c = t;
		v = g;
	}
	if (u < 0)
		u += loc;
	return u;
}

int Nod(int c, int m) {
	while (c != 0 && m != 0) {
		if (c > m) {
			c %= m;
		}
		else {
			m %= c;
		}
	}
	return c + m;
}

int main() {
	setlocale(LC_ALL, "Rus");
	cout << "Введите число c: ";
	int c;
	cin >> c;
	cout << "Введите модуль m: ";
	int m;
	cin >> m;
	if (Nod(c, m) == 1) {
		cout << "d = " << Euclid(c, m) << endl;
	}
	else {
		cout << "d не существует, так как c и m - не взаимно простые числа" << endl;
	}
}
