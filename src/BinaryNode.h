#pragma once

#include "Node.h"

class BinaryNode : public Node {
public:
	BinaryNode(Node* a, Node* b, std::string str) :Node(str), in_1(a), in_2(b) {}
	~BinaryNode(){
		if (!in_1->isUserNode()) delete in_1;
		else in_1 = nullptr;

		if (!in_2->isUserNode()) delete in_2;
		else in_2 = nullptr;
	}
	// those functions can be virtual since BinaryNode class doens't itself represent an object
	virtual void forwardProp() = 0;
	virtual void backwardProp(bool first = false) = 0;
	// is Node::reset() better than reset()?
	void reset() { Node::reset(); in_1->reset(); in_2->reset(); }

	//Debugging
	virtual void forwardDebug() = 0;
	virtual void backwardDebug(bool first = false) = 0;
protected:
	Node* in_1;
	Node* in_2;
};