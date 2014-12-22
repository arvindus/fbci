//
//  stack.h
//  
//
//  Created by arvind sudarsanam on 12/21/14.
//
//

#ifndef ____stack__
#define ____stack__

#include <vector>
#include <iostream>

template <typename T>
class stack
{
private:
    std::vector<T> nodes;
public:
    void enqueue(T node) { nodes.push_back(node); }
    T dequeue()
    {
        if (nodes.empty())
            return NULL;
        T node = nodes.back();
        nodes.pop_back();
        return node;
    }
    bool isempty() { return nodes.empty(); }
    int num_nodes() { return nodes.size(); }
    void print()
    {
        for (int i = 0; i < num_nodes(); ++i)
        {
            std::cout << *(nodes[i]) << " ";
        }
        std::cout << "\n";
    }
};


#endif /* defined(____stack__) */
