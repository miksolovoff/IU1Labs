// 1
/*
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main() {
	string name;
	cout << "Input name of file\n";
	cin >> name;
	ifstream ifs;
	ifs.open(name);
	if (!ifs.is_open()) cout << "Impossible open this file\n";
	else {
		int pr_number = -(pow(2, 8 * sizeof(int))) + 1, number = 0, temp = 1, max = 0;
		do {
			ifs >> number;
			if (number < pr_number) temp++;
			else {
				if (temp > max) max = temp;
				temp = 1;
			}
			pr_number = number;
		} while (!ifs.eof());
		if (temp > max) max = temp; // случай, когда большая убывающая последовательность - в конце документа
		if (temp == 1) max = 0;
		ifs.close();
		cout << "Max length is : " << max;
	}
	return 0;	
}
*/
// 2
// Сортировка матрицы размером n*m по убыванию с использованием алгоритма из STL
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
string name;
int n, m, b, c;
void write_matrix(vector <int> a) { // запись матрицы в .bin файл
	fstream ifs;
	ifs.open(name, ios::app | ios::binary);
	if (!ifs.is_open()) cout << "Impossible open this file\n";
	else {
		for (int i = 0; i < n * m; i++) ifs.write((char*)&a[i], sizeof(a[i]));
		ifs.close();
	}
}
void read_matrix() { // считывание матрицы из .bin файла и вывод ее в консоль
	fstream ifs;
	ifs.open(name, ios::in | ios::binary);
	if (!ifs.is_open()) cout << "Impossible open this file\n";
	else{
		int t;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ifs.read((char*)&t, sizeof(t));
				cout << t << ' ';
			}
			cout << '\n';
		}
	}
}
int main() {
	srand(time(NULL));
	cout << "Input name of file for matrix\n";
	cin >> name;
	cout << "Input size of matrix\n";
	cin >> n >> m;
	vector <int> a(n * m);
	cout << "Input range [b, c]\n";
	cin >> b >> c;
	for (int i=0; i<n*m; i++){ // заполнение матрицы
		if (b==0) a[i] = rand() % (c + 1); // [0; c]
		else a[i] = (rand() % (c - b + 1) + b); // [b; c], b!=0
	}
	write_matrix(a);
	read_matrix();
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	remove(name.c_str());
	cout << '\n';
	write_matrix(a);
	read_matrix();
return 0;
}		