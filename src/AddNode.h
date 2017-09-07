#pragma once

#include "BinaryNode.h"

class AddNode : public BinaryNode {
public:
	AddNode(Node* a, Node* b) :BinaryNode(a, b, std::string("add")) {}

	void forwardProp();
	void backwardProp(bool first = false);

	// Debugging
	void forwardDebug();
	void backwardDebug(bool first = false);
};