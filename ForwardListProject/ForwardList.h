#include <iostream>
#pragma once
class ForwardList
{
	struct Node
	{
		int value;
		Node* next;
	};

	Node* head;
	int size;
public:
	ForwardList() : head{ nullptr }, size{ 0 } {}

	int Size();

	void Add(int value);
	void Insert(int index, int value);
	int Delete();
	int Remove(int index);

	Node*& At(int index);
	int& operator[](int index);

	friend std::ostream& operator<<(std::ostream& out, const ForwardList& flist);

	
};

