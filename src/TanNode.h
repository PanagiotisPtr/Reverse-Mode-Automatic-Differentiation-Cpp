#pragma once

#include "UnaryNode.h"

class TanNode : public UnaryNode {
public:
	TanNode(Node* a) :UnaryNode(a, std::string("tan")) {}

	void forwardProp();
	void backwardProp(bool first = false);

	// Debugging
	void forwardDebug();
	void backwardDebug(bool first = false);
};