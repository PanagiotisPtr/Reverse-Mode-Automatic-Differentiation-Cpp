#pragma once

#include "UnaryNode.h"

// TanNode Class ( Claculates the tangent of a node. ):

// Check the Node.h file for function definitions
class TanNode : public UnaryNode {
public:
	TanNode(Node* a) :UnaryNode(a, std::string("tan")) {}

	void forwardProp();
	void backwardProp(bool first = false);

	// Debugging
	void forwardDebug();
	void backwardDebug(bool first = false);
};