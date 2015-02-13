//
//  heap.h
//  
//
//  Created by arvind sudarsanam on 12/25/14.
//
//

#ifndef ____heap__
#define ____heap__
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class heap
{
private:
    vector<T> nodes;
    void swap(int i, int j);
    void heapUp(int index);
    void heapDown(int index);
public:
    heap() {}
    T retrieve() { return nodes[0]; }
    void insert(T data);
    void removeTop();
    int numNodes() { return nodes.size(); }
    bool isEmpty() { return nodes.empty(); }
    void print();
};

#endif /* defined(____heap__) */
