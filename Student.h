#pragma once
#pragma once
#include<iostream>
#include "stdafx.h"

using namespace std;
class Student
{
private:

	int groups;
	int point;
	string subject;
	int money;
public:
	string fio;
	Student();
	Student(string f, int g, int l, int cl);
	void set_fio(string);
	void set_groups(int);
	void set_point(int);
	void set_subject(string);
	void set_money(int);
	string get_fio();
	int get_groups();
	int get_point();
	string get_subject();
	int get_money();
	friend ostream& operator<<(ostream& out, const Student c);
	friend istream& operator>>(istream& in, Student& t);
	friend bool operator==(const Student t1, const Student t2);
	friend bool operator<(const Student t1, const Student t2);
	friend bool operator>(const Student t1, const Student t2);
};