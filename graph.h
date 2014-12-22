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
    void add_edge(node <T> *dest, int w)
    {
        pair<node<T> *, int> temp;
        temp.first = dest;
        temp.second = w;
        adjlist.push_back(temp);
    }
    int num_edges() { return adjlist.size(); }
    vector<pair<node <T> *, int> > &get_adjlist() { return adjlist; }
    void print()
    {
        cout << "node data = " << data << "\nnode edges = ";
        for (auto it = adjlist.begin(); it != adjlist.end(); ++it)
        {
            cout << "(" << ((*it).first)->get_data() << "," << (*it).second << ") ";
        }
        cout << "\n";
    }
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
    bool is_bipartate;
public:
    graph(int n, bool t) : directed(t)
    {
        nodelist.resize(n);
        clearAllColors();
        clearAllStates();
        clearAllParents();
    }
    graph(bool t) : directed(t)
    {
        clearAllColors();
        clearAllStates();
        clearAllParents();
    }
    ~graph()
    {
        for (auto it = nodelist.begin(); it != nodelist.end(); ++it)
        {
            delete *it;
        }
    }
    void clearAllColors()
    {
        for (auto elem : nodelist) { node2color[elem] = unknown; }
    }
    
    void clearAllStates()
    {
        for (auto elem : nodelist) { node2state[elem] = undiscovered; }
    }
    
    void clearAllParents()
    {
        for (auto elem : nodelist) { node2parent[elem] = NULL; }
    }
    
    bool isDirected() { return directed; }
    node<T> *add_new_node(T t) { node<T> *n1 = new node<T>(t); nodelist.push_back(n1); return n1; }
    void add_new_node(node<T> *t_n) { nodelist.push_back(t_n); }
    
    void add_new_edge(node<T> *n1, node<T> *n2, int w) { n1->add_edge(n2,w); }
    int num_nodes() { return nodelist.size(); }
    int num_edges()
    {
        int sum = 0;
        for (auto it = nodelist.begin(); it != nodelist.end(); ++it)
        {
            sum += (*it)->num_edges();
        }
        return sum;
    }
    void print()
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
    void preprocessnode(node<T> *n1)
    {
        cout << "Node being preprocessed: " << n1->get_data() << "\n";
        //n1->print();
        //cout << "End preprocessing node\n";
    }
    void processedge(node<T> *n1, node<T> *n2, int w)
    {
        //cout << "Edge being processed\n";
        //cout << "SRC\n";
        //n1->print();
        //cout << "DEST\n";
        //n2->print();
        //cout << "weight = " << w << "\n";
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
            cout << "Back edge between " << n1->get_data() << " and " << n2->get_data() << "\n";
            cout << "Path is: ";
            findPath(n2,n1);
        }
        //cout << "End processing edge\n";
    }
    void postprocessnode(node<T> *n1)
    {
        cout << "Node being postprocessed: " << n1->get_data() << "\n";
        //n1->print();
        //cout << "End postprocessing node\n";
    }
    void bfs(node<T> *);
    void dfs(node<T> *);
    bool isBipartate();
    void findPath(node<T> *src, node<T> *dest);
};

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
void graph<T>::dfs(node<T> *n1)
{
    stack<node<T> *> tempnodelist;
    node2state[n1] = discovered;
    tempnodelist.enqueue(n1);
    
    while (!tempnodelist.isempty())
    {
        node<T> *t_n = tempnodelist.dequeue();
        preprocessnode(t_n);
        auto t_adjlist = t_n->get_adjlist();
        for (auto it = t_adjlist.begin(); it != t_adjlist.end(); ++it)
        {
            if (node2state[(*it).first] == undiscovered)
            {
                node2parent[(*it).first] = t_n;
                node2state[(*it).first] = discovered;
                tempnodelist.enqueue((*it).first);
            }
            processedge(t_n,(*it).first,(*it).second);
        }
        node2state[t_n] = processed;
        postprocessnode(t_n);
    }
    return;
}
#endif /* defined(____graph__) */
