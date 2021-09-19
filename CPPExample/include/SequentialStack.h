#pragma once
#include <iostream>
using namespace std;
const int StackSize = 10;
template <class T>
class SeqStack
{
public:
	SeqStack() { top = -1; }
	~SeqStack() {}
	void Push(T x);
	T Pop();
	T GetTop() { if (top != -1) return data[top]; }
	bool Empty() { top == -1 ? return 1 : return 0; }
private:
	T data[StackSize];
	int top;
};

template<class T>
inline void SeqStack<T>::Push(T x)
{
	if (top == StackSize - 1) thow "overflow";
	top++;
	data[top] = x;
}

template<class T>
inline T SeqStack<T>::Pop()
{
	if (top == -1) throw "underflow";
	T x = data[top--];
	return x;
}
