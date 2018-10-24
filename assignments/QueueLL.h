/***************************************************************
Problem: Dequeue using List
Description:
Name: Mukhammadnozim Islamov
ID: 1668193
Date: 09/30/2018
Status: ( complete)
****************************************************************/
#ifndef QUEUE_H
#define QUEUE_H
#include"List.h"
#include <string>


template<typename T>
class Queue {
private:

	List<T>queue;

public:

	Queue() {}
	Queue(int a) {}
	void push(T const&);
	T front() const;
	T pop();
	bool empty();
	~Queue();
};

template<typename T>
void Queue<T>::push(T const &value) {
	queue.push_back(value);
}

template<typename T>
T Queue<T>::front() const {
	queue.front();
}

template<typename T>
T Queue<T>::pop() {
	return queue.pop_front();
}

template<typename T>
bool Queue<T>::empty() {
	return queue.empty();
}

template<typename T>
Queue<T>::~Queue() {
}
#endif

