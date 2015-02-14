//
//  stack.cpp
//  
//
//  Created by arvind sudarsanam on 12/21/14.
//
//

#include "stack.h"
#include "threeStacks.h"

int main(void)
{
    /*
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
    */
    /*
     threeStacks<int *> mythreestack;
    
    int b[10] = {1,2,3,4,5,6,7,8,9,10};
    int c[5] = {11,12,13,14,15};
    int d[8] = {20,30,40,50,60,70,80,90};
    
    for (int i = 0; i < 15; i++)
    {
        if (i%3 == 0)
            mythreestack.enqueue(&b[i/3],0);
        if (i%3 == 1)
            mythreestack.enqueue(&c[i/3],1);
        if (i%3 == 2)
            mythreestack.enqueue(&d[i/3],2);
    }
    mythreestack.print();
    for (int i = 0; i < 18; i++)
    {
        int *x;
        if (i%3 == 0)
            x = mythreestack.dequeue(0);
        if (i%3 == 1)
            x = mythreestack.dequeue(1);
        if (i%3 == 2)
            x = mythreestack.dequeue(2);
    }
    mythreestack.print();
     */
    
    int tmp;
    stackMin<int *> mystack(&tmp);
    int a[10] = {7,3,6,9,4,1,9,0,1,7};
    
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