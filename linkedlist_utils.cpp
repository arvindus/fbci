#include "linkedlist.h"



Node* linkedlist::addNodeToTail(int d)
{
	Node *t = new Node(d);
	if (head == NULL)
	{
		head = t;
		return t;
	}
	Node *curr = head;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = t;
	return head;
}

void linkedlist::removeDupVals(void)
{
	Node *n1 = head;
	if (n1 == NULL)
		return;
	while (n1->next != NULL)
	{
		Node *n2 = n1->next;
		while (n2->next != NULL)
		{
			if (n1->data == n2->next->data)
			{
				n2->next = n2->next->next;
			}
			n2 = n2->next;
		}
		n2 = n1->next;
		if (n1->data == n2->data)
		{
			n1->next = n2->next;
		}
		n1 = n1->next;
	}
	return;
}

void linkedlist::print(void)
{
	Node *curr = head;
	cout << "LIST: \n";
	while (curr != NULL)
	{
		cout << curr->data << ' ';
		curr = curr->next;
	}
	cout << "\n";
}

linkedlist::~linkedlist(void)
{
	Node *prev = head;
	if (prev == NULL)
		return;
	Node *curr = prev->next;
	while (curr != NULL)
	{
		delete prev;
		prev = curr;
		curr = curr->next;
	}
}

void linkedlist::deleteNodeInMiddle(Node *n)
{
	Node *t = NULL;
	if (n == NULL)
		return;
	while (n->next != NULL)
	{
		n->data = n->next->data;
		if (n->next->next == NULL)
		{
			t = n->next;
			n->next = NULL;
		}
		else
			n = n->next;
	}
	if (t)
		delete t;
}

linkedlist *addTwoLists(linkedlist *list1, linkedlist *list2)
{
	Node *t1 = list1->head;
	Node *t2 = list2->head;
	int nDigits_1 = 0;
	int nDigits_2 = 0;
	while(t1 != NULL)
	{
		nDigits_1++;
		t1 = t1->next;
	}
	
	while(t2 != NULL)
	{
		nDigits_2++;
		t2 = t2->next;
	}
	if (nDigits_1 < nDigits_2)
	{
		int temp = nDigits_1;
		nDigits_1 = nDigits_2;
		nDigits_2 = temp;
		t2 = list1->head;
		t1 = list2->head;
	}
	else
	{
		t1 = list1->head;
		t2 = list2->head;
	}
	int count = 0;
	int sum = 0;
	while ((t1 != NULL) && (t2 != NULL))
	{
		if (count < (nDigits_1 - nDigits_2))
		{
			sum = sum*10 + t1->data;
			t1 = t1->next;
			count++;
		}
		else
		{
			sum = sum*10 + t1->data + t2->data;
			t1 = t1->next;
			t2 = t2->next;
		}
	}
	Node *p = NULL;
	Node *q = NULL;
	while (sum != 0)
	{
		p = new Node(sum % 10);
		p->next = q;
		sum = sum/10;
		q = p;
	}
	linkedlist *sumlist = new linkedlist();
	sumlist->head = p;
}