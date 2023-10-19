#include <iostream>
#include <locale.h>
using namespace std;

int NOD(int a, int b) {
	while (a != 0 && b != 0) {
		if (a > b) {
			a %= b;
		}
		else {
			b %= a;
		}
	}
	return a + b;
}

int mod(int number, int deg, int p) {
	int res = 1;
	if (NOD(number, p) != 1 || deg != p - 1) {
		for (int i = 1; i <= deg; i++) {
			res = res * number;
			res = res % p;
		}
	}
	//cout << res << endl; Значение числа по модулю для сравнения
	return res;
}

int main() {
	setlocale(LC_ALL, "Rus");
	cout << "Программа сравнивает числа a в степени x и b в степени y по модулю p" << '\n';
	cout << "Введите число a: ";
	int a;
	cin >> a;
	cout << "Введите степень числа a: ";
	int a_deg;
	cin >> a_deg;
	cout << "Введите число b: ";
	int b;
	cin >> b;
	cout << "Введите степень числа b: ";
	int b_deg;
	cin >> b_deg;
	cout << "Введите p: ";
	int p;
	cin >> p;
	if (mod(a, a_deg, p) == mod(b, b_deg, p)) {
		cout << a << " в степени " << a_deg << " равно " << b << " в степени " << b_deg << " по модулю " << p << endl;
	}
	else {
		cout << a << " в степени " << a_deg << " не равно " << b << " в степени " << b_deg << " по модулю " << p << endl;
	}
}
