#include "stdafx.h"

#include"List.h"


Node::Node() : data(), next(nullptr) { }

Node::Node(Student d) : data(d), next(nullptr) { }


List::List() : head(nullptr), size(0) {}
void List::push(Student x)
{
	if (head == nullptr)
	{
		Node* element = new Node(x);
		head = new Node(x);
		element->next = head;
		head = element;
		size++;
	}
	else
	{
		Node* tmp = head;
		int i = 0;
		while (i < size - 1)
		{
			tmp = tmp->next;
			i++;
		}
		tmp->next = new Node(x);
		tmp->next->next = head;
		size++;
	}
}
void List::pop()
{
	if (size == 0)
		throw Exception();
	Node* tmp = head;
	head = head->next;
	delete tmp;
	size--;
	Node* t = head;
	int i = 0;
	while (i < size - 1)
	{
		t = t->next;
		i++;
	}
	t->next = head;
}
void List::output()
{
	if (size == 0)
		throw Exception();
	Node* tmp = head;
	int i = 0;
	while (i < size)
	{
		cout << "   " << tmp->data;
		tmp = tmp->next;
		i++;
	}
}
Node* List::get_node()
{
	return head;
}
int List::get_size()
{
	return size;
}
ostream& operator<<(ostream& out, const Node& node)
{
	out << node.data;
	return out;
}
Iterator::Iterator(List* element) : current(0)
{
	node = element->get_node();
	size = element->get_size();
}
void Iterator::begin()
{
	if (size == 0)
		throw Exception();
	if (current != 0)
	{
		while (current < size)
		{
			current++;
			node = node->next;
		}
		current = 0;
	}

}
void Iterator::search(Student x)
{
	if (size == 0)
		throw Exception();
	int i = 0;
	while (i < size)
	{
		if (x == node->data)
		{
			cout << "\nElement\n " << x << "\nfound" << endl;
			return;
		}
		if (current == size - 1)
			current = 0;
		else
			current++;
		node = node->next;
		i++;
	}
	cout << "\nElement\n " << x << " \nnot found" << endl;
}
Iterator& Iterator:: operator++()
{
	if (size == 0)
		throw Exception();
	if (size == 1)
		current = 0;
	else
		current++;
	node = node->next;
	return *this;
}
Student Iterator::  operator*() {
	return node->data;
}
void Iterator:: operator = (Student x)
{
	if (size == 0)
		throw Exception();
	node->data = x;
}
Iterator& Iterator:: operator[](int index)
{
	if (size == 0)
		throw Exception();
	Node* tmp = node;
	while (1)
	{
		if (current == index)
		{
			node = tmp;
			return *this;
		}
		tmp = tmp->next;
		if (current == size - 1)
			current = 0;
		else
			current++;
	}
}
void Iterator::shell()
{
	if (size == 0)
		throw Exception();
	int step, i, j;
	Student tmp;
	for (step = size / 2; step > 0; step /= 2)
		for (i = step; i < size; i++)
			for (j = i - step; j >= 0 && (*this)[j].node->data >(*this)[j + step].node->data; j -= step)
			{
				tmp = (*this)[j].node->data;
				(*this)[j].node->data = (*this)[j + step].node->data;
				(*this)[j + step].node->data = tmp;
			}
}
void Iterator::sort_special()
{
	if (size == 0)
		throw Exception();
	int step, i, j;
	Student tmp;
	for (step = size / 2; step > 0; step /= 2)
		for (i = step; i < size; i++)
		{
			for (j = i - step; j >= 0 && (*this)[j].node->data.get_subject() >(*this)[j + step].node->data.get_subject() &&
				(*this)[j].node->data.get_point() - (*this)[j].node->data.get_money() == (*this)[j + step].node->data.get_point() - (*this)[j + step].node->data.get_money(); j -= step)
			{
				tmp = (*this)[j].node->data;
				(*this)[j].node->data = (*this)[j + step].node->data;
				(*this)[j + step].node->data = tmp;
			}
		}

}
ostream& operator<<(ostream& out, const Iterator& it)
{
	out << it.node;
	return out;
}