//
//  heap_util.cpp
//  
//
//  Created by arvind sudarsanam on 12/25/14.
//
//

#include "heap.h"

template <typename T>
void heap<T>::swap(int i, int j)
{
    T x = nodes[i];
    nodes[i] = nodes[j];
    nodes[j] = x;
}

template <typename T>
void heap<T>::heapUp(int index)
{
    if (index ==0)
        return;
    if (nodes[index] <= nodes[(index-1)/2])
        return;
    swap(index,(index-1)/2);
    heapUp((index-1)/2);
}

template <typename T>
void heap<T>::heapDown(int index)
{
    int lindex = 2*index+1;
    int rindex = 2*index+2;
    if (rindex < nodes.size())
    {
        if (nodes[lindex] < nodes[rindex])
        {
            if (nodes[index] < nodes[rindex])
            {
                swap(index,rindex);
                heapDown(rindex);
            }
        }
        else
        {
            if (nodes[index] < nodes[lindex])
            {
                swap(index,lindex);
                heapDown(lindex);
            }
        }
    }
    else if (lindex < nodes.size())
    {
        if (nodes[index] < nodes[lindex])
        {
            swap(index,lindex);
            heapDown(lindex);
        }
    }
    else
        return;
}

template <typename T>
void heap<T>::insert(T data)
{
    nodes.push_back(data);
    heapUp(nodes.size()-1);
    cout << data << " has been inserted\n";
}

template <typename T>
void heap<T>::removeTop()
{
    cout << nodes[0] << " has been removed\n";
    swap(0,nodes.size()-1);
    nodes.pop_back();
    heapDown(0);
}

template <typename T>
void heap<T>::print()
{
    cout << "Heap array is: \n";
    for (auto elem : nodes)
    {
        cout << elem << " ";
    }
    cout << "\n*******************\n";
}


template class heap<int>;
