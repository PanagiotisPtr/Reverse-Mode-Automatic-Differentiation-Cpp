#pragma once

#include "Core.h"
#include <vector>
#include <map>

/*
	Graph Class (used at a higher level class to do math operations with nodes. ):
	
	What the graph class does is pretty simple. It has a pointer to an output node that is used to get the output of 
	an expression as well as propagating the gradient backwards. It also allows the user to use variables that haven't
	been initialized when used but are given a value before the graph is 'run'(using Graph.init, Graph.get_output)
*/

class Graph : public Node{
public:
	Graph() {};
	Graph(Node& n) { output = &n; }
	~Graph() { output->~Node(); output = nullptr; }
	double get_output();
	double get_grad(Node* x);
	void init(std::map<Node*, double> feed_dict); // Is used to initialize every variable in the graph. Example: Graph.init({ { &a, 13 }, { &b, 1}, ... ,{&c, 5} }); Notice that nodes are passed
												  // by reference
	void reset(); // resets all values in graph

	// Overloaded operators
	Graph& operator=(Node& n) { output = &n; return *this; } // Is to set a graph's output to a node.

	// Debugging
	std::string output_debug();
	std::string grad_debug(Node* x);
private:
	bool fp = false; // true if ForwardProp has been ran
	bool bp = false; // true if BackwardProp has been ran
	Node* output;
};