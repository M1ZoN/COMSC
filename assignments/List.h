/***************************************************************
Problem: Singly Linked List
Description:
Name: Mukhammadnozim Islamov
ID: 1668193
Date: 09/30/2018
Status: ( complete)
****************************************************************/
#ifndef LIST_H
#define LIST_H
#include<string>

using namespace std;

class underflow{
};

class overflow {
};


template<typename T>
class List
{
private:

	struct ListNode
	{
		T value;
		struct ListNode *next;
	};
	ListNode *head;
	ListNode *tail;

public:

	List<T>()
	{
		head = nullptr;
		tail = nullptr;
	}

	List<T>(List<T>& list)
	{
		head = nullptr;
		ListNode *nodePtr = list.head;

		while (nodePtr) {
			appendNode(nodePtr->value);
			nodePtr = nodePtr->next;
		}
	}

	~List();

	void appendNode(T);
	void insertNode(T);
	void deleteNode(T);
	void displayList() const;
	void insertNodeAt(int, T);
	bool empty()const;
	void push_back(T);
	void push_front(T);
	T front()const;
	T back()const;
	ListNode* begin()const;
	ListNode* end()const;
	int count(double);
	int size();
	T pop_front();
	T pop_back();


};

template<typename T>
void List<T>::appendNode(T num)
{
	ListNode *newNode;

	ListNode *nodePtr;
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;

	if (!head) {
		head = newNode;
		tail = newNode;	
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
}


template<typename T>
void List<T>::displayList() const
{
	ListNode *nodePtr;
	nodePtr = head;

	while (nodePtr){
		cout << nodePtr->value << endl;
		nodePtr = nodePtr->next;
	}
}



template<typename T>
void List<T>::insertNode(T num)
{
	ListNode *newNode;
	ListNode *nodePtr;
	ListNode *previousNode = nullptr;


	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;


	if (!head || (head->value > num))
	{
		newNode->next = head;
		head = newNode;
		tail = newNode;

	}
	else
	{
		nodePtr = head;
		previousNode = nullptr;

		while (nodePtr != nullptr && nodePtr->value < num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		previousNode->next = newNode;
		newNode->next = nodePtr;
		if (!nodePtr->next) {
			tail = nodePtr;
		}

	}
}

template<typename T>
void List<T>::deleteNode(T num)
{
	ListNode *nodePtr;
	ListNode *previousNode;

	if (!head)
		return;

	if (head->value == num)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;
		while (nodePtr && nodePtr->value != num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

template<typename T>
void List<T>::insertNodeAt(int pos, T num) {
	ListNode *newNode;
	ListNode *nodePtr;


	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;

	if (pos == 0)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		nodePtr = head;
		for (int i = 0; !nodePtr && i < pos;i++,nodePtr = nodePtr->next) {}

		newNode->next = nodePtr->next;
		nodePtr->next = newNode;
	}

}

template<typename T>
bool List<T>::empty()const {
	return !head;
}

template<typename T>
typename List<T>::ListNode* List<T>::begin()const {
	return head;
}

template<typename T>
typename List<T>::ListNode* List<T>::end()const {
	return tail;
}

template<typename T>
T List<T>::front()const {
	if (empty()) {
		throw underflow();
	}

	return begin()->value;
}

template<typename T>
T List<T>::back()const {
	if (empty()) {
		throw underflow();
	}

	return end()->value;
}

template<typename T>
void List<T>::push_front(T num) {
	ListNode *newNode = new ListNode;
	newNode->value = num;
	newNode->next = head;
	head = newNode;
}

template<typename T>
void List<T>::push_back(T num) {
	appendNode(num);
}

template<typename T>
int List<T>::count(double n) {
	int counter = 0;
	for (ListNode *nodePtr = head; nodePtr != tail; nodePtr = nodePtr->next) {
		counter += (nodePtr->value == n);
	}

	return counter;
}

template<typename T>
int List<T>::size() {
	int counter = 0;
	for (ListNode *nodePtr = head; nodePtr != tail; nodePtr = nodePtr->next, counter++) {}

	return counter;
}

template<typename T>
T List<T>::pop_front() {
	if (empty()) {
		throw underflow();
	}
	T output = front();
	ListNode *nodePtr = head;
	head = head->next;
	delete nodePtr;

	return output;
}

template<typename T>
T List<T>::pop_back() {
	if (empty()) {
		throw underflow();
	}
	T output = back();
	ListNode *nodePtr = tail;
	ListNode *traversePtr=head;
	for (;traversePtr->next; traversePtr = traversePtr->next) {}
	tail = traversePtr;
	delete nodePtr;

	return output;
}


template<typename T>
List<T>::~List()
{
	ListNode *nodePtr;
	ListNode *nextNode;
	nodePtr = head;
	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}


#endif 
