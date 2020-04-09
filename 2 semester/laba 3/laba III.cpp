// 12 вариант
// 1 задача

#include <iostream>
#include <string>
#include "equation_root.h"
using namespace std;
bool check1(string t) { // для проверки на корректность a и b
	bool ok = true;
	int tchk = 0;
	for (int i = 0; i < t.size(); i++) {
		if ((t[i] < '0' || t[i]>'9') && t[i] != '.' && t[0]!='-') {
			ok = false;
			break;
		}
		else if (t[i] == '.') tchk++;
	}
	if (tchk > 1) ok = false;
	return ok;
}
bool check2(string t) { // для проверки на корректность n
	bool ok = true;
	for (int i = 0; i < t.size(); i++) {
		if (t[i] < '0' || t[i]>'9') {
			ok = false;
			break;
		}
	}
	return ok;
}
int main() {
	string t1, t2, t3;
	double A, B;
	int N;
	cout << "Input a, b (a<b), n" << endl;
	cin >> t1 >> t2 >> t3;
	while (!check1(t1) || !check1(t2) || !check2(t3) || atof(t1.c_str())>=atof(t2.c_str())) {
		cout << "Try again to input values" << endl;
		cin >> t1 >> t2 >> t3;
	}
	A = atof(t1.c_str());
	B = atof(t2.c_str());
	N = atoi(t3.c_str());
	double v_b_t = int_by_trap(A, B, N);
	double v_b_p = int_by_parab(A, B, N);
	double v_b_e = int_exact(A, B);
	cout << "Exact value: " << fixed << v_b_e << endl;
	cout << "Value by the trapezoid method: " << fixed << v_b_t << endl;
	cout << "Absolute error: " << fixed << error_abs(v_b_t, v_b_e) << endl;
	cout << "Relative error: " << fixed << error_rel(v_b_t, v_b_e) << '%' << endl;
	cout << "Value by parabola method: " << fixed << v_b_p << endl;
	cout << "Absolute error: " << fixed << error_abs(v_b_p, v_b_e) << endl;
	cout << "Relative error: " << fixed << error_rel(v_b_p, v_b_e) << '%' << endl;
	system("pause");
	return 0;
}

// 2 задача
/*
#include <iostream>
#include <string>
#include <vector>
#include "sort.h"
using namespace std;
bool check_int(vector<string>q) {
	bool ok = true;
	for (int i = 0; i < q.size(); i++) {
		for (int j = 0; j < q[i].size(); j++) {
			if ((q[i][j] < '0' || q[i][j]>'9') && q[i][0]!='-') {
				ok = false;
				break;
			}
		}
	}
	return ok;
}
bool check_float(vector<string>q) {
	bool ok = true;
	for (int i = 0; i < q.size(); i++) {
		int tchk = 0;
		for (int j = 0; j < q[i].size(); j++) {
			if (q[i][j] == '.') tchk++;
			else if ((q[i][j] < '0' || q[i][j]>'9') && q[i][0]!='-') {
				ok = false;
				break;
			}
		}
		if (tchk > 1) {
			ok = false;
			break;
		}
	}
	return ok;
}
bool check_alph(vector<string>q) {
	bool ok = true;
	for (int i = 0; i < q.size(); i++) {
		if (q[i][0] < 'a' || q[i][0]>'z') {
			ok = false;
			break;
		}
	}
	return ok;
}
int main() {
	cout << "Input how many elements in array are (k) and how much to sort (n)" << endl;
	int k, n, type;
	cin >> k >> n;
	cout << "Choose type of array" << endl;
	cout << "1 - int array" << endl;
	cout << "2 - long int array" << endl;
	cout << "3 - float array" << endl;
	cout << "4 - double array" << endl;
	cout << "5 - long double array" << endl;
	cout << "6 - char array" << endl;
	cin >> type;
	switch (type) {
	case 1: {
		int* a;
		a = (int*)malloc(k * sizeof(int));
		cout << "Input array" << endl;
		vector <string> b(k);
		for (int i = 0; i < k; i++) cin >> b[i];
		while (!check_int(b)) {
			cout << "Try again to input values" << endl;
			for (int i = 0; i < k; i++) cin >> b[i];
		}
		for (int i = 0; i < k; i++) a[i] = atoi(b[i].c_str());
		sort(a, n);
		cout << "Sorted array" << endl;
		for (int i = 0; i < k; i++) cout << a[i] << endl;
		free(a);
		break;
	}
	case 2: {
		long int* a;
		a = (long int*)malloc(k * sizeof(long int));
		cout << "Input array" << endl;
		vector<string>b(k);
		for (int i = 0; i < k; i++) cin >> b[i];
		while (!check_int(b)) {
			cout << "Try again to input values" << endl;
			for (int i = 0; i < k; i++) cin >> b[i];
		}
		for (int i = 0; i < k; i++) a[i] = atol(b[i].c_str());
		sort(a, n);
		cout << "Sorted array" << endl;
		for (int i = 0; i < k; i++) cout << a[i] << endl;
		free(a);
		break;
	}
	case 3: {
		float* a;
		a = (float*)malloc(k * sizeof(float));
		cout << "Input array" << endl;
		vector<string>b(k);
		for (int i = 0; i < k; i++) cin >> b[i];
		while (!check_float(b)) {
			cout << "Try again to input values" << endl;
			for (int i = 0; i < k; i++) cin >> b[i];
		}
		for (int i = 0; i < k; i++) a[i] = stof(b[i]);
		sort(a, n);
		cout << "Sorted array" << endl;
		for (int i = 0; i < k; i++) cout << a[i] << endl;
		free(a);
		break;
	}
	case 4: {
		double* a;
		a = (double*)malloc(k * sizeof(double));
		cout << "Input array" << endl;
		vector<string>b(k);
		for (int i = 0; i < k; i++) cin >> b[i];
		while (!check_float(b)) {
			cout << "Try again to input values" << endl;
			for (int i = 0; i < k; i++) cin >> b[i];
		}
		for (int i = 0; i < k; i++) a[i] = atof(b[i].c_str());
		sort(a, n);
		cout << "Sorted array" << endl;
		for (int i = 0; i < k; i++) cout << a[i] << endl;
		free(a);
		break;
	}
	case 5: {
		long double* a;
		a = (long double*)malloc(k * sizeof(long double));
		cout << "Input array" << endl;
		vector<string>b(k);
		for (int i = 0; i < k; i++) cin >> b[i];
		while (!check_float(b)) {
			cout << "Try again to input values" << endl;
			for (int i = 0; i < k; i++) cin >> b[i];
		}
		for (int i = 0; i < k; i++) a[i] = stold(b[i]);
		sort(a, n);
		cout << "Sorted array" << endl;
		for (int i = 0; i < k; i++) cout << a[i] << endl;
		free(a);
		break;
	}
	case 6: {
		char* a;
		a = (char*)malloc(k * sizeof(char));
		cout << "Input array" << endl;
		vector<string>b(k);
		for (int i = 0; i < k; i++) cin >> b[i];
		while (!check_alph(b)) {
			cout << "Try again to input values" << endl;
			for (int i = 0; i < k; i++) cin >> b[i];
		}
		for (int i = 0; i < k; i++) a[i] = b[i][0];
		sort(a, n);
		cout << "Sorted array" << endl;
		for (int i = 0; i < k; i++) cout << a[i] << endl;
		free(a);
		break;
	}
	}
	system("pause");
	return 0;
}
*/
