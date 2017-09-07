#pragma once

#include "UnaryNode.h"

// SinNode Class ( Calculated the sine of a node. ):

// Check the Node.h file for function definitions
class SinNode : public UnaryNode {
public:
	SinNode(Node* a) :UnaryNode(a, std::string("cos")) {}

	void forwardProp();
	void backwardProp(bool first = false);

	// Debugging
	void forwardDebug();
	void backwardDebug(bool first = false);
};