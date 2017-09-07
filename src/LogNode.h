#pragma once

#include "BinaryNode.h"

class LogNode : public BinaryNode {
public:
	LogNode(Node* a, Node* b) :BinaryNode(a, b, std::string("add")) {}
	// Log(base, x)

	void forwardProp();
	void backwardProp(bool first = false);

	// Debugging
	void forwardDebug();
	void backwardDebug(bool first = false);
};