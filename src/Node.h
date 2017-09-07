#pragma once

#include <string>
#include <cmath>

// Basically a general template of what every node should have but also acts like a Placeholder class
class Node {
public:
	Node(std::string str = "Placeholder") : m_val(0.f), m_grad(0.f), init(false), name(str), dinit(false), grad_expr(""), m_expr(str) {}
	Node(double x, std::string str = "Placeholder") :m_val(x), m_grad(0.f), init(false), name(str), dinit(false), grad_expr(""), m_expr(str) {}
	virtual ~Node() {  }
	// since this class will represent a placeholder it can't be abstract it needs to be able to backprop/forwardprop
	virtual void forwardProp() { return; }
	virtual void backwardProp(bool first = false) { return; }
	virtual void reset() { init = false; dinit = false; } // Again here although it could be written as just m_grad=0; by expanding
																				 // it a bit more I think it helps make it more general
	void set_val(double x) { m_val = x; }
	void set_grad(double x) { m_grad = x; }
	double get_val();
	double get_grad() { return m_grad; }
	std::string get_name() { return name; }

	// Helper functions
	friend double ln(double a);
	friend std::string double_str(double f);

	// Overloaded operators
	// Node with Node
	friend Node& operator+(Node &a, Node &b);
	friend Node& operator-(Node &a, Node &b);
	friend Node& operator*(Node &a, Node &b);
	friend Node& operator/(Node &a, Node &b);
	// Node with double
	friend Node& operator+(Node &a, double b);
	friend Node& operator-(Node &a, double b);
	friend Node& operator*(Node &a, double b);
	friend Node& operator/(Node &a, double b);
	// double with Node
	friend Node& operator+(double a, Node &b);
	friend Node& operator-(double a, Node &b);
	friend Node& operator*(double a, Node &b);
	friend Node& operator/(double a, Node &b);

	// Overloaded math functions for Nodes
	// Trigonometry
	friend Node& sin(Node &a);
	friend Node& cos(Node &a);
	friend Node& tan(Node &a);
	// Powers
	friend Node& pow(Node &a, Node &b);
	friend Node& pow(double a, Node &b);
	friend Node& pow(Node &a, double b);
	// Logarithms
	friend Node& log(Node &a, Node &b);
	friend Node& log(Node &a);
	friend Node& ln(Node &a);

	// Debugging
	virtual void forwardDebug() { return; } // for coherence I set ForwardProp and BackwardProp and their
											// debugging counterparts as setter functions.
	virtual void backwardDebug(bool first = false) { return; }
	std::string get_grad_expr() { return grad_expr; }
	std::string get_expr();
	void set_grad_expr(std::string str) { grad_expr = str; }
	void set_expr(std::string str) { m_expr = str; }

	bool isUserNode() { return userNode; }
protected:
	double m_val;
	double m_grad;
	bool init;
	std::string name;
	bool userNode;

	// Debugging
	bool dinit;
	std::string m_expr;
	std::string grad_expr;
};