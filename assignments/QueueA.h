/***************************************************************
Problem: Queue using array
Description:
Name: Mukhammadnozim Islamov
ID: 1668193
Date: 09/30/2018
Status: ( complete)
****************************************************************/
#ifndef QUEUE_H
#define QUEUE_H
#include<algorithm>
#include"List.h"
#include <string>


template<typename T>
class Queue {
private:

	int queue_size;
	int ifront;
	int iback;
	int array_capacity;
	T *array;

public:
	Queue() : queue_size(10), array_capacity(10), array(new T[array_capacity]), ifront(0), iback(-1) {}
	Queue(int size) :queue_size(size), array_capacity(std::max(1, size)), array(new T[array_capacity]), ifront(0), iback(-1) {}
	void push(T const&);
	T front() const;
	T pop();
	bool empty();
	void double_capacity();
	~Queue();
};



template<typename T>
void Queue<T>::push(T const &value) {
	if (iback == array_capacity)
		throw overflow();
	iback = (++iback) % array_capacity;
	array[iback] = value;
	queue_size++;
}

template<typename T>
T Queue<T>::front() const {
	if (ifront == -1)
		throw underflow();
	return array[ifront];
}

template<typename T>
T Queue<T>::pop() {
	if (empty())
		throw underflow();
	--queue_size;
	ifront++;
	return array[ifront - 1];
}

template<typename T>
bool Queue<T>::empty() {
	return (queue_size == 0);
}

template<typename T>
void Queue<T>::double_capacity() {
	T *tmp_array = new T[2 * capacity];
	for (int i = 0; i < capacity; i++) {
		tmp_array[i] = array[i];
	}
	delete[] array;
	array = tmp_array;

	capacity *= 2;
}

template<typename T>
Queue<T>::~Queue() {
	delete[] array;
}
#endif

