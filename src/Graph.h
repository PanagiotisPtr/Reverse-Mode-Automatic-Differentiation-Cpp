#pragma once

#include "Core.h"
#include <vector>
#include <map>

class Graph : public Node{
public:
	Graph() {};
	Graph(Node& n) { output = &n; }
	~Graph() { output->~Node(); output = nullptr; }
	double get_output();
	double get_grad(Node* x);
	void init(std::map<Node*, double> feed_dict);
	void reset();

	// Overloaded operators
	Graph& operator=(Node& n) { output = &n; return *this; }

	// Debugging
	std::string output_debug();
	std::string grad_debug(Node* x);
private:
	bool fp = false; // true if ForwardProp has been ran
	bool bp = false; // true if BackwardProp has been ran
	Node* output;
};