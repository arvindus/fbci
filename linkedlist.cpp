#include "linkedlist.h"

int main(void)
{
	/*linkedlist mylist(10);
	mylist.addNodeToTail(20);
	mylist.addNodeToTail(30);
	mylist.addNodeToTail(20);
	mylist.addNodeToTail(40);
	mylist.addNodeToTail(20);
	mylist.addNodeToTail(50);
	mylist.print();
	Node *n4 = mylist.head->next->next->next;
	//mylist.removeDupVals();
	mylist.deleteNodeInMiddle(n4);
	mylist.print();*/
	
	linkedlist *l1 = new linkedlist(3);
	l1->addNodeToTail(1);
	l1->addNodeToTail(5);
	linkedlist *l2 = new linkedlist(5);
	//l2->addNodeToTail(9);
	//l2->addNodeToTail(2);
	l1->print();
	l2->print();
	linkedlist *l3 = addTwoLists(l1,l2);
	l3->print();
	return 0;	
}