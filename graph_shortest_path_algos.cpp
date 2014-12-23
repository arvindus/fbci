#include "graph.h"

template <typename T>
void graph<T>::findDAGShortestPaths(node<T> *start)
{
	cout << "For DAG with no negative weight edges:\n";
	const int LARGENUMBER = 10000000;
	stack<node <T> *> *st = new stack<node <T> *>();
	topologicalSort(st);
	if (hasCycle)
	{
		cout << "has cycle\n";
		return;
	}
	stack<node<T> *> *st1 = st->cloneStack();
	for (auto elem : nodelist)
	{
		node2parent[elem] = NULL;
		node2shortest[elem] = LARGENUMBER;
	}
	node2shortest[start] = 0;
	bool flag = false;
	while (!st1->isEmpty())
	{
		node<T> *src = st1->dequeue();
		if (src == start)
			flag = true;
		if (flag)
		{
			auto t_adjlist = src->get_adjlist();
			for (auto elem : t_adjlist)
			{
				node<T> *dst = elem.first;
				int w = elem.second;
				cout << "src = " << src->get_data() << " and dst = " << dst->get_data() << "and w = " << w << "\n";
				if (node2shortest[src] + w < node2shortest[dst])
				{
					node2parent[dst] = src;
					node2shortest[dst] = node2shortest[src] + w;
				}
			}
		}
	}
	
	cout << "Shortest path lengths from " << start->get_data() << " are:\n";
	for (auto elem : nodelist)
	{
		cout << elem->get_data() << ": " << node2shortest[elem] << "\n";
	}
	cout << "Shortest path parents from " << start->get_data() << " are:\n";
	for (auto elem : nodelist)
	{
		if (node2parent[elem])
			cout << elem->get_data() << ": " << node2parent[elem]->get_data() << "\n";
	}
	cout << "***********************\n";
}

template <typename T>
void graph<T>::djikstra(node<T> *start)
{
	cout << "DJIKSTRA:\n";
	const int LARGENUMBER = 10000000;
	for (auto elem : nodelist)
	{
		node2parent[elem] = NULL;
		node2shortest[elem] = LARGENUMBER;
	}
	node2shortest[start] = 0;
	
	set<node<T> *> readyset(nodelist.begin(),nodelist.end());
	
	while (!readyset.empty())
	{
		int min = LARGENUMBER;
		node<T> *min_elem = NULL;
		for (auto elem : readyset)
		{
			if (node2shortest[elem] < min)
			{
				min = node2shortest[elem];
				min_elem = elem;
			}
		}
		readyset.erase(min_elem);
		auto t_adjlist = min_elem->get_adjlist();
		for (auto elem : t_adjlist)
		{
			node<T> *dst = elem.first;
			int w = elem.second;
			if (node2shortest[min_elem] + w < node2shortest[dst])
			{
				node2parent[dst] = min_elem;
				node2shortest[dst] = node2shortest[min_elem] + w;
			}
		}
	}
	
	cout << "Shortest path lengths from " << start->get_data() << " are:\n";
	for (auto elem : nodelist)
	{
		cout << elem->get_data() << ": " << node2shortest[elem] << "\n";
	}
	cout << "Shortest path parents from " << start->get_data() << " are:\n";
	for (auto elem : nodelist)
	{
		if (node2parent[elem])
			cout << elem->get_data() << ": " << node2parent[elem]->get_data() << "\n";
	}
	cout << "***********************\n";
}

template <typename T>
void graph<T>::bellmanford(node<T> *start)
{
	cout << "BELLMAN-FORD:\n";
	const int LARGENUMBER = 10000000;
	for (auto elem : nodelist)
	{
		node2parent[elem] = NULL;
		node2shortest[elem] = LARGENUMBER;
	}
	node2shortest[start] = 0;
	
	for (int i = 0; i < num_nodes()-1; ++i)
	{
		for (auto src : nodelist)
		{
			auto t_adjlist = src->get_adjlist();
			for (auto elem : t_adjlist)
			{
				node<T> *dst = elem.first;
				int w = elem.second;
				if (node2shortest[src] + w < node2shortest[dst])
				{
					node2parent[dst] = src;
					node2shortest[dst] = node2shortest[src] + w;
				}
			}
		}
	}
	
	cout << "Shortest path lengths from " << start->get_data() << " are:\n";
	for (auto elem : nodelist)
	{
		cout << elem->get_data() << ": " << node2shortest[elem] << "\n";
	}
	cout << "Shortest path parents from " << start->get_data() << " are:\n";
	for (auto elem : nodelist)
	{
		if (node2parent[elem])
			cout << elem->get_data() << ": " << node2parent[elem]->get_data() << "\n";
	}
	cout << "***********************\n";
}
template class node<int>;
template class graph<int>;