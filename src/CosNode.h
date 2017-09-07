#pragma once

#include "UnaryNode.h"

class CosNode : public UnaryNode {
public:
	CosNode(Node* a) :UnaryNode(a, std::string("cos")) {}

	void forwardProp();
	void backwardProp(bool first = false);

	// Debugging
	void forwardDebug();
	void backwardDebug(bool first = false);
};