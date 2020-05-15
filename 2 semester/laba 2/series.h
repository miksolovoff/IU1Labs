#include <cmath>
#include <iostream>
using namespace std;
int i = 1;
double x_i(int i, double x) { // член из суммы ряда
	double res = pow(x, i);
	res /= i;
	for (int j = 1; j < i; j++) { // коэффициент перед x^i/i
		if (j % 2 == 0) res /= (-j);
		else res *= j;
	}
	return res;
}
double ln_fun_ab(double eps, double x) {
	double sum = 0;
	while (abs(x_i(i, x)) > eps) { // суммирование, пока модуль члена ряда > заданной точности
		sum += x_i(i, x);
		if (x_i(i, x) > x) {
			cout << "Impossible to count approximate function value with such eps" << endl;
			sum = 0;
			break;
		}
		i += 2;
	}
	return sum; // приближенное значение заданной функции
}
double ln_fun_ex(double x) {
	return log(x + sqrt(1 + x * x));
}