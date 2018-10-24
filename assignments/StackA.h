/***************************************************************
Problem: Stack using array
Description:
Name: Mukhammadnozim Islamov
ID: 1668193
Date: 09/30/2018
Status: ( incomplete) This header file  has problem with first push
****************************************************************/
#ifndef STACKA_H
#define STACKA_H
#include<iostream>
#include<algorithm>
#include"List.h"

template<typename T>
class Stack
{
private:

	int stack_size;
	int array_capacity;
	T *array;

public:
	Stack<T>() : stack_size(0), array_capacity(std::max(1, 10)), array(new T[array_capacity]) {}
	Stack<T>(int num) :stack_size(0), array_capacity(std::max(1, num)), array(new T[array_capacity]) {}

	~Stack();
	bool empty()const;
	T top()const;
	void push(T const&);
	T pop();
	void double_capacity();

};



template<typename T>
Stack<T>::~Stack() {
	delete [] array;
}

template<typename T>
bool Stack<T>::empty()const {
	return (!stack_size);
}

template<typename T>
T Stack<T>::top()const {
	if (empty()) {
		throw overflow();
	}
	return array[stack_size-1];
}

template<typename T>
void Stack<T>::push(T const& obj) {
	if (stack_size == array_capacity) {
		throw overflow();
	}
	array[stack_size] = obj;
	++stack_size;
}

template<typename T>
T Stack<T>::pop() {
	if (empty()) {
		throw underflow();
	}
	T temp = array[stack_size];
	--stack_size;
	return temp;
	
}

template<typename T>
void Stack<T>::double_capacity() {
	Type *tmp_array = new Type[2 * array_capacity];
	for (int i = 0; i < array_capacity; i++) {
		tmp_array[i] = array[i];
	}
	delete[] array;
	array = tmp_array;

	array_capacity *= 2;
}

#endif // !STACKLL_H
