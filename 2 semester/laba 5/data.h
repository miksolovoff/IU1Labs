#pragma once
#ifndef DATA_H
#define DATA_H
class data {
	int day;
	int month;
	int year;
public: 
	data(int d, int m, int y);
	data(std::string s);
	int subtr(data fir, data sec);
	bool compare(data fir, data sec);
	int passed(data data_last);
	int objects();
};
#endif // !DATA_H
