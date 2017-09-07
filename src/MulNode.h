#pragma once

#include "BinaryNode.h"

// MulNode Class ( Performs multiplication of 2 nodes. ):

// Check the Node.h file for function definitions
class MulNode : public BinaryNode {
public:
	MulNode(Node* a, Node* b) :BinaryNode(a, b, std::string("mul")) {}

	void forwardProp();
	void backwardProp(bool first = false);

	// Debugging
	void forwardDebug();
	void backwardDebug(bool first = false);
};