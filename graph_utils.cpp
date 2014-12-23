#include "graph.h"

template <typename T>
void node<T>::add_edge(node <T> *dest, int w)
{
	pair<node<T> *, int> temp;
	temp.first = dest;
	temp.second = w;
	adjlist.push_back(temp);
}

template <typename T>
node<T> *node<T>::cloneNode()
{
	node<T> *n1 = new node<T>(data+100);
	n1->adjlist.resize(adjlist.size());
	copy(adjlist.begin(),adjlist.end(),n1->adjlist.begin());
	return n1;
}

template <typename T>
void node<T>::print()
{
	cout << "node data = " << data << "\nnode edges = ";
	for (auto it = adjlist.begin(); it != adjlist.end(); ++it)
	{
		cout << "(" << ((*it).first)->get_data() << "," << (*it).second << ") ";
	}
	cout << "\n";
}


template <typename T>
graph<T>::graph(int n, bool t) : directed(t), dfsTime(0), hasCycle(false)
{
	nodelist.resize(n);
	clearAllColors();
	clearAllStates();
	clearAllParents();
}

template <typename T>
graph<T>::graph(bool t) : directed(t), dfsTime(0), hasCycle(false)
{
	clearAllColors();
	clearAllStates();
	clearAllParents();
}

template <typename T>
graph<T> *graph<T>::createGraph1(bool isdirected)
{
	graph<T> *g1 = new graph<T>(isdirected);
    node<T> *n1 = g1->add_new_node(1);
    node<T> *n2 = g1->add_new_node(2);
    node<T> *n3 = g1->add_new_node(3);
    node<T> *n4 = g1->add_new_node(4);
    node<T> *n5 = g1->add_new_node(5);
    
    g1->add_new_edge(n1,n2,1);
    g1->add_new_edge(n1,n3,1);
    g1->add_new_edge(n1,n5,1);
    g1->add_new_edge(n2,n3,1);
    g1->add_new_edge(n2,n4,1);
    g1->add_new_edge(n3,n4,1);
	
	return g1;
}

template <typename T>
graph<T> *graph<T>::createGraph2(bool isdirected)
{
	graph<T> *g1 = new graph<T>(isdirected);
    node<T> *n1 = g1->add_new_node(1);
    node<T> *n2 = g1->add_new_node(2);
    node<T> *n3 = g1->add_new_node(3);
    node<T> *n4 = g1->add_new_node(4);
    node<T> *n5 = g1->add_new_node(5);
    node<T> *n6 = g1->add_new_node(6);
    
    g1->add_new_edge(n1,n2,1);
    g1->add_new_edge(n1,n3,1);
    g1->add_new_edge(n2,n4,1);
    g1->add_new_edge(n3,n5,1);
    g1->add_new_edge(n3,n6,1);
    g1->add_new_edge(n6,n1,1);
	
	return g1;
}

template <typename T>
graph<T> *graph<T>::createGraph3(bool isdirected)
{
	graph<T> *g1 = new graph<T>(isdirected);
    node<T> *n1 = g1->add_new_node(1);
    node<T> *n2 = g1->add_new_node(2);
    node<T> *n3 = g1->add_new_node(3);
    node<T> *n4 = g1->add_new_node(4);
    node<T> *n5 = g1->add_new_node(5);
    node<T> *n6 = g1->add_new_node(6);
    node<T> *n7 = g1->add_new_node(7);
    
    g1->add_new_edge(n1,n2,1);
    g1->add_new_edge(n1,n3,1);
    g1->add_new_edge(n2,n4,1);
    g1->add_new_edge(n2,n5,1);
    g1->add_new_edge(n3,n6,1);
    g1->add_new_edge(n3,n7,1);
	
	return g1;
}

template <typename T>
graph<T> *graph<T>::createGraph4(bool isdirected)
{
	graph<T> *g1 = new graph<T>(isdirected);
    node<T> *n1 = g1->add_new_node(1);
    node<T> *n2 = g1->add_new_node(2);
    node<T> *n3 = g1->add_new_node(3);
    node<T> *n4 = g1->add_new_node(4);
    node<T> *n5 = g1->add_new_node(5);
    node<T> *n6 = g1->add_new_node(6);
    node<T> *n7 = g1->add_new_node(7);
    node<T> *n8 = g1->add_new_node(8);
    node<T> *n9 = g1->add_new_node(9);
    node<T> *n10 = g1->add_new_node(10);
    
    g1->add_new_edge(n1,n2,1);
    g1->add_new_edge(n1,n3,1);
	g1->add_new_edge(n1,n6,1);
	g1->add_new_edge(n1,n7,1);
	g1->add_new_edge(n2,n4,1);
	g1->add_new_edge(n3,n5,1);
	g1->add_new_edge(n3,n6,1);
	g1->add_new_edge(n4,n5,1);
	g1->add_new_edge(n5,n10,1);
	g1->add_new_edge(n7,n8,1);
	g1->add_new_edge(n7,n9,1);
	g1->add_new_edge(n8,n10,1);
	g1->add_new_edge(n9,n10,1);
	g1->add_new_edge(n2,n3,1);
	return g1;
}

