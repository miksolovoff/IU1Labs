// В 13, 24 и 68 строках введены корректировки, позволяющие работать с отрицательными входными данными
// 1 задача
/*
#include <iostream>
#include "series.h"
#include <string>
using namespace std;
double x, eps;
bool check(string a, string b) {
	bool res = true;
	int tchk = 0;
	for (int i = 0; i < a.size(); i++) {
		if ((a[i] < '0' || a[i]>'9') && (a[i]!='.') && (a[0]!='-')) {
			res = false;
			break;
		}
		if (a[i] == '.') tchk++;
	}
	if (res) {
		if (tchk > 1) res = false;
		else {
			tchk = 0;
			for (int i = 0; i < b.size(); i++) {
				if ((b[i] < '0' || b[i]>'9') && (b[i] != '.') && (b[0]!='-')) {
					res = false;
					break;
				}
				if (b[i] == '.') tchk++;
			}
			if (res) {
				if (tchk > 1) res = false;
			}
		}
	}
	return res;
}
int main() {
	cout << "Input x and eps\n";
	string t1, t2;
	cin >> t1 >> t2;
	while (!check(t1, t2)) { // проверка входных данных
		cout << "Try again to input values" << endl;
		cin >> t1 >> t2;
	}
	x = atof(t1.c_str());
	eps = atof(t2.c_str());
	double res1 = ln_fun_ab(eps, x);
	double res2 = ln_fun_ex(x);
	cout << "Approximate function value: " << res1 << endl;
	cout << "Exact function value: " << res2 << endl;
	cout << "Absolute error: " << (res2-res1) << endl;
	cout << "Relative error: " << ((res2 - res1) / res2) << endl;
	system("pause");
}
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "matrix.h"
using namespace std;
bool check(vector <string> a_s) {
	bool res = true;
	for (int i = 0; i < 9; i++) {
		int tchk = 0;
		for (int j = 0; j < a_s[i].size(); j++) {
			if ((a_s[i][j] < '0' || a_s[i][j]>'9') && (a_s[i][j] != '.') && (a_s[i][0]!='-')) {
				res = false;
				break;
			}
			if (a_s[i][j] == '.') tchk++;
		}
		if (tchk > 1) {
			res = false;
			break;
		}
	}
	return res;
}
int main() {
	int m=3, n=3, k=3, l=3;
	vector <string> a_S(9); // для обработки ошибочного ввода A
	vector <string> b_S(9); // для обработки ошибочного ввода B
	cout << "Input 3x3 matrix A" << endl;
	for (int i = 0; i < 9; i++) {
		cin >> a_S[i];
	}
	while (!check(a_S)) {
		cout << "Try again input matrix A" << endl;
		for (int i = 0; i < 9; i++) cin >> a_S[i];
	}
	double** a;
	a = (double**)malloc(m * sizeof(double));
	for (int i = 0; i < m; i++) {
		a[i] = (double*)malloc(n * sizeof(double));
	}
	int temp_t = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = atof(a_S[temp_t].c_str());
			temp_t++;
		}
	}
	cout << "Input 3x3 matrix B" << endl;
	for (int i = 0; i < 9; i++) {
		cin >> b_S[i];
	}
	while (!check(b_S)) {
		cout << "Try again input matrix B" << endl;
		for (int i = 0; i < 9; i++) cin >> b_S[i];
	}
	double** b;
	b = (double**)malloc(k * sizeof(double));
	for (int i = 0; i < k; i++) {
		b[i] = (double*)malloc(l * sizeof(double));
	}
	temp_t = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < l; j++) {
			b[i][j] = atof(b_S[temp_t].c_str());
			temp_t++;
		}
	}
	if (det(a, m, n) == 0 && det(b, m, n) == 0) cout << "The inverse matrix A does not exist" << endl 
		                                             << "The inverse matrix B does not exist" << endl;
	else if (det(a, m, n)!=0 && det(b, m, n)!=0){
		cout << "A^-1 matrix:" << endl;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << left << setw(15) << reverse_matrix(a, m, n)[i][j] << ' ';
			}
			cout << endl;
		}
		cout << "B^-1 matrix:" << endl;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << left << setw(15) << reverse_matrix(b, m, n)[i][j] << ' ';
			}
			cout << endl;
		}
	}
	else if (det(a, m, n) != 0 && det(b, m, n) == 0) {
		cout << "A^-1 matrix:" << endl;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << left << setw(15) << reverse_matrix(a, m, n)[i][j] << ' ';
			}
			cout << endl;
		}
		cout << "The inverse matrix B does not exist" << endl;
	}
	else {
		cout << "The inverse matrix A does not exist" << endl;
		cout << "B^-1 matrix:" << endl;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << left << setw(15) << reverse_matrix(b, m, n)[i][j] << ' ';
			}
			cout << endl;
		}
	}
	for (int i = 0; i < 3; i++) {
		free(a[i]);
		free(b[i]);
	}
	free(a);
	free(b);
	system("pause");
	return 0;
}
