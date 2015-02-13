//
//  tree.cpp
//  
//
//  Created by arvind sudarsanam on 12/23/14.
//
//

#include "tree.h"
#include <vector>
int main(void)
{
    /*
    node<int> *n1 = new node<int>(10);
    tree<int> *t1 = new tree<int>();
    
    t1->setRoot(n1);
    
    for (int i = 0; i < 20; i++)
    {
        int j = rand() % 100 + 1;
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
    cout << t1->checkIfBST(n1) << "\n";
    t1->deletion(50);
    cout << t1->checkIfBST(n1) << "\n";
    cout << "Inorder traversal of tree: \n";
    t1->inOrderTraverseAndPrint(n1);
    cout << "******************\n";

    cout << "Find range between 1 and 6:\n";
    queue<node<int> *> *qt = new queue<node<int> *>();
    
    int a = 3;
    int b = 9;
    t1->findRange(n1, a, b, qt);
    
    cout << "Range of nodes between " << a << " and " << b << "\n";
    queue<node <int> *> *qt1 = qt->cloneQueue();
    while(!qt1->isEmpty())
    {
        node<int> *n1 = qt1->dequeue();
        n1->print();
    }
    
    cout << "Height is " << t1->findHeight(n1) << "\n";
    
    cout << "min is " << t1->findMin(n1)->getData() << "\n";
    cout << "max is " << t1->findMax(n1)->getData() << "\n";
    
    node<int> *curr = t1->search(45,n1);
    node<int> *succ = t1->findSucc(curr);
    node<int> *pred = t1->findPred(curr);
    if (curr)
        cout << "curr = " << curr->getData() << "\n";
    if (succ)
        cout << "succ = " << succ->getData() << "\n";
    if (pred)
        cout << "pred = " << pred->getData() << "\n";
    */
    binarytree<int> *bt = new binarytree<int>();
    
    bt->createSampleBinaryTree();
    cout << "Min depth is " << bt->getMinDepth(bt->getRoot()) << "\n";
    
    cout << "Min depth is " << bt->getMinDepth_2(bt->getRoot()) << "\n";
    return 0;
}