// Bellman ford example
template <typename T>
graph<T> *graph<T>::createGraph5(bool isdirected)
{
	graph<T> *g1 = new graph<T>(isdirected);
    node<T> *n1 = g1->add_new_node(1);
    node<T> *n2 = g1->add_new_node(2);
    node<T> *n3 = g1->add_new_node(3);
    node<T> *n4 = g1->add_new_node(4);
    node<T> *n5 = g1->add_new_node(5);
    
    g1->add_new_edge(n1,n2,6);
    g1->add_new_edge(n1,n3,7);
    g1->add_new_edge(n2,n3,8);
    g1->add_new_edge(n2,n4,5);
    g1->add_new_edge(n2,n5,-4);
    g1->add_new_edge(n3,n4,-3);
	g1->add_new_edge(n3,n5,9);
	g1->add_new_edge(n4,n2,-2);
	g1->add_new_edge(n5,n1,2);
	g1->add_new_edge(n5,n4,7);
	
	return g1;
}

template <typename T>
graph<T> *graph<T>::cloneGraph()
{
	graph<T> *g1 = new graph<T>(directed);
	unordered_map<node<int> *, node<int> *> old2new;
	for (auto elem : nodelist)
	{
		node<T> *n1 = elem->cloneNode();
		g1->add_new_node(n1);
		old2new[elem] = n1;
	}
	for (auto elem : node2parent)
		g1->node2parent[old2new[elem.first]] = old2new[elem.second];
	for (auto elem : node2state)
		g1->node2state[old2new[elem.first]] = elem.second;
	for (auto elem : node2color)
		g1->node2color[old2new[elem.first]] = elem.second;
	for (auto elem : dfsStartTimes)
		g1->dfsStartTimes[old2new[elem.first]] = elem.second;
	for (auto elem : dfsEndTimes)
		g1->dfsEndTimes[old2new[elem.first]] = elem.second;
	for (auto elem : mst_edges)
	{
		pair <node<int> *, node<int> *> temp;
		temp.first = old2new[elem.first];
		temp.second = old2new[elem.second];
		g1->mst_edges.push_back(temp);
	}
	g1->is_bipartate = is_bipartate;
	g1->dfsTime = dfsTime;
	g1->hasCycle = hasCycle;
	return g1;
}
template <typename T>
graph<T>::~graph()
{
	for (auto it = nodelist.begin(); it != nodelist.end(); ++it)
	{
		delete *it;
	}
}

	
template <typename T>
void graph<T>::findPath(node<T> *src, node<T> *dest)
{
    if (node2parent[dest] == src)
    {
        cout << src->get_data();
    }
    else
    {
        findPath(src, node2parent[dest]);
    }
    cout << "->" << dest->get_data();
}

template <typename T>
bool graph<T>::isBipartate()
{
    is_bipartate = true;
    for (auto elem : nodelist)
    {
        if (node2color[elem] == unknown)
        {
            node2color[elem] = WHITE;
            bfs(elem);
        }
    }
    return is_bipartate;
}

template <typename T>
void graph<T>::clearAllColors()
{
	for (auto elem : nodelist) { node2color[elem] = unknown; }
}

template <typename T>
void graph<T>::clearAllStates()
{
	for (auto elem : nodelist) { node2state[elem] = undiscovered; }
}

template <typename T>
void graph<T>::clearAllParents()
{
	for (auto elem : nodelist) { node2parent[elem] = NULL; }
}

template <typename T>
node<T> *graph<T>::add_new_node(T t) 
{ 
	node<T> *n1 = new node<T>(t); 
	nodelist.push_back(n1); 
	return n1; 
}

template <typename T>
int graph<T>::num_edges()
{
	int sum = 0;
	for (auto it = nodelist.begin(); it != nodelist.end(); ++it)
	{
		sum += (*it)->num_edges();
	}
	return sum;
}

template <typename T>
void graph<T>::print()
{
	cout << "num nodes = " << num_nodes() << " and num edges = " << num_edges() << "\n";
	for (auto it = nodelist.begin(); it != nodelist.end(); ++it)
	{
		(*it)->print();
		if (node2parent[*it])
			cout << "parent = " << node2parent[*it]->get_data() << "\n";
		cout << "state = " << node2state[*it] << "\n";
		cout << "color = " << node2color[*it] << "\n";
	}
}

template <typename T>
void graph<T>::preprocessnode(node<T> *n1)
{
	cout << "Node being preprocessed: " << n1->get_data() << "\n";
}

