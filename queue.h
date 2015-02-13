//
//  queue.h
//  
//
//  Created by arvind sudarsanam on 12/20/14.
//
//

#ifndef ____queue__
#define ____queue__

#include <deque>
#include <iostream>

template <typename T>
class queue
{
private:
    std::deque<T> nodes;
public:
    void enqueue(T node) { nodes.push_back(node); }
    T dequeue()
    {
        if (nodes.empty())
            return NULL;
        T node = nodes.front();
        nodes.pop_front();
        return node;
    }
    bool isEmpty() { return nodes.empty(); }
    int num_nodes() { return nodes.size(); }
    void print()
    {
        for (int i = 0; i < num_nodes(); ++i)
        {
            std::cout << *(nodes[i]) << " ";
        }
        std::cout << "\n";
    }
    queue<T> *cloneQueue()
    {
        queue<T> *q1 = new queue<T>();
        q1->nodes.resize(num_nodes());
        copy(nodes.begin(),nodes.end(),q1->nodes.begin());
        return q1;
    }
};

#endif /* defined(____queue__) */
