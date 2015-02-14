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

#define MINVAL 1000000
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
	stack<T> *cloneStack()
	{
		stack<T> *st1 = new stack<T>();
		st1->nodes.resize(num_nodes());
		copy(nodes.begin(),nodes.end(),st1->nodes.begin());
		return st1;
	}
};

#endif /* defined(____stack__) */
