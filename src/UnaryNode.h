#pragma once

#include "Node.h"

// UnaryNode Class ( Performs an operation [that is declared by a derived class] on a signle node. ):

// This class serves as a boilerplate base class for all the classes that their operations are performed on 1 node.

// Check the Node.h file for function definitions
class UnaryNode : public Node {
public:
	UnaryNode(Node* a, std::string &str) :Node(str), prev(a) {}
	// Recursively destroys pointes that where created with 'new' to ensure that there are no memory leaks
	~UnaryNode(){
		if (!prev->isUserNode()) delete prev;
		else prev = nullptr;
	}
	// those functions can be pure virtual since Unary class doens't itself represent an object (i.e it isn't supposed to be created and used itself as an object)
	virtual void forwardProp() = 0;
	virtual void backwardProp(bool first = false) = 0;

	void reset() { Node::reset(); prev->reset(); }

	//Debugging
	virtual void forwardDebug() = 0;
	virtual void backwardDebug(bool first = false) = 0;
protected:
	Node* prev;
};
