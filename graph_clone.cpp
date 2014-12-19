#include <iostream>
#include <vector>
#include <map>

using namespace std;

class node;

class node {
private:
  int data;
  vector<node *> edgelist;
public:
  node(int t_data = 0) { data = t_data; }
  ~node() {}
  int get_data(void) { return data; }
  void set_data(int t_data) { data = t_data; }
  void add_edge(node *dest) { edgelist.push_back(dest); }
  node *get_edge(int i) { return edgelist[i]; }
  int get_num_edges(void) { return edgelist.size(); }	  
};

void add_edge(node *src, node *dest) { src->add_edge(dest); }

class graph {
private:
  vector<node *> nodelist;
public:
  graph() {}
  ~graph() {}
  void add_node(node *n) { nodelist.push_back(n); }
  int get_num_nodes(void) { return nodelist.size(); }
  node *get_node(int i) { return nodelist[i]; }
  graph *clone(void) {
    graph *g = new graph();
	map<node *, node *>  src_2_dest;
	for (int i=0; i<get_num_nodes(); i++) {
	  node *o = get_node(i);
	  node *n = new node(o->get_data());
	  g->add_node(n);
	  src_2_dest[o] = n;
	}
	for (int i=0; i<get_num_nodes(); i++) {
	  node *src = get_node(i);
	  for (int j=0; j<src->get_num_edges(); j++) {
		node *dest = src->get_edge(j);
		add_edge(src_2_dest[src], src_2_dest[dest]);
	  }
	}
	return g;
  }
  void print_graph(void) {
    cout << "list of nodes:" << endl;
    map<node *, int>  node_2_index;
    for (int i=0; i<get_num_nodes(); i++) {
	  node *src = get_node(i);
	  cout << "index = " << i << " and data = " << src->get_data() << endl;
	  node_2_index[src] = i;
    }
    cout << "list of edges:" << endl;
    for (int i=0; i<get_num_nodes(); i++) {
	  node *src = get_node(i); 
	  for (int j=0; j<src->get_num_edges(); j++) {
	    node *dest = src->get_edge(j);
	    cout << "src_index = " << node_2_index[src] << " and dest_index = " << node_2_index[dest] << endl;
	  }
    }
  }
};

int main(void) {
  graph *g1 = new graph();
  node *n1 = new node(10);
  node *n2 = new node(20);
  node *n3 = new node(30);
  node *n4 = new node(40);
  
  // Creating a sample graph
  g1->add_node(n1);
  g1->add_node(n2);
  g1->add_node(n3);
  g1->add_node(n4);
  add_edge(n1,n2);
  add_edge(n1,n3);
  add_edge(n4,n3);
  
  // cloning the sample graph
  graph *g2 = g1->clone();
  
  cout << "Printing the original graph:" << endl;
  g1->print_graph();
  
  cout << "Printing the cloned graph:" << endl;
  g2->print_graph();
  
  delete n1;
  delete n2;
  delete n3;
  delete n4;
  delete g1;
  delete g2;
  
  return 0;
}