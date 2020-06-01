#include <string>
#include <ctime>
#include "data.h"
int d_in_m[12] = { 31, 28, 31, 30,
				   31, 30, 31, 31,
				   30, 31, 30, 31 };
int how_many_obj = 0;
bool leap(int y) {
	bool flag = false;
	if (y % 4 != 0) flag = false;
	else {
		if (y % 100 != 0) flag = true;
		else flag = y % 400 == 0 ? true : false;
	}
	return flag;
}
data::data(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
	how_many_obj++;
}
data::data(std::string s) {
	day = 0, month = 0;
	int l = 0;
	for (int r = 0; r < s.size(); r++) {
		if (s[r] == '.') {
			if (l == 0) {
				day = atoi(s.substr(0, r - l).c_str());
				l = r;
			}
			else {
				month = atoi(s.substr(l + 1, r - l - 1).c_str());
				l = r;
			}
		}
	}
	year = atoi(s.substr(l + 1, s.size() - l - 1).c_str());
	how_many_obj++;
}
int data::subtr(data fir, data sec) { // разница в днях между первой и второй датой
	int fir_days = 0, sec_days = 0;
	for (int i = 0; i < fir.year - 1; i++) {
		for (int j = 0; j < 12; j++) {
			if (leap(i) && j == 1) fir_days += 29;
			else fir_days += d_in_m[j];
		}
	}
	for (int i = 0; i < fir.month - 1; i++) {
		if (leap(fir.year) && i == 1) fir_days += 29;
		else fir_days += d_in_m[i];
	}
	fir_days += fir.day;
	for (int i = 0; i < sec.year - 1; i++) {
		for (int j = 0; j < 12; j++) {
			if (leap(i) && j == 1) sec_days += 29;
			else sec_days += d_in_m[j];
		}
	}
	for (int i = 0; i < sec.month - 1; i++) {
		if (leap(sec.year) && i == 1) sec_days += 29;
		else sec_days += d_in_m[i];
	}
	sec_days += sec.day;
	return fir_days - sec_days;
}
bool data::compare(data fir, data sec) { // первая дата больше второй
	if (subtr(fir, sec) > 0) return true;
	else return false;
}
int data::passed(data data_last) {
	time_t t = time(NULL);
	struct tm now;
	localtime_s(&now, &t);
	data data_now(now.tm_mday, now.tm_mon, now.tm_year + 1900);
	return subtr(data_now, data_last) * 24;
}
int data::objects() {
	return how_many_obj;
}