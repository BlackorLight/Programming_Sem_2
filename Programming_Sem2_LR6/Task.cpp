#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


int main() {
	vector <vector<double>> A = { { -1.19, -0.04, 0.21, -18, -1.24 },
	{ 0.25, -1.23, -0.21, -0.09, 1.21 },
	{ -0.21, -0.21, 0.8, -0.13, 2.56 },
	{ 0.15, -1.31, 0.06, 1.21, -1.19 } };
	vector <vector<double>> U = { { 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 } };
	vector <vector<double>> L = { { 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 } };

	int n = 4;

	for (int i = 0; i < n; i++) {
		L[i][0] = A[i][0];
	}

	for (int i = 0; i < n + 1; i++) {
		U[0][i] = A[0][i] / L[0][0];
	}

	for (int k = 1; k < n; k++)
	{
		for (int i = k; i < n; i++) {
			double sum = 0;
			for (int j = 0; j < k; j++) {
				sum += L[i][j] * U[j][k];
			}
			L[i][k] = A[i][k] - sum;
		}

		for (int j = k; j < n + 1; j++) {
			double sum = 0;
			for (int m = 0; m < k; m++) {
				sum += L[k][m] * U[m][j];
			}
			U[k][j] = (A[k][j] - sum) / L[k][k];
		}
	}

	vector<double> X = { 0, 0, 0, 0 };

	X[3] = U[3][4];
	for (int i = n - 2; i >= 0; i--) {
		double sum = 0;
		for (int k = i + 1; k < n; k++) {
			sum += U[i][k] * X[k];
		}
		X[i] = U[i][n] - sum;
	}

	cout << "First Matrix:" << endl;
	for (auto i : A) {
		for (auto j : i) {
			cout << fixed;
			cout.precision(3);
			cout << setw(10) << j << "     ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "Matrix L:" << endl;
	for (auto i : L) {
		for (auto j : i) {
			cout << fixed;
			cout.precision(3);
			cout << setw(10) << j << "     ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "Matrix U:" << endl;
	for (auto i : U) {
		for (auto j : i) {
			cout << fixed;
			cout.precision(3);
			cout << setw(10) << j << "     ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "Roots SLAU:" << endl;
	for (auto j : X) {
		cout << fixed;
		cout.precision(3);
		cout << setw(10) << j << "     ";
	}
	cout << endl;
	cout << "Zeydel" << endl;

	int N = 0;
	vector<double> f;
	f.push_back(U[0][4]);
	f.push_back(U[1][4]);
	f.push_back(U[2][4]);
	f.push_back(U[3][4]);
	vector<double> Xk = f;
	vector<double> Xkpost(4);
	cout << N;
	for (auto j : Xk) {
		cout << fixed;
		cout.precision(3);
		cout << setw(10) << j << "     ";
	}

	cout << endl;
	while (1) {
		Xkpost[0] = (f[0] - U[0][1] * Xk[1] - U[0][2] * Xk[2] - U[0][3] * Xk[3]) / U[0][0];
		Xkpost[1] = (f[1] - U[1][0] * Xk[0] - U[1][2] * Xk[2] - U[1][3] * Xk[3]) / U[1][1];
		Xkpost[2] = (f[2] - U[2][0] * Xk[0] - U[2][1] * Xk[1] - U[2][3] * Xk[3]) / U[2][2];
		Xkpost[3] = (f[3] - U[3][0] * Xk[0] - U[3][1] * Xk[1] - U[3][2] * Xk[2]) / U[3][3];
		N++;
		cout << N;
		for (auto j : Xkpost) {
			cout << fixed;
			cout.precision(3);
			cout << setw(10) << j << "     ";
		}
		cout << abs(Xk[0] - Xkpost[0]);
		if (abs(Xk[0] - Xkpost[0]) < 0.001) {
			cout << endl;
			break;
		}
		Xk = Xkpost;
		cout << endl;

	}
}
