//
//  stack.cpp
//  
//
//  Created by arvind sudarsanam on 12/21/14.
//
//

#include "stack.h"

int main(void)
{
    stack<int *> mystack;
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    
    for (int i = 0; i < 10; i++)
    {
        mystack.enqueue(&a[i]);
    }
    mystack.print();
    for (int i = 0; i < 5; i++)
    {
        int *x = mystack.dequeue();
    }
    mystack.print();
    return 0;
}