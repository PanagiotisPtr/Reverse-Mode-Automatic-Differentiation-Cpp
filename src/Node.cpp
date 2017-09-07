#pragma once

#include "Node.h"
#include "Core.h"

double Node::get_val() {
	if (init)return m_val;
	forwardProp();
	init = true;
	return m_val;
}

std::string Node::get_expr() {
	if (dinit)return m_expr;
	forwardDebug();
	dinit = true;
	return m_expr;
}

// Helper functions
double ln(double a) {
	return log(a) / log(exp(1));
}

std::string double_str(double f) {
	if (abs(f - exp(1)) < 1e-7)return "e";
	std::string rv = std::to_string(f);
	while (rv.back() == '0')rv.pop_back();
	if (rv.back() == '.')rv.pop_back();
	return rv;
}

// Node with Node
Node& operator+(Node& a, Node& b) { return *new AddNode(&a, &b); }
Node& operator-(Node& a, Node& b) { return *new SabNode(&a, &b); }
Node& operator*(Node& a, Node& b) { return *new MulNode(&a, &b); }
Node& operator/(Node& a, Node& b) { return *new MulNode(&a, new PowNode(&b, new Node(-1, "-1"))); }
// Node with double
Node& operator+(Node& a, double b) { return *new AddNode(&a, new Node(b, double_str(b))); }
Node& operator-(Node& a, double b) { return *new SabNode(&a, new Node(b, double_str(b))); }
Node& operator*(Node& a, double b) { return *new MulNode(&a, new Node(b, double_str(b))); }
Node& operator/(Node& a, double b) { return *new MulNode(&a, new PowNode(new Node(b, double_str(b)), new Node(-1, "-1"))); }
// double with Node
Node& operator+(double a, Node& b) { return *new AddNode(new Node(a, double_str(a)), &b); }
Node& operator-(double a, Node& b) { return *new SabNode(new Node(a, double_str(a)), &b); }
Node& operator*(double a, Node& b) { return *new MulNode(new Node(a, double_str(a)), &b); }
Node& operator/(double a, Node& b) { return *new MulNode(new Node(a, double_str(a)), new PowNode(&b, new Node(-1, "-1"))); }

// Overloaded math functions for Nodes
// Trigonometry
Node& sin(Node& a) { return *new SinNode(&a); }
Node& cos(Node& a) { return *new CosNode(&a); }
Node& tan(Node& a) { return *new TanNode(&a); }
// Powers
Node& pow(Node& a, Node& b) { return *new PowNode(&a, &b); }
Node& pow(double a, Node& b) { return *new PowNode(new Node(a, double_str(a)), &b); }
Node& pow(Node& a, double b) { return *new PowNode(&a, new Node(b, double_str(b))); }
// Logarithms
Node& log(Node& a, Node& b) { return *new LogNode(&a, &b); }
Node& log(Node& a) { return *new LogNode(new Node(10, "10"), &a); }
Node& ln(Node& a) { return *new LogNode(new Node(exp(1), "e"), &a); }