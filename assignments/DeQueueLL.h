/***************************************************************
Problem: Dequeue using List
Description:
Name: Mukhammadnozim Islamov
ID: 1668193
Date: 09/30/2018
Status: ( incomplete) This header file has problems with pop_back function
****************************************************************/
#ifndef DEQUEUE_H
#define DEQUEUE_H
#include"List.h"
#include <string>


template<typename T>
class Dequeue {
private:
	List<T>dequeue;
public:
	Dequeue() {}
	Dequeue(int a) {}
	void push_back(T const&);
	void push_front(T const&);
	T back() const;
	T front() const;
	T pop_back();
	T pop_front();
	bool empty();
	~Dequeue();
};

template<typename T>
void Dequeue<T>::push_back(T const &value) {
	dequeue.push_back(value);
}

template<typename T>
void Dequeue<T>::push_front(T const &value) {
	dequeue.insertNodeAt(0,value);
}

template<typename T>
T Dequeue<T>::front() const {
	return dequeue.front();
}

template<typename T>
T Dequeue<T>::back() const {
	return dequeue.back();
}


template<typename T>
T Dequeue<T>::pop_front() {
	if (empty())
		throw underflow();
	return dequeue.pop_front();
}

template<typename T>
T Dequeue<T>::pop_back() {
	if (empty())
		throw underflow();
	return dequeue.pop_back();
}

template<typename T>
bool Dequeue<T>::empty() {
	return dequeue.empty();
}

template<typename T>
Dequeue<T>::~Dequeue() {
}
#endif

