#include <iostream>
#include <locale.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	cout << "Введите основание степени: ";
	int digit;
	cin >> digit;
	cout << "Введите показатель 1:	   ";
	int x;
	cin >> x;
	cout << "Введите показатель 2:	   ";
	int y;
	cin >> y;
	int mod = 10;
	int resault = 1;
	for (int i = 1; i <= x * y; i++) {
		resault *= digit;
		resault %= mod;
	}
	cout << "Последняя цифра числа:	   " << resault << endl;
}
