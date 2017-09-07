#pragma once

#include "Node.h"

class UnaryNode : public Node {
public:
	UnaryNode(Node* a, std::string &str) :Node(str), prev(a) {}
	~UnaryNode(){
		if (!prev->isUserNode()) delete prev;
		else prev = nullptr;
	}
	virtual void forwardProp() = 0;
	virtual void backwardProp(bool first = false) = 0;

	void reset() { Node::reset(); prev->reset(); }

	//Debugging
	virtual void forwardDebug() = 0;
	virtual void backwardDebug(bool first = false) = 0;
protected:
	Node* prev;
};