template <typename T>
void graph<T>::processedge(node<T> *n1, node<T> *n2, int w)
{
	cout << "Processing " << n1->get_data() << "->" << n2->get_data() << "\n";
	if ((node2color[n2] != unknown) && (node2color[n1] == node2color[n2]))
	{
		is_bipartate = false;
	}
	else
	{
		if (node2color[n1] == WHITE)
			node2color[n2] = BLACK;
		else
			node2color[n2] = WHITE;
	}
	// Finding if this is a back edge
	if (node2parent[n2] != n1)
	{
		hasCycle = true;
		cout << "Back edge between " << n1->get_data() << " and " << n2->get_data() << "\n";
		cout << "Path is: ";
		findPath(n2,n1);
		cout << "\n";
	}
}

template <typename T>
void graph<T>::postprocessnode(node<T> *n1)
{
	cout << "Node being postprocessed: " << n1->get_data() << "\n";
}


template <typename T>
void graph<T>::bfs(node<T> *n1)
{
    queue<node<T> *> tempnodelist;
    node2state[n1] = discovered;
    tempnodelist.enqueue(n1);
    
    while (!tempnodelist.isempty())
    {
        node<T> *t_n = tempnodelist.dequeue();
        preprocessnode(t_n);
        auto t_adjlist = t_n->get_adjlist();
        for (auto it = t_adjlist.begin(); it != t_adjlist.end(); ++it)
        {
            if ((node2state[(*it).first] != processed) && (!isDirected()))
            {
                processedge(t_n,(*it).first,(*it).second);
            }
            if (node2state[(*it).first] == undiscovered)
            {
                node2parent[(*it).first] = t_n;
                node2state[(*it).first] = discovered;
                tempnodelist.enqueue((*it).first);
            }
        }
        node2state[t_n] = processed;
        postprocessnode(t_n);
    }
    return;
}

template <typename T>
void graph<T>::dfs(node<T> *n1, stack<node<T> *> *st)
{
    if (node2state[n1] == processed)
		return;
	dfsStartTimes[n1] = ++dfsTime;
	node2state[n1] = discovered;
    preprocessnode(n1);
    auto t_adjlist = n1->get_adjlist();
    for (auto it = t_adjlist.begin(); it != t_adjlist.end(); ++it)
    {
		if (node2state[(*it).first] != discovered)
		{
			node2parent[(*it).first] = n1;
			processedge(n1,(*it).first,(*it).second);
			dfs((*it).first,st);
		}
		else
			processedge(n1,(*it).first,(*it).second);
    }
    node2state[n1] = processed;
	dfsEndTimes[n1] = ++dfsTime;
	st->enqueue(n1);
    postprocessnode(n1);
    return;
}

template <typename T>
bool graph<T>::topologicalSort(stack<node <T> *> *st)
{
	dfsTime = 0;
	for (auto it = nodelist.begin(); it != nodelist.end(); ++it)
	{
		if (node2state[(*it)] == undiscovered)
			dfs(*it,st);
	}
	if (hasCycle)
	{
		cout << "Found a cycle\n";
		return false;
	}
		
	cout << "Topological sort is: \nSTART";
	stack<node<T> *> *st1 = st->cloneStack();
	while (!st1->isEmpty())
	{
		node<int> *n1 = st1->dequeue();
		cout << "->" << n1->get_data();
	}
	cout << "\n******************\nTimings are:\n";
	
	for (auto elem : nodelist)
	{
		cout << elem->get_data() << " " << dfsStartTimes[elem] << " " << dfsEndTimes[elem] << "\n";
	}
	return true;
}

template <typename T>
int graph<T>::findMST()
{
	int cost = 0;
	set<node<T> *> inTreeNodes;
	set<node<T> *> outTreeNodes(nodelist.begin(),nodelist.end());
	node<T> *n1 = *(outTreeNodes.begin());
	outTreeNodes.erase(n1);
	inTreeNodes.insert(n1);
	while (!outTreeNodes.empty())
	{
		int min = 100000000;
		node<T> *min_src = NULL;
		node<T> *min_dst = NULL;
		for (auto elem : inTreeNodes)
		{
			auto t_adjlist = elem->get_adjlist();
			for (auto dest : t_adjlist)
			{
				node<T> *dst_node = dest.first;
				if (inTreeNodes.find(dst_node) == inTreeNodes.end())
				{
					if (min > dest.second)
					{
						min = dest.second;
						min_src = elem;
						min_dst = dst_node;
					}
				}
			}
		}
		pair<node<T> *, node<T> *> tmp;
		tmp.first = min_src;
		tmp.second = min_dst;
		cost += min;
		mst_edges.push_back(tmp);
		outTreeNodes.erase(min_dst);
		inTreeNodes.insert(min_dst);
	}
	return cost;
}

template <typename T>
void graph<T>::printMST()
{
	cout << "This is MST:\n";
	for (auto elem : mst_edges)
	{
		cout << elem.first->get_data() << "->" << elem.second->get_data() << "\n";
	}
	cout << "********************\n";
}

template class node<int>;
template class graph<int>;