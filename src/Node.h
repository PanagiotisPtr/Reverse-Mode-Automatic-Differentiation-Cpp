#pragma once

#include <string>
#include <cmath>

/*
	The Great Node Class( Base class of all classes. ):
	
	This class is basically the core of the library. It can be used as an object and acts like a placeholder (holding a single value).
	It also has all the overloaded operators that make the library work. The operators are split between Node-Node, float-Node, Node-float.
	Here you will find explanations for all the functions that derived classes declare. 
	
	The forward and backward functions (forwardDebug, forwardProp, backwardDebug, backwardProp) are only used for setting values and they return nothing. 
	If you want to access those values you have to use the helper functions bellow.
*/

// Basically a general template of what every node should have but also acts like a Placeholder class
class Node {
public:
	// Constructors
	Node(std::string str = "Placeholder") : m_val(0.f), m_grad(0.f), init(false), name(str), dinit(false), grad_expr(""), m_expr(str) {}
	Node(double x, std::string str = "Placeholder") :m_val(x), m_grad(0.f), init(false), name(str), dinit(false), grad_expr(""), m_expr(str) {}
	virtual ~Node() {  }
	// since this class will represent a placeholder it can't be abstract it needs to be able to backprop/forwardprop
	virtual void forwardProp() { return; } // The value of a Node is already set so it doesn't need to be calculated
	virtual void backwardProp(bool first = false) { return; } // The gradient of the node is also calculated by other nodes so the Node class doesn't have any work to do.
	virtual void reset() { init = false; dinit = false; } // Again here although it could be written as just m_grad=0; by expanding
																				 // it a bit more I think it helps make it more general
	void set_val(double x) { m_val = x; } // Allows setting of the value of the Node. Useful for Graph.init (see Graph.h)
	void set_grad(double x) { m_grad = x; } // Helper function that allows setting of the Node gradient.
	double get_val(); // returns Node value
	double get_grad() { return m_grad; } // returns Node's gradient
	std::string get_name() { return name; } // returns Node's name

	// Helper functions
	friend double ln(double a); // Log base e. (AKA natural log)
	friend std::string double_str(double f); // converts a double to a string

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
	virtual void forwardDebug() { return; } // It is used to set the m_expr string to the expression of the node. In this case, since this acts like a placeholder, it does nothing(For that class).
											// For coherence I set ForwardProp and BackwardProp and their
											// debugging counterparts as setter functions. 
											
	virtual void backwardDebug(bool first = false) { return; } // Is used to debug the program and access the derived form of the expression. Very useful when double precision is not enough.
	std::string get_grad_expr() { return grad_expr; }// Returns a string of the Node's gradient. (Derivative of an expression)
	std::string get_expr(); // Returns a string of the Node's expression
	
	void set_grad_expr(std::string str) { grad_expr = str; } // sets a Node's expression to a string
	void set_expr(std::string str) { m_expr = str; } // sets a Node's gradient expression to a string.

	bool isUserNode() { return userNode; } // If the node is created with 'new' (e.x node* n = new Node() ) then this value MUST be set to true. 
										   // It can also be helpful since gradients of dummy nodes do not need to be calculated so this could reduce time complexity (currently not implemented)
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