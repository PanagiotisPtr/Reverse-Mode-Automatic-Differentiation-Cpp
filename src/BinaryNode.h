#pragma once

#include "Node.h"

// BinaryNode Class ( Performs an operation [that is declared by a derived class] on 2 nodes. ):

// This class serves as a boilerplate base class for all the classes that their operations are performed on 2 nodes.

// Check the Node.h file for function definitions
class BinaryNode : public Node {
public:
	BinaryNode(Node* a, Node* b, std::string str) :Node(str), in_1(a), in_2(b) {}
	// Recursively destroys pointes that where created with 'new' to ensure that there are no memory leaks
	~BinaryNode(){
		if (!in_1->isUserNode()) delete in_1;
		else in_1 = nullptr;

		if (!in_2->isUserNode()) delete in_2;
		else in_2 = nullptr;
	}
	// those functions can be pure virtual since BinaryNode class doens't itself represent an object (i.e it isn't supposed to be created and used itself as an object)
	virtual void forwardProp() = 0;
	virtual void backwardProp(bool first = false) = 0;
	void reset() { Node::reset(); in_1->reset(); in_2->reset(); }

	//Debugging
	virtual void forwardDebug() = 0;
	virtual void backwardDebug(bool first = false) = 0;
protected:
	Node* in_1;
	Node* in_2;
};