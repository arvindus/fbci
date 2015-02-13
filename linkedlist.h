#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node *next = NULL;
	Node(int d) : data(d) {}
};

class linkedlist
{
public:
	Node *head;
	linkedlist(int d) { head = new Node(d); }
	linkedlist() {}
	~linkedlist();
	Node *addNodeToTail(int d);
	void removeDupVals(void);
	void print(void);
	void deleteNodeInMiddle(Node *n);
};

linkedlist *addTwoLists(linkedlist *list1, linkedlist *list2);
