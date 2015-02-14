//
//  stack.h
//  
//
//  Created by arvind sudarsanam on 12/21/14.
//
//

#ifndef ____stackMin__
#define ____stackMin__

#include <vector>
#include <iostream>

#define MINVAL 1000000
template <typename T>
class stackMin
{
private:
    std::vector<T> nodes;
    T currmin;
    std::vector<T> shadowNodes;
public:
    stackMin(T a) { currmin = a; *currmin = MINVAL; }
    void enqueue(T node)
    {
        if (*currmin > *node)
        {
            currmin = node;
        }
        shadowNodes.push_back(currmin);
        nodes.push_back(node);
    }
    T dequeue()
    {
        if (nodes.empty())
            return NULL;
        T node = nodes.back();
        nodes.pop_back();
        shadowNodes.pop_back();
        return node;
    }
    T getMin()
    {
        if (nodes.empty())
            return NULL;
        T node = shadowNodes.back();
        return node;
    }
    bool isEmpty() { return nodes.empty(); }
    int num_nodes() { return nodes.size(); }
    void print()
    {
        for (int i = 0; i < num_nodes(); ++i)
        {
            std::cout << *(nodes[i]) << "," << *(shadowNodes[i]) << " ";
        }
        std::cout << "\n";
    }
	stackMin<T> *cloneStack()
	{
		stackMin<T> *st1 = new stackMin<T>();
		st1->nodes.resize(num_nodes());
        st1->shadowNodes.resize(num_nodes());
		copy(nodes.begin(),nodes.end(),st1->nodes.begin());
        copy(shadowNodes.begin(),shadowNodes.end(),st1->shadowNodes.begin());
		return st1;
	}
};

#endif /* defined(____stackMin__) */
