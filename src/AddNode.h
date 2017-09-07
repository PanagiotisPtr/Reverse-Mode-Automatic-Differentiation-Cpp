#pragma once

#include "BinaryNode.h"

// AddNode Class ( Performs addition on 2 nodes. ):

// Check the Node.h file for function definitions
class AddNode : public BinaryNode {
public:
	AddNode(Node* a, Node* b) :BinaryNode(a, b, std::string("add")) {}

	void forwardProp();
	void backwardProp(bool first = false);

	// Debugging
	void forwardDebug();
	void backwardDebug(bool first = false);
};