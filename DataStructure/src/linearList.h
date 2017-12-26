#pragma once
#include<iostream>
#include <string>
using namespace std;
const int MaxSize = 100;
template <class T>
class SeqList
{
public:
	SeqList() { length = 0; }
	SeqList(T a[], int n);
	~SeqList() {};
	int Length() { return length; }
	T Get(int i);
	int Locate(T x);
	void Insert(int i, T x);
	T Delete(int i);
	void PrintList();
private:
	T data[MaxSize];
	int length;
};

template<class T>
inline SeqList<T>::SeqList(T a[], int n)
{
	if (n > MaxSize) throw "Bad argument, n is larger than the MaxSize of sequence list";
	for(int i = 0; i<n; i++)
	{ 
		data[i] = a[i];
	}
	length = n;
}

template<class T>
inline T SeqList<T>::Get(int i)
{
	if (i <= 0 || i > MaxSize) throw "i is illegal";
		else	return data[i-1];
}

template<class T>
inline int SeqList<T>::Locate(T x)
{
	for (int i = 0; i < length; i++)
	{
		if (data[i] == x) return i + 1;
	}
	return 0;
}

template<class T>
inline void SeqList<T>::Insert(int i, T x)
{
	if (length + 1 > MaxSize) throw "list if full, cannot complete insert operation";
	if (i < 1 || i >= length) throw "i refers to a bad location";
	for (int j = length - 1; j >= i - 1; j--)
	{
		data[j + 1] = data[j];
	}
	data[i - 1] = x;
	length++;	
}

template<class T>
inline T SeqList<T>::Delete(int i)
{
	if (length == 0) throw "null sequence list";
	if (i<1 || i>length) throw "i refers to a bad location";
	T retVal = data[i - 1];
	for (int j = i-1; j <= length; j++)
	{
		data[j] = data[j + 1];
	}
	data[length - 1] = 0;
	length--;
	return retVal;
}

template<class T>
inline void SeqList<T>::PrintList()
{
	cout << "Print list:" << endl;
	for (int i = 1; i <= length; i++)
		cout << data[i - 1] << " ";
	cout << endl;
}
void SeqListTest()
{
	int a[] = { 10,12,15,25,8,16,20 };
	SeqList<int> sl(a, 7);
	cout << "sl initial length:" << "\t" << sl.Length() << endl;
	cout << "sl elements;" << endl;
	sl.PrintList();
	sl.Insert(2, 15);
	cout << "insert 15 at 2" << endl;
	cout << "sl elements after insert£º" << "\t" << endl;
	sl.PrintList();
	cout << "delete a3" << endl;
	sl.Delete(3);
	cout << "sl elements after delete:" << endl;
	sl.PrintList();
	cout << "get element a2" << endl;
	cout << sl.Get(2) << endl;
	cout << "locate 25" << endl;
	cout << sl.Locate(25);
}