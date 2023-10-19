#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	cout << "The equation to be solved: 2^x mod(30203) = 24322\n";
	int a = 2;
	int p = 30203;
	int y = 24322;
	int m = sqrt(p);
	int k = m + 1;
	while (m * k <= p) {
		k++;
	}
	vector <int> firstVec(m);
	vector <int> secondVec(k);
	int n = 0;
	int resault = 1;
	for (auto& it : firstVec) {
		for (int i = 1; i <= n; i++) {
			resault *= a;
			resault %= p;
		}
		n++;
		it = (y * resault) % p;
		resault = 1;
	}
	n = 0;
	for (auto& it : secondVec) {
		for (int i = 1; i <= n * m; i++) {
			resault *= a;
			resault %= p;
		}
		n++;
		it = resault;
		resault = 1;
	}

	int yp = p + 1;

	for (const auto& digitfirst : firstVec) {
		for (const auto& digitsecond : secondVec) {
			if (digitfirst == digitsecond) {
				yp = digitfirst;
				break;
			}
		}
		if (yp < p + 1) {
			break;
		}

	}
	if (yp == p + 1) {
		cout << "Warning" << endl;
		exit(1);
	}
	int i;
	int j;
	int x;
	int res = 1;
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= m; j++) {
			x = i * m - j;
			res = 1;
			for (int q = 1; q <= x; q++) {
				res *= a;
				res %= p;
			}
			if (res == y) {
				cout << "x = " << x << endl;
				exit(0);
			}
			res = 1;
		}
	}
}

