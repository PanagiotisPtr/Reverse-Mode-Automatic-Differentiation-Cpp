#pragma once

#include "UnaryNode.h"

// CosNode Class ( Calculates the cosine of a node. ):

// Check the Node.h file for function definitions
class CosNode : public UnaryNode {
public:
	CosNode(Node* a) :UnaryNode(a, std::string("cos")) {}

	void forwardProp();
	void backwardProp(bool first = false);

	// Debugging
	void forwardDebug();
	void backwardDebug(bool first = false);
};