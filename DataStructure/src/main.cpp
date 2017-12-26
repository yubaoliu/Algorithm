#include "linearList.h"
#include "LinkList.h"
#include "SequentialStack.h"
#include "LinkStack.h"
#include "Queue.h"
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{

#ifdef queue_test
	CirQueue<int> cq;
	cq.EnQueue(12);
	cq.EnQueue(89);
	cout << cq.GetQueue() << endl;
#endif


#ifdef LINK_MERGE_TEST
	LinkStack<int> ls;
	ls.Push(23);
	ls.Push(29);
	cout<<"top\t"<<ls.GetTop()<<endl;

	int a[] = { 10,12,15,25,8,16,20 };
	LinkList<int> link(a, 7, 1);
	link.PrintList();
	cout << endl;
	cout << "length: "<<link.Length() << endl;

	int b[] = { 2,5,6,9,59,111 };
	int c[] = { 3,25,35,39,66 };
	LinkList<int> L1(b, 6, 0);
	LinkList<int> L2(c, 5, 0);
	cout << "L1" << endl;
	L1.PrintList();
	cout << "L2" << endl;
	L2.PrintList();
	LinkList<int> res;
	//Node<int> *res;
	Node<int> *p1 = L1.first->next;
	Node<int> *p2 = L2.first->next;

	L1.first->next = NULL;
	L2.first->next = NULL;


	res.first->next = MergeSort(p1, p2);
	

	cout << endl;
	cout << "after merge:" << endl;
	res.PrintList();

	//cout << endl;
	cout << "end" << endl;
#endif
//	SeqListTest();
	
	return 0;
}
