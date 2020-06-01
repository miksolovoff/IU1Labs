#include <iostream>
#include "data.h"
int d, m, y;
std::string str;
bool check_int(std::string s) {
	bool flag = true;
	for (int i = 0; i < s.size(); i++) {
		if ((s[i] < '0' || s[i]>'9') && s[i]!='.') {
			flag = false;
			break;
		}
	}
	return flag;
}
bool check_day(std::string s) {
	return (check_int(s) && atoi(s.c_str()) > 0 && atoi(s.c_str()) < 32) ? true : false;
}
bool check_mon(std::string s) {
	return (check_int(s) && atoi(s.c_str()) > 0 && atoi(s.c_str()) < 13) ? true : false;
}
bool check_year(std::string s) {
	return (check_int(s) && atoi(s.c_str()) > 0) ? true : false;
}
bool check_format(std::string s) {
	bool flag = true;
	int l = 0;
	int points = 0;
	for (int r = 0; r < s.size(); r++) {
		if (s[r] == '.') {
			points++;
			if (l == 0) {
				std::string day_t = s.substr(0, r - l);
				l = r;
				if (!check_day(day_t)) {
					flag = false;
					break;
				}
				else {
					std::string month_t = s.substr(l + 1, r - l - 1);
					l = r;
					if (!check_mon(month_t)) {
						flag = false;
						break;
					}
				}
			}
		}
	}
	if (points != 2) flag = false;
	else {
		std::string year_t = s.substr(l + 1, s.size() - l - 1);
		if (!check_year(year_t)) flag = false;
	}
	return flag;
}
void by_int() {
	std::string s1, s2, s3;
	std::cout << "input day\n";
	std::cin >> s1;
	while (!check_day(s1)) {
		std::cout << "try again\n";
		std::cin >> s1;
	}
	d = atoi(s1.c_str());
	std::cout << "input month\n";
	std::cin >> s2;
	while (!check_mon(s2)) {
		std::cout << "try again\n";
		std::cin >> s2;
	}
	m = atoi(s2.c_str());
	std::cout << "input year\n";
	std::cin >> s3;
	while (!check_year(s3)) {
		std::cout << "try again\n";
		std::cin >> s3;
	}
	y = atoi(s3.c_str());
}
void by_string() {
	std::cout << "input data\n";
	std::cin >> str;
	while (!check_format(str)) {
		std::cout << "try again\n";
		std::cin >> str;
	}
}
int main() {
	std::string what;
	bool stop = false;
	for (;;) {
		std::cout << "1 - compare two dates\n";
		std::cout << "2 - difference in days between the first and second dates\n";
		std::cout << "3 - has this date arrived?\n";
		std::cout << "4 - how many hours have passed since that date?\n";
		std::cout << "5 - how many objects created\n";
		std::cout << "6 - exit\n";
		std::cin >> what;
		while (!check_int(what)) {
			std::cout << "try again\n";
			std::cin >> what;
		}
		switch (atoi(what.c_str())) {
		case 1: {
			std::cout << "input first date\n";
			std::cout << "choose method of input\n";
			std::cout << "1 - by int\n";
			std::cout << "2 - by string\n";
			std::string temp;
			std::cin >> temp;
			while (!check_int(temp)) {
				std::cout << "try again\n";
				std::cin >> temp;
			}
			if (temp == "1") {
				by_int();
				data first(d, m, y);
				std::cout << "input second date\n";
				std::cout << "choose method of input\n";
				std::cout << "1 - by int\n";
				std::cout << "2 - by string\n";
				std::string temp;
				std::cin >> temp;
				while (!check_int(temp)) {
					std::cout << "try again\n";
					std::cin >> temp;
				}
				if (temp == "1") {
					by_int();
					data second(d, m, y);
					std::cout << (first.compare(first, second) ? "first >  second\n" : "first <= second\n");
				}
				else if (temp == "2") {
					by_string();
					data second(str);
					std::cout << (first.compare(first, second) ? "first >  second\n" : "first <= second\n");
				}
				else std::cout << "error\n";
			}
			if (temp == "2") {
				by_string();
				data first(str);
				std::cout << "input second date\n";
				std::cout << "choose method of input\n";
				std::cout << "1 - by int\n";
				std::cout << "2 - by string\n";
				std::string temp;
				std::cin >> temp;
				while (!check_int(temp)) {
					std::cout << "try again\n";
					std::cin >> temp;
				}
				if (temp == "1") {
					by_int();
					data second(d, m, y);
					std::cout << (first.compare(first, second) ? "first >  second\n" : "first <= second\n");
				}
				else if (temp == "2") {
					by_string();
					data second(str);
					std::cout << (first.compare(first, second) ? "first >  second\n" : "first <= second\n");
				}
				else std::cout << "error\n";
			}
		}
			  break;
		case 2: {
			std::cout << "input first date\n";
			std::cout << "choose method of input\n";
			std::cout << "1 - by int\n";
			std::cout << "2 - by string\n";
			std::string temp;
			std::cin >> temp;
			while (!check_int(temp)) {
				std::cout << "try again\n";
				std::cin >> temp;
			}
			if (temp == "1") {
				by_int();
				data first(d, m, y);
				std::cout << "input second date\n";
				std::cout << "choose method of input\n";
				std::cout << "1 - by int\n";
				std::cout << "2 - by string\n";
				std::string temp;
				std::cin >> temp;
				while (!check_int(temp)) {
					std::cout << "try again\n";
					std::cin >> temp;
				}
				if (temp == "1") {
					by_int();
					data second(d, m, y);
					std::cout << (first.subtr(first, second) >= 0 ? first.subtr(first, second) : -first.subtr(first, second)) << " days\n";
				}
				else if (temp == "2") {
					by_string();
					data second(str);
					std::cout << (first.subtr(first, second) >= 0 ? first.subtr(first, second) : -first.subtr(first, second)) << " days\n";
				}
				else std::cout << "error\n";
			}
			if (temp == "2") {
				by_string();
				data first(str);
				std::cout << "input second date\n";
				std::cout << "choose method of input\n";
				std::cout << "1 - by int\n";
				std::cout << "2 - by string\n";
				std::string temp;
				std::cin >> temp;
				while (!check_int(temp)) {
					std::cout << "try again\n";
					std::cin >> temp;
				}
				if (temp == "1") {
					by_int();
					data second(d, m, y);
					std::cout << (first.subtr(first, second) >= 0 ? first.subtr(first, second) : -first.subtr(first, second)) << " days\n";
				}
				else if (temp == "2") {
					by_string();
					data second(str);
					std::cout << (first.subtr(first, second) >= 0 ? first.subtr(first, second) : -first.subtr(first, second)) << " days\n";
				}
				else std::cout << "error\n";
			}
		}
			  break;
		case 3: {
			std::cout << "input date\n";
			std::cout << "choose method of input\n";
			std::cout << "1 - by int\n";
			std::cout << "2 - by string\n";
			std::string temp;
			std::cin >> temp;
			while (!check_int(temp)) {
				std::cout << "try again\n";
				std::cin >> temp;
			}
			if (temp == "1") {
				by_int();
				data last(d, m, y);
				std::cout << (last.passed(last)>=0 ? "yes\n" : "no\n");
			}
			else if (temp == "2") {
				by_string();
				data last(str);
				std::cout << (last.passed(last)>=0 ? "yes\n" : "no\n");
			}
			else std::cout << "error\n";
		}
			  break;
		case 4: {
			std::cout << "input date\n";
			std::cout << "choose method of input\n";
			std::cout << "1 - by int\n";
			std::cout << "2 - by string\n";
			std::string temp;
			std::cin >> temp;
			while (!check_int(temp)) {
				std::cout << "try again\n";
				std::cin >> temp;
			}
			if (temp == "1") {
				by_int();
				data last(d, m, y);
				std::cout << (last.passed(last) >= 0 ? last.passed(last) : -last.passed(last)) << " hours\n";
			}
			else if (temp == "2") {
				by_string();
				data last(str);
				std::cout << (last.passed(last) >= 0 ? last.passed(last) : -last.passed(last)) << " hours\n";
			}
			else std::cout << "error\n";
		}
			  break;
		case 5: {
			data data_t(0, 0, 0);
			std::cout << data_t.objects() << " objects created\n";
		}
			break;
		case 6:
			stop = true;
			break;
		}
		if (stop) break;
	}
	return 0;
}