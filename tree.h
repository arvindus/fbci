//
//  tree.h
//  
//
//  Created by arvind sudarsanam on 12/23/14.
//
//

#ifndef ____tree__
#define ____tree__

#include <iostream>

using namespace std;
template <typename T>
class node
{
private:
    T data;
    node<T> *parent;
    node<T> *left;
    node<T> *right;
public:
    node() : parent(NULL), left(NULL), right(NULL) {}
    node(T t_data) : data(t_data), parent(NULL), left(NULL), right(NULL) {}
    node(T t_data, node<T> *t_parent, node<T> *t_left, node<T> *t_right) : data(t_data), parent(t_parent), left(t_left), right(t_right) {}
    
    void setData(T t_data) { data = t_data; }
    T getData() { return data; }
    
    void setParent(node<T> *t) { parent = t; }
    void setLeft(node<T> *t) { left = t; }
    void setRight(node<T> *t) { right = t; }
    
    node<T> *getParent() { return parent; }
    node<T> *getLeft() { return left; }
    node<T> *getRight() { return right; }
    void print();
};

template <typename T>
class tree
{
private:
    node<T> *root;
public:
    tree() {}
    tree(T data) { root = new node<T>(data); }
    tree(node<T> *n1) { root = n1; }
    
    void setRoot(node<T> *t_root) { root = t_root; }
    node<T> *getRoot() { return root; }
    node<T> *insertion(T data);
    void deletion(T data);
    node<T> *search(T data, node<T> *);
    void inOrderTraverseAndPrint(node<T> *);
};

#endif /* defined(____tree__) */
