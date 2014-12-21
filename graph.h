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

using namespace std;

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
public:
    graph(int n) { nodelist.resize(n); }
    graph() {}
    ~graph()
    {
        for (auto it = nodelist.begin(); it != nodelist.end(); ++it)
        {
            delete *it;
        }
    }
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
        }
    }
    void preprocessnode(node<T> *n1)
    {
        cout << "Node being preprocessed\n";
        n1->print();
        cout << "End preprocessing node\n";
    }
    void processedge(node<T> *n1, node<T> *n2, int w)
    {
        cout << "Edge being processed\n";
        cout << "SRC\n";
        n1->print();
        cout << "DEST\n";
        n2->print();
        cout << "weight = " << w << "\n";
        cout << "End processing edge\n";
    }
    void postprocessnode(node<T> *n1)
    {
        cout << "Node being postprocessed\n";
        n1->print();
        cout << "End postprocessing node\n";
    }
    void bfs(node<T> *);
};

typedef enum {undiscovered, discovered, processed} STATE;

template <typename T>
void graph<T>::bfs(node<T> *n1)
{
    unordered_map<node<T> *, node<T> *> node2parent;
    unordered_map<node<T> *, STATE> node2state;
    
    queue<node<T> *> tempnodelist;
    for (auto it = nodelist.begin(); it != nodelist.end(); ++it)
    {
        node2parent[*it] = NULL;
        node2state[*it] = undiscovered;
    }
    node2state[n1] = discovered;
    tempnodelist.enqueue(n1);
    
    while (!tempnodelist.isempty())
    {
        node<T> *t_n = tempnodelist.dequeue();
        //preprocessnode(t_n);
        auto t_adjlist = t_n->get_adjlist();
        for (auto it = t_adjlist.begin(); it != t_adjlist.end(); ++it)
        {
            if (node2state[(*it).first] == undiscovered)
            {
                node2parent[(*it).first] = t_n;
                node2state[(*it).first] = discovered;
                //processedge(t_n,(*it).first,(*it).second);
                tempnodelist.enqueue((*it).first);
            }
        }
        node2state[t_n] = processed;
        postprocessnode(t_n);
    }
    return;
}
#endif /* defined(____graph__) */
