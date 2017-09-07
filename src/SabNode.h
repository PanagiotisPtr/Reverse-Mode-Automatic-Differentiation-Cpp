#pragma once

#include "BinaryNode.h"

class SabNode : public BinaryNode {
public:
	SabNode(Node* a, Node* b) :BinaryNode(a, b, std::string("sab")) {}

	void forwardProp();
	void backwardProp(bool first = false);

	// Debugging
	void forwardDebug();
	void backwardDebug(bool first = false);
};