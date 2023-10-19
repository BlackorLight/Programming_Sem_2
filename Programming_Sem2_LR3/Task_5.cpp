#include <iostream>
#include <locale.h>
#include <string.h>
#include <random>
#include <time.h>

using namespace std;


int Bob(int g, int m, int y)
{
	int k = 1;
	for (int i = 1; i <= y; i++) {
		k *= g;
		k %= m;
	}
	cout << "Число Боба: " << k << endl;
	return k;
}

int Bob2(int xb, int m, int y) {
	int z = 0;
	int loc = m;
	int v = 1;
	int t, g;
	while (y > 0) {
		t = loc % y;
		g = z - loc / y * v;
		loc = y;
		z = v;
		y = t;
		v = g;
	}
	if (z < 0) {
		z += m;
	}

	cout << "Обратное число Боба: " << z << endl;

	int k = 1;
	for (int i = 1; i <= z; i++) {
		k *= xb;
		k %= m + 1;
	}
	cout << "Ключ Боба: " << k << endl;
	return k;
}

int Nod(int y, int m) {
	while (y != 0 && m != 0) {
		if (y > m) {
			y %= m;
		}
		else {
			m %= y;
		}
	}
	return y + m;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	char Stroka[] = { "Alice wants to pass this line to Bob" };
	cout << "Алиса передаст Бобу строку: " << Stroka << endl;
	int g = 1301;
	int m = 1297;
	int x = rand() + 1000;
	int k = 1;
	for (int i = 1; i <= x; i++) {
		k *= g;
		k %= m;
	}
	cout << "Закрытый ключ: " << k << endl;
	for (int i = 0; i < strlen(Stroka); i++)
		Stroka[i] += k;
	cout << "Закодированная строка, которую Алиса передаст Бобу:	" << Stroka << endl;
	int y = rand() + 1000;
	while (Nod(y, m - 1) != 1) {
		y = rand();
	}
	int yb = Bob(g, m, y);
	int xb = 1;
	for (int i = 1; i <= x; i++) {
		xb *= yb;
		xb %= m;
	}
	cout << "Число Алисы: " << xb << endl;
	if (k == Bob2(xb, m - 1, y)) {
		cout << "Ключи совпадают" << endl;
	}
	else {
		cout << "Ключи не совпадают" << endl;
	}
	cout << "Боб при декодировке получил строку: " << endl;
	for (int i = 0; i < strlen(Stroka); i++)
		Stroka[i] -= k;
	cout << Stroka << endl;

}
