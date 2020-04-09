#pragma once
#include <cmath>
double f(double x) {
	return (exp(x) - exp(-x)) / 2;
}

double F(double x) {
	return (exp(x) + exp(-x)) / 2;

}
double int_by_trap(double a, double b, int n) {
	double sum = 0;
	double dx = (b - a) / n;
	for (int i = 1; i <= n - 1; i++) {
		double xi = a + i * dx;
		sum += f(xi);
	}
	sum += (f(a) + f(b)) / 2;
	sum *= dx;
	return sum;
}
double int_by_parab(double a, double b, int n) {
	double sum = 0;
	double dx = (b - a) / n;
	for (int i = 1; i <= n; i++) {
		double xi = a + i * dx;
		if (i != n) sum += f(xi);
		sum += 2 * f(xi - dx / 2);
	}
	sum += (f(a) + f(b)) / 2;
	sum *= dx / 3;
	return sum;
}
double int_exact(double a, double b) {
	return F(b) - F(a);
}
double error_abs(double m, double n) {
	return abs(m - n);
}
double error_rel(double m, double n) {
	return 100*abs(m - n) / n;
}
