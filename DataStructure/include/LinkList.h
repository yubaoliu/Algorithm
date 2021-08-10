#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class LinkList
{
public:
	LinkList() { first = new Node<T>; first->next = NULL; }
	LinkList(T a[], int n, bool flag_head_tail);//flag_head_tail 1: head insert method 0: tail insert method
	~LinkList();
	int Length();
	T Get(int i);
	int Locate(T x);
	void Insert(int i, T x);
	T Delete(int i);
	void PrintList();

//private:
	Node<T> *first;
};

template<class T>
inline void LinkList<T>::PrintList()
{
	Node<T>* p=first;
	while (p->next)
	{
		p = p->next;
		cout << p->data << "\t";
	}
	cout << endl;
}

template<class T>
inline LinkList<T>::LinkList(T a[], int n, bool flag_head_tail)
{
	first = new Node<T>;
	first->next = NULL;
	Node<T>* tmp;
	if (flag_head_tail)	//head insert method
	{
		for (int i = 0; i < n; i++)
		{
			tmp = new Node<T>;
			tmp->data = a[i];
			tmp->next = first->next;
			first->next = tmp;
		}
	}else {	//tail insert method
		Node<T>* tail = first;
		for (int i = 0; i < n; i++)
		{
			tmp = new Node<T>;
			tmp->data = a[i];
			tail->next = tmp;
			tail = tmp;
		}
		tail->next = NULL;
	}

}

template<class T>
inline int LinkList<T>::Length()
{
	Node<T>* p=first;
	int j = 0;
	while (p&&p->next)
	{
		p = p->next;
		j++;
	}
	return j;
}

template<class T>
inline T LinkList<T>::Get(int i)
{
	Node<T>* p;
	p = first;
	int j = 0;
	while (p&&j < i)
	{
		j++;
		p = p->next;
	}
	if (!p) throw "bad position of i";
	else {
		return p->data;
	}
}

template<class T>
inline int LinkList<T>::Locate(T x)
{
	Node<T>* p = first;
	int j = 0;
	while (p->next)
	{
		p = p->next;
		j++;
		if (p->data == x)
		{
			return j;
		}
	}
	cout << "not find;" << endl;
	return 0;
}

template<class T>
inline void LinkList<T>::Insert(int i, T x)
{
	Node<T>* p;
	p = first;
	int j = 0;
	while (p&&j < i)
	{
		j++;
		p = p->next;
	}
	if (!p) throw "bad position";
	else{
		Node<T> *newNode = new Node<T>;
		newNode->data = x;
		newNode->next = p->next;
		p->next = newNode;
	}

}

template<class T>
inline T LinkList<T>::Delete(int i)
{
	Node<T>* p = first,q;
	int j = 0;
	T x;
	while (p&&j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p || !p->next) throw "bad position";
	else{
		q = p->next;
		x = q->data;
		p->next = q->next;
		delete q;
		return x;
	}
}
template<class T>
inline LinkList<T>::~LinkList()
{
	Node<T>* p,*q;
	p = first;
	while (p)
	{
		q = p;
		p = p->next;
		delete q;
	}
}
/*
This is Microsoft interview question:

Question: Write a function(in C# or C++) to merge two already sorted linked lists, do not use recursion.
It takes in two already sorted linked lists(in ascendant order, duplicates allowed) and is supposed to merge them into a single sorted linked list(in ascendant order, duplicates allowed) and returns the new head.
*/
template <class T>
Node<T>* MergeSort(Node<T>* head1, Node<T>* head2)
{
	//deal with null link list
	if (head1 == NULL)
	{
		return head2;
	}
	else {
		if (head2 == NULL)
		{
			return head1;
		}
	}
	Node<T>* p = head1;
	Node<T>* q = head2;
	Node<T>* newHead, *newPt;
	//find the least significant node, and use it as the new Head node
	if (p->data <= q->data) //dumblicate allowed
	{
		newHead = p;
		p = p->next;
	}
	else {
		newHead = q;
		q = q->next;
	}
	newPt = newHead;
	while (p && q)
	{
		//insert the least significant node to newHead link list
		if (p->data <= q->data)
		{
			newPt->next = p;
			newPt = p;
			p = p->next;
		}
		else {
			newPt->next = q;
			newPt = q;
			q = q->next;
		}
	}
	//while (p)
	//{
	//	newPt->next = p;
	//	newPt = p;
	//	p = p->next;
	//	cout << newPt->data<<"\t";
	//}
	//while (q)
	//{
	//	newPt->next = q;
	//	newPt = q;
	//	q = q->next;
	//	cout << newPt->data << "\t";
	//}
	newPt->next = p ? p : q; //link the remainder
	return newHead;

}