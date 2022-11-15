#include <iostream>
#include "ForwardList.h"

template <class T>
int ForwardList<T>::Size()
{
	return size;
}

template <class T>
void ForwardList<T>::Add(T value)
{
	Node<T>* nodeNew = new Node<T>();
	nodeNew->value = value;
	nodeNew->next = head;

	head = nodeNew;

	size++;
}

template <class T>
void ForwardList<T>::Insert(int index, T value)
{
	if (index >= size - 1)
	{
		Add(value);
		return;
	}


	Node<T>* nodeCurr = At(index);
	Node<T>* nodeNew = new Node<T>();

	nodeNew->value = value;
	nodeNew->next = nodeCurr->next;
	nodeCurr->next = nodeNew;
}

template <class T>
T ForwardList<T>::Delete()
{
	T value = head->value;

	Node<T>* nodeDel{ head };
	head = head->next;
	delete nodeDel;

	size--;

	return value;
}

template <class T>
T ForwardList<T>::Remove(int index)
{
	if (index >= size - 1)
		return Delete();

	Node<T>* nodeCurr = At(index + 1);
	T value = nodeCurr->next->value;

	Node<T>* nodeDel = nodeCurr->next;
	nodeCurr->next = nodeCurr->next->next;

	delete nodeDel;

	return value;
}

template <class T>
Node<T>*& ForwardList<T>::At(int index)
{
	// if (index > size) return; // заменим на исключение
	Node<T>* nodeCurr{ head };
	for (int i = 0; i < size - 1 - index; i++)
		nodeCurr = nodeCurr->next;

	return nodeCurr;
}

template <class T>
T& ForwardList<T>::operator[](int index)
{
	return At(index)->value;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const ForwardList<T>& flist)
{
	Node<T>* nodeCurr{ flist.head };
	while (nodeCurr)
	{
		out << nodeCurr->value << "\n";
		nodeCurr = nodeCurr->next;
	}
	return out;
}

