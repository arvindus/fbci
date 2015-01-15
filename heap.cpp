//
//  heap.cpp
//  
//
//  Created by arvind sudarsanam on 12/25/14.
//
//

#include "heap.h"

int main()
{
    heap<int> myheap;
    for (int i = 0; i < 10; i++)
    {
        int val = rand() % 100 + 1;
        myheap.insert(val);
    }
    myheap.print();
    for (int i = 0; i < 5; i++)
    {
        myheap.removeTop();
    }
    myheap.print();
    return 0;
}
