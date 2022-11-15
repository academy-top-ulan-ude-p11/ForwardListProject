#include <iostream>
#pragma once
template <class T>
struct Node
{
	T value;
	Node<T>* next;
};

template <class T>
class ForwardList
{
	Node<T>* head;
	int size;
public:
	ForwardList() : head{ nullptr }, size{ 0 } {}

	int Size();

	void Add(T value);
	void Insert(int index, T value);
	T Delete();
	T Remove(int index);

	Node<T>*& At(int index);
	T& operator[](int index);

	friend std::ostream& operator<<(std::ostream& out, const ForwardList<T>& flist);
};

#include "ForwardList.inl"

