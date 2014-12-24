//
//  tree.cpp
//  
//
//  Created by arvind sudarsanam on 12/23/14.
//
//

#include "tree.h"

int main(void)
{
    node<int> *n1 = new node<int>(10);
    tree<int> *t1 = new tree<int>();
    
    t1->setRoot(n1);
    
    for (int i = 0; i < 10; i++)
    {
        int j = rand() % 10 + 1;
        t1->insertion(j);
    }
    cout << "Inorder traversal of tree: \n";
    t1->inOrderTraverseAndPrint(n1);
    cout << "******************\n";
    node<int> *n2 = t1->search(15,t1->getRoot());
    if (n2)
        n2->print();
    else
        cout << "Data not found in tree\n";
    t1->deletion(4);
    
    cout << "Inorder traversal of tree: \n";
    t1->inOrderTraverseAndPrint(n1);
    cout << "******************\n";

    return 0;
}