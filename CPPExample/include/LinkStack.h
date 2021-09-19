#pragma once
#include "Node.h"
using namespace std;
template <class T>

class LinkStack
{
public:
	LinkStack() { top = NULL; }
	~LinkStack();
	void Push(T x);
	T Pop();
	T GetTop();
	bool Empty();
private:
	Node<T> *top;
};

template<class T>
inline LinkStack<T>::~LinkStack()
{
	Node<T>* p;
	while (top)
	{
		p = top;
		top = top->next;
		delete p;
	}
}

template<class T>
inline void LinkStack<T>::Push(T x)
{
	Node<T>* s = new Node<T>;
	s->data = x;
	s->next = top;
	top = s;
}

template<class T>
inline T LinkStack<T>::Pop()
{
	if (top == NULL) throw "underflow";
	T x = top->data;
	Node<T>* s = top;
	top = top->next;
	delegate s;
	return x;
}

template<class T>
inline T LinkStack<T>::GetTop()
{
	if (top != NULL) return top->data;
}

template<class T>
inline bool LinkStack<T>::Empty()
{
	(top == NULL) ? return 1 : return 0;
}
