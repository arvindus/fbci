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
    while (1)
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
        node<T> *temp = n1->getLeft();
        if (temp)
        {
            while (temp->getRight())
            {
                temp = temp->getRight();
            }
        }
        else
        {
            temp = n1->getRight();
            while (temp->getLeft())
            {
                temp = temp->getLeft();
            }
        }
        T inter = temp->getData();
        temp->setData(n1->getData());
        n1->setData(inter);
        n1 = temp;
    }
}

template class node<int>;
template class tree<int>;
