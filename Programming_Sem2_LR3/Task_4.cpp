#include <iostream>
#include <locale.h>
using namespace std;

int Extended_Euclid(int c, int m)
{
	int q, r, nod, b, a, d, a1 = 0, a2 = 1, b1 = 1, b2 = 0;
	while (m != 0) {
		q = c / m;
		r = c - q * m;
		a = a2 - q * a1;
		b = b2 - q * b1;
		c = m;
		m = r;
		a2 = a1, a1 = a, b2 = b1, b1 = b;
	}
	nod = c, a = a2, b = b2;
	if (nod != 1) {
		cout << "Обратное число не найдено" << endl;
		exit(0);
	}
	return a;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите число c: ";
	int c;
	cin >> c;
	cout << "Введите модуль m: ";
	int m;
	cin >> m;
	cout << "Обратное число: " << Extended_Euclid(c, m) << endl;
}
