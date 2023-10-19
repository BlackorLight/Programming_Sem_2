#include <iostream>
#include <random>
#include <vector>

using namespace std;

vector <int> generator(int k) {
	random_device randu;
	vector <int> vec(k);
	for (auto& i : vec) {
		i = (randu() % 100 + 1);
	}
	return vec;
}

double MX(vector <int> vec, int k) {
	int sum = 0;
	for (auto i : vec) {
		sum += i;
	}
	int resault = 0;
	resault = sum / k;
	return resault;
}

double SKO(vector <int> vec, int k) {
	double MO = MX(vec, k);
	double sum = 0;
	for (auto i : vec) {
		sum += (i - MO) * (i - MO);
	}
	sum /= (k - 1);
	return sqrt(sum);
}

double HI(vector <int> vec, int k) {
	int A[10];
	for (int i = 0; i < 10; i++) {
		A[i] = 0;
	}
	for (auto i : vec) {
		if (i == 0) {
			A[0]++;
		}
		else {
			A[(i - 1) / 10]++;
		}
	}
	double sum = 0;
	double MO = MX(vec, k);
	double sko = SKO(vec, k);
	for (int i = 0; i < 10; i++) {
		double Vexp = k * 10 / sko;	//Теоретическая частота
		double u = ((i + 1) * 10 - MO) / sko;  //Функция Лапласа
		double fi = exp(-u * u / 2) / (sqrt(2 * 3.14)); //Функция Лапласа 
		Vexp *= fi;
		sum += (A[i] - Vexp) * (A[i] - Vexp) / Vexp;
	}
	return sum;
}

void funk(int k) {
	cout << "Размер массива: " << k << endl;
	vector <int> vec = generator(k);
	cout << "MO = " << MX(vec, k) << endl;
	cout << "SKO = " << SKO(vec, k) << endl;
	double a = HI(vec, k);
	cout << "hi = " << a << endl;
	//из таблицы значений критических точек распределения χ2 (хи-квадрат) критерия Пирсона 
	// для 10 интервалов и нормального распределения соотвествует значение 16,9
	if (a > 16, 9) {
		cout << "Генератор рандомных чисел random_device не соотвествует нормальному распределению, т.к полученное значение Xи^2 > 16,9" << endl;
	}
	else {
		cout << "Генератор рандомных чисел random_device  соотвествует нормальному распределению, т.к полученное значение Хи^2 <= 16,9" << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	int k = 50;
	funk(k);
	k = 100;
	funk(k);
	k = 1000;
	funk(k);
}
