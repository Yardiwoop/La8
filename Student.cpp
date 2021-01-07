#include "stdafx.h"

#include "Student.h"

Student::Student() : fio("-"), groups(0), point(0), money(0) {}
Student::Student(string f, int g, int l, int cl) : fio(f), groups(g), point(l), money(cl) {}
void Student::set_fio(string f)
{
	fio = f;
}
void Student::set_groups(int g)
{
	groups = g;
}
void Student::set_point(int l)
{
	point = l;
}
void Student::set_subject(string s)
{
	subject = s;
}
void Student::set_money(int cl)
{
	money = cl;
}
string Student::get_fio()
{
	return fio;
}
int Student::get_groups()
{
	return groups;
}
int Student::get_point()
{
	return point;
}
string Student::get_subject()
{
	return subject;
}
int Student::get_money()
{
	return money;
}
ostream& operator<<(ostream& out, const Student t)
{
	//	out << "\nFull name - " << t.fio << "\nNumber of groups - " << t.groups << "\nNumber of point per subject - " << t.point << "\nSubject - " << t.subject << "\nNumber of current point - " << t.money << endl;
	return out;
}
istream& operator>>(istream& in, Student& t)
{
	//in >> t.fio;
	in >> t.groups;
	in >> t.point;
	//in >> t.subject;
	return in;
}
bool operator==(Student t1, Student t2) {
	if (t1.point - t1.money == t2.point - t2.money)
		return true;
	else
		return false;
}
bool operator<(const Student t1, const Student t2)
{
	if (t1.point - t1.money < t2.point - t2.money)
		return true;
	else
		return false;
}
bool operator>(const Student t1, const Student t2)
{
	if (t1.point - t1.money > t2.point - t2.money)
		return true;
	else
		return false;
}
