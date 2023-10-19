#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>

using namespace std;

double func(double x) {
	return x * x - 3 * sin(x);
}

bool inflect(double a, double b) { //Проверяем разнознаковость функции на концах интервала
	return (func(a) * func(b) < 0);
}

void delenie(vector <pair<double, double>>& intervals_d, vector<double>& roots_delenie, double a, double b) {
	double c = (a + b) / 2; // берем середину отрезка 
	intervals_d.push_back(make_pair(a, b));
	roots_delenie.push_back(c);
	if (fabs(b - a) > 0.0001) {
		if (inflect(a, c)) {
			delenie(intervals_d, roots_delenie, a, c);
		}
		else {
			delenie(intervals_d, roots_delenie, c, b);
		}
	}
}

void Newton(vector <pair<double, double>>& roots_newton, double x) {
	double x1 = x - (func(x)) / (2 * x - 3 * cos(x));  // производная от начальной функции
	roots_newton.push_back(make_pair(x, x1));
	if (fabs(func(x1) - func(x)) > 0.0001) {
		Newton(roots_newton, x1);
	}
}

void Hord(vector <pair<double, double>>& roots_hord, double a, double b) {
	double x1 = a - (b - a) * func(a) / (func(b) - func(a));
	roots_hord.push_back(make_pair(x1, a));
	if (fabs(x1 - a) > 0.0001) {
		Hord(roots_hord, x1, a);
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	vector <pair <double, double>> intervals_d;
	vector <double> roots_delenie;
	double a = -1;
	int num_root = 0;
	for (double b = -0.9;; b += 0.5) {
		if (num_root == 2) break;
		if (inflect(a, b)) {
			delenie(intervals_d, roots_delenie, a, b);
			num_root++;
		}
		a = b;
	}
	cout << "        Половинное деление " << endl;
	int N = 1;

	cout << "| N |    a    |     b    |   b - a   |" << endl;

	cout.setf(ios::fixed);
	cout << setprecision(4);
	for (pair<double, double> v : intervals_d) {
		cout << " " << setw(3) << N << " " << setw(10) << v.first << " " << setw(10) << v.second << " " << setw(10) << fabs(v.second - v.first) << "  " << endl;
		N++;
	}
	N = 1;
	cout << endl;

	cout << "\n         Метод Ньютона" << endl;
	vector <pair<double, double>> roots_newton;
	Newton(roots_newton, -1);
	Newton(roots_newton, 1);


	cout << "| N |     Xn   |   Xn+1     |   Xn+1 - Xn   |" << endl;

	for (pair<double, double> v : roots_newton) {
		cout << " " << setw(3) << N << " " << setw(10) << v.first << " " << setw(10) << v.second << " " << setw(14) << fabs(v.second - v.first) << "  " << endl;
		N++;
	}
	N = 1;
	cout << endl;

	cout << "\n          Метод хорд" << endl;
	vector <pair <double, double>> roots_hord;
	Hord(roots_hord, 0.1, -1);
	Hord(roots_hord, 2, 0.2);

	cout << "| N |     Xn   |   Xn+1   |   Xn+1 - Xn   |" << endl;
	for (pair<double, double> v : roots_hord) {
		cout << " " << setw(3) << N << " " << setw(10) << v.first << " " << setw(10) << v.second << " " << setw(14) << fabs(v.second - v.first) << "  " << endl;
		N++;
	}
	cout << endl;

}
