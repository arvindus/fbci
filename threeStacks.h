//
//  stack.h
//  
//
//  Created by arvind sudarsanam on 12/21/14.
//
//

#ifndef ____threeStacks__
#define ____threeStacks__

#include <vector>
#include <iostream>

// Have three stacks included into the stl vector one after the other with a fixed max. size. If size exceeds this max, report overflow.
template <typename T>
class threeStacks
{
private:
    std::vector<T> nodes;
    const int MAXSIZE = 1000;
    int stackSize[3];
public:
    threeStacks() { stackSize[0] = stackSize[1] = stackSize[2] = 0; nodes.resize(3*MAXSIZE); }
    void enqueue(T node, int stacknum)
    {
        if (stackSize[stacknum] < MAXSIZE)
        {
            nodes[stackSize[stacknum]+MAXSIZE*stacknum] = node;
            stackSize[stacknum]++;
        }
        else
        {
            std::cout << "MAXSIZE for stack #" << stacknum << " reached..No additions!!\n";
        }
    }
    T dequeue(int stacknum)
    {
        if (stackSize[stacknum] == 0)
        {
            std::cout << "Stack #" << stacknum << " is empty!!!\n";
            return NULL;
        }
        stackSize[stacknum]--;
        return nodes[stackSize[stacknum]+MAXSIZE*stacknum];
    }
    bool isEmpty(int stacknum) { return (stackSize[stacknum] == 0); }
    int num_nodes(int stacknum) { return stackSize[stacknum]; }
    void print()
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << "Stack #" << j << ":\n";
            for (int i = 0; i < num_nodes(j); ++i)
            {
                std::cout << *(nodes[i+MAXSIZE*j]) << " ";
            }
            std::cout << "\n";
        }
    }
	threeStacks<T> *cloneStack()
	{
		threeStacks<T> *st1 = new threeStacks<T>();
        copy(nodes.begin(),nodes.end(),st1->nodes.begin());
        for (int j = 0; j < 3; j++)
        {
            st1->stackSize[j] = stackSize[j];
        }
		return st1;
	}
};

#endif /* defined(____threeStacks__) */
