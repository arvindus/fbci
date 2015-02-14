//
//  tree_utils.cpp
//  
//
//  Created by arvind sudarsanam on 12/23/14.
//
//

#include "tree.h"

template <typename T>
void node<T>::print()
{
    cout << data << " ";
    if (parent)
        cout << parent->getData() << " ";
    else
        cout << "NULL ";
    if (left)
        cout << left->getData() << " ";
    else
        cout << "NULL ";
    if (right)
        cout << right->getData() << "\n";
    else
        cout << "NULL\n";
}

template <typename T>
void tree<T>::inOrderTraverseAndPrint(node<T> *t)
{
    if (t != NULL)
    {
        inOrderTraverseAndPrint(t->getLeft());
        t->print();
        inOrderTraverseAndPrint(t->getRight());
    }
}

template <typename T>
node<T> *tree<T>::findMin(node<T> *n1)
{
    if (n1 == NULL)
        return NULL;
    while (n1->getLeft())
    {
        n1 = n1->getLeft();
    }
    return n1;
}

template <typename T>
node<T> *tree<T>::findMax(node<T> *n1)
{
    if (n1 == NULL)
        return NULL;
    while (n1->getRight())
    {
        n1 = n1->getRight();
    }
    return n1;
}

template <typename T>
node<T> *tree<T>::search(T data, node<T> *start)
{
    node<T> *temp = start;
    while (temp)
    {
        if (data == temp->getData())
            return temp;
        else if (data < temp->getData())
            return search(data, temp->getLeft());
        else
            return search(data,temp->getRight());
    }
    //cout << "Data not found\n";
    return NULL;
}

template <typename T>
node<T> *tree<T>::insertion(T data)
{
    node<T> *new_node = new node<T>(data);
    if (root == NULL)
    {
        root = new_node;
        return new_node;
    }
    node<T> *temp = root;
    while (temp != NULL)
    {
        if (temp->getData() == data)
        {
            cout << "Data already present\n";
            return NULL;
        }
        if (temp->getData() < data)
        {
            if (temp->getRight() == NULL)
            {
                temp->setRight(new_node);
                new_node->setParent(temp);
                return new_node;
            }
            else
                temp = temp->getRight();
        }
        else
        {
            if (temp->getLeft() == NULL)
            {
                temp->setLeft(new_node);
                new_node->setParent(temp);
                return new_node;
            }
            else
                temp = temp->getLeft();
        }
    }
    cout << "Data not inserted for SOME reason\n";
    return NULL;
}

template <typename T>
void tree<T>::subDelete(node<T> *n1)
{
    if ((n1->getLeft() == NULL) && (n1->getRight() == NULL))
    {
        if (n1->getParent()->getLeft() == n1)
            n1->getParent()->setLeft(NULL);
        else
            n1->getParent()->setRight(NULL);
        cout << "deleting " << n1->getData() << "\n";
        delete n1;
        n1 = NULL;
        return;
    }
    node<T> *temp;
    if (n1->getLeft() != NULL)
        temp = findPred(n1);
    else
        temp = findSucc(n1);
    T inter = temp->getData();
    temp->setData(n1->getData());
    n1->setData(inter);
    subDelete(temp);
}

template <typename T>
void tree<T>::deletion(T data)
{
    node<T> *n1 = search(data,getRoot());
    if (n1)
    {
        cout << "Data found\n";
    }
    else
    {
        cout << "data " << data << " not found\n";
        return;
    }
    subDelete(n1);
}

template <typename T>
void tree<T>::findRange(node<T> *t, T min, T max, queue<node<T> *> *qt)
{
    if (t != NULL)
    {
        findRange(t->getLeft(),min,max,qt);
        if ((t->getData() >= min) && (t->getData() <= max))
            qt->enqueue(t);
        findRange(t->getRight(),min,max,qt);
    }
}

template <typename T>
int tree<T>::findHeight(node <T> *t)
{
    if (root == NULL)
        return -1;
    if (t == NULL)
        return 0;
    else
        return 1 + max(findHeight(t->getLeft()), findHeight(t->getRight()));
}

template <typename T>
node<T> *tree<T>::findSucc(node<T> *n1)
{
    if (n1->getRight() != NULL)
        return findMin(n1->getRight());
    node<T> *temp = n1;
    while (temp)
    {
        if ((temp->getParent() != NULL) && (temp->getParent()->getLeft() == temp))
            return temp->getParent();
        temp = temp->getParent();
    }
    return NULL;
}

template <typename T>
node<T> *tree<T>::findPred(node<T> *n1)
{
    if (n1->getLeft() != NULL)
        return findMax(n1->getLeft());
    node<T> *temp = n1;
    while (temp)
    {
        if ((temp->getParent() != NULL) && (temp->getParent()->getRight() == temp))
            return temp->getParent();
        temp = temp->getParent();
    }
    return NULL;
}

