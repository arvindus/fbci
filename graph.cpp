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
    graph<int> *g1 = graph<int>::createGraph5(false);
    
    //if (g1->getNode(0) != NULL)
	//	g1->dfs(g1->getNode(0));
    //if ((g1->getNode(0) != NULL) && (g1->getNode(9) != NULL))
	//	g1->findPath(g1->getNode(0),g1->getNode(9));
    //cout << "\n";
	//stack<node <int> *> *st = new stack<node <int> *>();
	//g1->topologicalSort(st);
	
	//int cost = g1->findMST();
	//cout << "min cost of mst is " << cost << "\n";
	//graph<int> *g2 = g1->cloneGraph();
	
	//g1->printMST();
	//g2->printMST();
	if (g1->getNode(0) != NULL)
		g1->findDAGShortestPaths(g1->getNode(0));
	if (g1->getNode(0) != NULL)
		g1->djikstra(g1->getNode(0));
	if (g1->getNode(0) != NULL)
		g1->bellmanford(g1->getNode(0));
	delete g1;
	
    return 0;
}
