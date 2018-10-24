/***************************************************************
Problem: Dequeue using array
Description:
Name: Mukhammadnozim Islamov
ID: 1668193
Date: 09/30/2018
Status: ( complete)
****************************************************************/
#ifndef DEQUEUE_H
#define DEQUEUE_H
#include"List.h"
#include <string>
#include<algorithm>


template<typename T>
class Dequeue {
private:

	int dequeue_size;
	int ifront;
	int iback;
	int dequeue_capacity;
	T *array;

public:

	Dequeue() :dequeue_size(0), dequeue_capacity(10), array(new T[dequeue_capacity]), ifront(0), iback(-1) {}

	Dequeue(int size) :dequeue_size(size), dequeue_capacity(std::max(1, size)), array(new T[dequeue_capacity]), ifront(0), iback(-1) {}
	void push_back(T const &);
	void push_front(T const &);
	T front() const;
	T back() const;
	T pop_back();
	T pop_front();
	bool empty();
	void double_capacity();
	~Dequeue();
};

template<typename T>
void Dequeue<T>::push_back(T const &value) {
	if (iback == dequeue_capacity)
		throw overflow();
	iback = (++iback) % dequeue_capacity;
	array[iback] = value;
	dequeue_size++;
}

template<typename T>
void Dequeue<T>::push_front(T const &value) {
	if (ifront == dequeue_capacity)
		throw overflow();
	ifront = (--ifront) % dequeue_capacity;
	array[ifront] = value;
	dequeue_size++;
}

template<typename T>
T Dequeue<T>::front() const {
	if (ifront == -1)
		throw underflow();
	return array[ifront];
}

template<typename T>
T Dequeue<T>::back() const {
	if (iback == -1)
		throw underflow();
	return array[iback];
}

template<typename T>
T Dequeue<T>::pop_front() {
	if (empty())
		throw underflow();
	--dequeue_size;
	ifront++;
	return array[ifront - 1];
}

template<typename T>
T Dequeue<T>::pop_back() {
	if (empty())
		throw underflow();
	--dequeue_size;
	iback--;
	return array[iback + 1];
}

template<typename T>
bool Dequeue<T>::empty() {
	return (dequeue_size == 0);
}

template<typename T>
void Dequeue<T>::double_capacity() {
	T *tmp_array = new T[2 * dequeue_capacity];
	for (int i = 0; i < dequeue_capacity; i++) {
		tmp_array[i] = array[i];
	}
	delete[] array;
	array = tmp_array;

	dequeue_capacity *= 2;
}

template<typename T>
Dequeue<T>::~Dequeue() {
	delete[] array;
}
#endif


