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
#include "queue.h"

using namespace std;
template <typename T>
class node
{
private:
    T data;
    node<T> *parent;
    node<T> *left;
    node<T> *right;
    int depth;
public:
    node() : parent(NULL), left(NULL), right(NULL), depth(-1) {}
    node(T t_data) : data(t_data), parent(NULL), left(NULL), right(NULL), depth(-1) {}
    node(T t_data, node<T> *t_parent, node<T> *t_left, node<T> *t_right) : data(t_data), parent(t_parent), left(t_left), right(t_right), depth(-1) {}
    
    void setData(T t_data) { data = t_data; }
    T getData() { return data; }
    
    void setParent(node<T> *t) { parent = t; }
    void setLeft(node<T> *t) { left = t; }
    void setRight(node<T> *t) { right = t; }
    
    node<T> *getParent() { return parent; }
    node<T> *getLeft() { return left; }
    node<T> *getRight() { return right; }
    void print();
    
    int getDepth() { return depth; }
    void setDepth(int t) { depth = t; }
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
    void findRange(node<T> *t, T min, T max, queue<node<T> *> *qt);
    int findHeight(node <T> *);
    node<T> *findSucc(node<T> *);
    node<T> *findPred(node<T> *);
    node<T> *findMin(node<T> *);
    node<T> *findMax(node<T> *);
    bool checkIfBST(node<T> *);
    void subDelete(node<T> *);
};

template <typename T>
class binarytree
{
private:
    node<T> *root;
public:
    binarytree() {}
    binarytree(T data) { root = new node<T>(data); }
    binarytree(node<T> *n1) { root = n1; }
    
    void setRoot(node<T> *t_root) { root = t_root; }
    node<T> *getRoot() { return root; }
    
    void createSampleBinaryTree();
    int getMinDepth(node<T> *n1);
    int getMinDepth_2(node<T> *n1);
};

#endif /* defined(____tree__) */
