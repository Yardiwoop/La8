#pragma once
#pragma once
#include<iostream>
#include"Student.h"
#include "stdafx.h"

using namespace std;
class Exception
{
};


class  Node
{
public:
	Student data;
	Node* next;
	Node();
	Node(Student d);
};


class List
{
private:
	Node* head;
	int size;
public:
	List();
	void push(Student x);
	void pop();
	void output();
	Node* get_node();
	int get_size();
	friend ostream& operator<<(ostream& out, const Node& node);
};


class Iterator
{
private:
	Node* node;
	int size;
	int current;
public:
	friend List;
	Iterator(List* element);
	void begin();
	void search(Student x);
	Iterator& operator++();
	Student operator*();
	void operator = (Student x);
	Iterator& operator[](int index);
	void shell();
	void sort_special();
	friend ostream& operator<<(ostream& out, const Iterator& it);
};