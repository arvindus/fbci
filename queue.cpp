//
//  queue.cpp
//  
//
//  Created by arvind sudarsanam on 12/20/14.
//
//

#include "queue.h"

int main(void)
{
    queue<int *> myqueue;
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    
    for (int i = 0; i < 10; i++)
    {
        myqueue.enqueue(&a[i]);
    }
    myqueue.print();
    for (int i = 0; i < 5; i++)
    {
        int *x = myqueue.dequeue();
    }
    myqueue.print();
    return 0;
}
