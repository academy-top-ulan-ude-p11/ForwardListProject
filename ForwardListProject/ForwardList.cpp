#include "ForwardList.h"

int ForwardList::Size()
{
	return size;
}

void ForwardList::Add(int value)
{
	Node* nodeNew = new Node();
	nodeNew->value = value;
	nodeNew->next = head;

	head = nodeNew;

	size++;
}

void ForwardList::Insert(int index, int value)
{
	if (index >= size - 1)
	{
		Add(value);
		return;
	}
		

	Node* nodeCurr = At(index);
	Node* nodeNew = new Node();

	nodeNew->value = value;
	nodeNew->next = nodeCurr->next;
	nodeCurr->next = nodeNew;
}

int ForwardList::Delete()
{
	int value = head->value;

	ForwardList::Node* nodeDel{ head };
	head = head->next;
	delete nodeDel;

	size--;

	return value;
}

int ForwardList::Remove(int index)
{
	if (index >= size - 1)
		return Delete();
	
	Node* nodeCurr = At(index + 1);
	int value = nodeCurr->next->value;

	Node* nodeDel = nodeCurr->next;
	nodeCurr->next = nodeCurr->next->next;

	delete nodeDel;

	return value;
}

ForwardList::Node*& ForwardList::At(int index)
{
	// if (index > size) return; // заменим на исключение
	Node* nodeCurr{ head };
	for (int i = 0; i < size - 1 - index; i++)
		nodeCurr = nodeCurr->next;

	return nodeCurr;
}

int& ForwardList::operator[](int index)
{
	return At(index)->value;
}

std::ostream& operator<<(std::ostream& out, const ForwardList& flist)
{
	ForwardList::Node* nodeCurr{ flist.head };
	while (nodeCurr)
	{
		out << nodeCurr->value << "\n";
		nodeCurr = nodeCurr->next;
	}
	return out;
}
