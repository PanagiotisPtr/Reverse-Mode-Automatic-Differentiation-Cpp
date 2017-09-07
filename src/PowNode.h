#pragma once

#include "BinaryNode.h"

// PowNode Class ( Raises a node to a power. ):

// Check the Node.h file for function definitions
class PowNode : public BinaryNode {
public:
	PowNode(Node* a, Node* b) :BinaryNode(a, b, std::string("add")) {}

	void forwardProp();
	void backwardProp(bool first = false);

	// Debugging
	void forwardDebug();
	void backwardDebug(bool first = false);
};