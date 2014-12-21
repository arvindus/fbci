//
//  graph.cpp
//  
//
//  Created by arvind sudarsanam on 12/20/14.
//
//

#include "graph.h"

int main()
{
    graph<int> g1;
    node<int> *n1 = g1.add_new_node(1);
    node<int> *n2 = g1.add_new_node(2);
    node<int> *n3 = g1.add_new_node(3);
    node<int> *n4 = g1.add_new_node(4);
    node<int> *n5 = g1.add_new_node(5);
    
    g1.add_new_edge(n1,n2,1);
    g1.add_new_edge(n1,n3,1);
    g1.add_new_edge(n1,n5,1);
    g1.add_new_edge(n2,n3,1);
    g1.add_new_edge(n2,n4,1);
    g1.add_new_edge(n3,n4,1);
    
    //g1.print();
    g1.bfs(n1);
    return 0;
}
