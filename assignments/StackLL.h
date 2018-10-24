/***************************************************************
Problem: Stack using List
Description:
Name: Mukhammadnozim Islamov
ID: 1668193
Date: 09/30/2018
Status: ( complete)
****************************************************************/
#ifndef STACKLL_H
#define STACKLL_H
#include"List.h"
#include<iostream>
#include<algorithm>

template<typename T>
class Stack
{
private:
	List<T>stack;
public:

	Stack() {}
	Stack(int num) {}

	~Stack() {}
	bool empty()const;
	T top()const;
	void push(T const&);
	T pop();
};

template<typename T>
bool Stack<T>::empty()const {
return stack.empty();
}

template<typename T>
T Stack<T>::top()const {
if (empty()) {
throw overflow();
}
return stack.front();
}

template<typename T>
void Stack<T>::push(T const& obj) {
stack.push_front(obj);
}

template<typename T>
T Stack<T>::pop() {
if (empty()) {
throw underflow();
}
stack.pop_front();
}

#endif // !STACKLL_H
