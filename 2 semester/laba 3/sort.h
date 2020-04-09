#pragma once
int* sort(int* a, int n) {
	for (int i = 0; i < n; i++) {
		int temp = n - 1 - i;
		int min_el = a[temp];
		int min_pos = temp;
		do {
			if (a[temp] < min_el) {
				min_el = a[temp];
				min_pos = temp;
			}
			temp--;
		} while (temp != -1);
		int r = min_el;
		r = a[n - 1 - i];
		a[n - 1 - i] = a[min_pos];
		a[min_pos] = r;
	}
	return a;
}
long int* sort(long int* a, int n) {
	for (int i = 0; i < n; i++) {
		int temp = n - 1 - i;
		long int min_el = a[temp];
		int min_pos = temp;
		do {
			if (a[temp] < min_el) {
				min_el = a[temp];
				min_pos = temp;
			}
			temp--;
		} while (temp != -1);
		long int r = min_el;
		r = a[n - 1 - i];
		a[n - 1 - i] = a[min_pos];
		a[min_pos] = r;
	}
	return a;
}
float* sort(float* a, int n) {
	for (int i = 0; i < n; i++) {
		int temp = n - 1 - i;
		float min_el = a[temp];
		int min_pos = temp;
		do {
			if (a[temp] < min_el) {
				min_el = a[temp];
				min_pos = temp;
			}
			temp--;
		} while (temp != -1);
		float r = min_el;
		r = a[n - 1 - i];
		a[n - 1 - i] = a[min_pos];
		a[min_pos] = r;
	}
	return a;
}
double* sort(double* a, int n) {
	for (int i = 0; i < n; i++) {
		int temp = n - 1 - i;
		double min_el = a[temp];
		int min_pos = temp;
		do {
			if (a[temp] < min_el) {
				min_el = a[temp];
				min_pos = temp;
			}
			temp--;
		} while (temp != -1);
		double r = min_el;
		r = a[n - 1 - i];
		a[n - 1 - i] = a[min_pos];
		a[min_pos] = r;
	}
	return a;
}
long double* sort(long double* a, int n) {
	for (int i = 0; i < n; i++) {
		int temp = n - 1 - i;
		long double min_el = a[temp];
		int min_pos = temp;
		do {
			if (a[temp] < min_el) {
				min_el = a[temp];
				min_pos = temp;
			}
			temp--;
		} while (temp != -1);
		long double r = min_el;
		r = a[n - 1 - i];
		a[n - 1 - i] = a[min_pos];
		a[min_pos] = r;
	}
	return a;
}
char* sort(char* a, int n) {
	for (int i = 0; i < n; i++) {
		int temp = n - 1 - i;
		char min_el = a[temp];
		int min_pos = temp;
		do {
			if (a[temp] < min_el) {
				min_el = a[temp];
				min_pos = temp;
			}
			temp--;
		} while (temp != -1);
		char r = min_el;
		r = a[n - 1 - i];
		a[n - 1 - i] = a[min_pos];
		a[min_pos] = r;
	}
	return a;
}
