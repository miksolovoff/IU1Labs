#include <iostream>
#include <cmath>
double minor (double** aa, int e, int r, int pos1, int pos2) {
	double M[4];
	int temp = 0;
	for (int i = 0; i < e; i++) {
		for (int j = 0; j < r; j++) {
			if (i != pos1 && j != pos2) {
				M[temp] = aa[i][j];
				temp++;		
			}
		}
	}
	return M[0] * M[3] - M[1] * M[2];
}
double det(double** aa, int n, int m) { 
	return aa[0][0] * minor(aa, m, n, 0, 0) - aa[0][1] * minor(aa, m, n, 0, 1) + aa[0][2] * minor(aa, m, n, 0, 2);
}
double** reverse_matrix(double** aa, int n, int m) { 
	double** answ;
	answ = (double**)malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) answ[i] = (double*)malloc(m * sizeof(double));
	double det_t = det(aa, n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			answ[j][i] = pow(-1, i+j)*minor(aa, n, m, i, j) / det_t; 
		}
	}
	return answ;
}