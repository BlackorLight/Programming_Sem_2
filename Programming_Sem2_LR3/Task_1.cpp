#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double func(double xn) {
	if (xn <= -4) {
		return 2;
	}
	else if (xn < -2) {
		return -(sqrt(-xn * xn - 4 * xn) - 2);
	}
	else if (xn <= 0) {
		return 0;
	}
	else if (xn <= 3) {
		return -xn;
	}
	else if (xn < 5) {
		return sqrt(-xn * xn + 6 * xn - 5) - 1;
	}
	else {
		return -1;
	}
}

int main() {
	double dx = 1;
	double xn = -5;
	double xk = 6;
	cout << "  x					  y" << endl;
	double y;
	for (xn; (xn <= xk); xn += dx) {
		y = func(xn);
		if (xn < 0) {
			if (y < 0) {
				cout << fixed << setprecision(2) << xn << "					" << y << endl;
			}
			else {
				cout << fixed << setprecision(2) << xn << "					" << " " << y << endl;
			}
		}
		else {
			if (y < 0) {
				cout << fixed << setprecision(2) << " " << xn << "					" << y << endl;
			}
			else {
				cout << fixed << setprecision(2) << " " << xn << "					" << " " << y << endl;
			}
		}
	}
}
