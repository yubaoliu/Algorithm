#pragma once
#include<iostream>
using namespace std;
const int QueueSize = 100;
template <class T>
class CirQueue
{
public:
	CirQueue() { front = rear = 0; }
	~CirQueue() {}
	void EnQueue(T x);
	T DeQueue();
	T GetQueue();
	bool Empty() { front == rear ? return 1 : return 0; }
private:
	T data[QueueSize];
	int front, rear;
};

template<class T>
inline void CirQueue<T>::EnQueue(T x)
{
	if ((rear + 1) % QueueSize == front) throw "overflow";
	rear = (rear + 1) % QueueSize;
	data[rear] = x;
}

template<class T>
inline T CirQueue<T>::DeQueue()
{
	if (front == rear) throw "under flow";
	front = (front + 1) % QueueSize;
	return data[front];
}

template<class T>
inline T CirQueue<T>::GetQueue()
{
	if (front == rear) throw "under flow";
	int pos = (front + 1) % QueueSize;
	return data[pos];
}
