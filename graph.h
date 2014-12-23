//
//  graph.h
//  
//
//  Created by arvind sudarsanam on 12/20/14.
//
//

#ifndef ____graph__
#define ____graph__

#include <vector>
#include <iterator>
#include <iostream> 
#include <unordered_map>
#include <set>
#include "queue.h"
#include "stack.h"

using namespace std;

typedef enum {undiscovered, discovered, processed} STATE;
typedef enum {unknown, BLACK, WHITE} COLOR;

template <typename T>
class node
{
private:
    T data;
    vector<pair<node<T> *, int> > adjlist;
public:
    T get_data() { return data; }
    node (T t) : data(t) {}
    void add_edge(node <T> *dest, int w);
    int num_edges() { return adjlist.size(); }
    vector<pair<node <T> *, int> > &get_adjlist() { return adjlist; }
    void print();
	node<T> *cloneNode();
};

template <typename T>
class graph
{
private:
    vector<node <T> *> nodelist;
    bool directed;
    unordered_map<node<T> *, node<T> *> node2parent;
    unordered_map<node<T> *, STATE> node2state;
    unordered_map<node<T> *, COLOR> node2color;
	unordered_map<node<T> *, int> dfsStartTimes;
	unordered_map<node<T> *, int> dfsEndTimes;
	vector<pair <node<int> *, node<int> *>> mst_edges;
	unordered_map<node<T> *, int> node2shortest;
    bool is_bipartate;
	int dfsTime;
	bool hasCycle;
public:
    graph(int n, bool t);
    graph(bool t);
	static graph<T> *createGraph1(bool isdirected);
	static graph<T> *createGraph2(bool isdirected);
	static graph<T> *createGraph3(bool isdirected);
	static graph<T> *createGraph4(bool isdirected);
	static graph<T> *createGraph5(bool isdirected);
	graph<T> *cloneGraph(void); 
    ~graph();
	node<T> *getNode(int index) 
	{ 
		if (index >= num_nodes()) 
			return NULL; 
		else 
			return nodelist[index]; 
	}
    void clearAllColors();    
    void clearAllStates();
    void clearAllParents();
    bool isDirected() { return directed; }
    node<T> *add_new_node(T t);
	void add_new_node(node<T> *t_n) { nodelist.push_back(t_n); }    
    void add_new_edge(node<T> *n1, node<T> *n2, int w) { n1->add_edge(n2,w); }
    int num_nodes() { return nodelist.size(); }
    int num_edges();
    void print();
    void preprocessnode(node<T> *n1);
    void processedge(node<T> *n1, node<T> *n2, int w);
    void postprocessnode(node<T> *n1);
    void bfs(node<T> *);
    void dfs(node<T> *,stack<node <T> *> *st);
    bool isBipartate();
    void findPath(node<T> *src, node<T> *dest);
	bool topologicalSort(stack<node <T> *> *st);
	int findMST();
	void printMST();
	void findDAGShortestPaths(node<T> *start);
	void djikstra(node<T> *start);
	void bellmanford(node<T> *start);
};

#endif /* defined(____graph__) */