template <typename T>
bool tree<T>::checkIfBST(node<T> *n1)
{
    bool flag = true;
    if (n1 == NULL)
        return true;
    if ((n1->getLeft() == NULL) && (n1->getRight() == NULL))
        return true;
    if (n1->getLeft() == NULL)
        return ((n1->getRight()->getData() > n1->getData()) && checkIfBST(n1->getRight()));
    if (n1->getRight() == NULL)
        return ((n1->getLeft()->getData() < n1->getData()) && checkIfBST(n1->getLeft()));
                return (   ((n1->getRight()->getData() > n1->getData()) && checkIfBST(n1->getRight()))
                        && ((n1->getLeft()->getData() < n1->getData()) && checkIfBST(n1->getLeft())));
        
    
    
}

template <typename T>
void binarytree<T>::createSampleBinaryTree(void)
{
    node<T> *n1 = new node<T>(1);
    node<T> *n2 = new node<T>(2);
    node<T> *n3 = new node<T>(3);
    node<T> *n4 = new node<T>(4);
    node<T> *n5 = new node<T>(5);
    node<T> *n6 = new node<T>(6);
    node<T> *n7 = new node<T>(7);
    node<T> *n8 = new node<T>(8);
    node<T> *n9 = new node<T>(9);
    node<T> *n10 = new node<T>(10);
    node<T> *n11 = new node<T>(11);
    node<T> *n12 = new node<T>(12);
    
    setRoot(n1);
    n1->setLeft(n2);
    n1->setRight(n3);
    
    n2->setParent(n1);
    n2->setLeft(n4);
    n2->setRight(n5);
    
    n3->setParent(n1);
    n3->setLeft(n6);
    n3->setRight(n12);
    
    n4->setParent(n2);
    n4->setLeft(n9);
    n4->setRight(n10);
    
    n5->setParent(n2);
    n5->setLeft(n11);
    
    n6->setParent(n3);
    n6->setLeft(n7);
    n6->setRight(n8);
    
    n7->setParent(n6);
    
    n8->setParent(n6);
    
    n9->setParent(n4);
    
    n10->setParent(n4);
    
    n11->setParent(n5);
    
    n12->setParent(n3);
    
    
}

// We use BFS here
template <typename T>
int binarytree<T>::getMinDepth(node<T> *n1)
{
    queue<node <T> *> myqueue;
    int currdepth = 0;
    int mindepth = 10000000;
    if (n1 == NULL)
        return 0;
    myqueue.enqueue(n1);
    n1->setDepth(1);
    while (!myqueue.isEmpty())
    {
        node<T> *n2 = myqueue.dequeue();
        if ((n2->getLeft() == NULL) && (n2->getRight() == NULL))
            return n2->getDepth();
        if (n2->getLeft() != NULL)
        {
            myqueue.enqueue(n2->getLeft());
            n2->getLeft()->setDepth(n2->getDepth()+1);
        }
        if (n2->getRight() != NULL)
        {
            myqueue.enqueue(n2->getRight());
            n2->getRight()->setDepth(n2->getDepth()+1);
        }
    }
    return -1;
}

// We use BFS here
template <typename T>
int binarytree<T>::getMinDepth_2(node<T> *n1)
{
    queue<node <T> *> myqueue;
    int depth = 1;
    if (n1 == NULL)
        return 0;
    myqueue.enqueue(n1);
    myqueue.enqueue(NULL);
    while (!myqueue.isEmpty())
    {
        node<T> *n2 = myqueue.dequeue();
        if (n2 != NULL)
        {
            if ((n2->getLeft() == NULL) && (n2->getRight() == NULL))
                return depth;
            if (n2->getLeft() != NULL)
            {
                myqueue.enqueue(n2->getLeft());
            }
            if (n2->getRight() != NULL)
            {
                myqueue.enqueue(n2->getRight());
            }
        }
        else
        {
            depth++;
            myqueue.enqueue(NULL);
        }
    }
    return -1;
}

template <typename T>
node<T> *binarytree<T>::findNode(T val, node<T> *n1)
{
    if (n1 == NULL)
        return NULL;
    if (n1->data == val)
    {
        return n1;
    }
    node<T> *temp = findNode(val,n1->getLeft());
    if (temp != NULL)
        return temp;
    else
        return findNode(val,n1->getRight());
}

template <typename T>
node<T> *binarytree<T>::getFirstCommonAncestor(node<T> *n1, node<T> *n2)
{
    return n1;
}

template class binarytree<int>;
template class node<int>;
template class tree<int>;