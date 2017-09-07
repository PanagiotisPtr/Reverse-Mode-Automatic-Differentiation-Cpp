#pragma once

#include "PowNode.h"
#include <iostream>

using namespace std;

// Raising to a power: f(exponent, base) = base ^ exponent // Notice that the terms are reversed
void PowNode::forwardProp() { m_val = pow(in_1->get_val(), in_2->get_val()); }

// Exponantiation derivative: // d/da(a^b) = b * a^(b-1) // Power rule
							  // d/db(a^b) = a^b * ln(a) // Exponent derivative
void PowNode::backwardProp(bool first) {
	if (first)m_grad = 1;
	double p = in_2->get_val();
	// Chain rule
	double new_grad_1 = in_1->get_grad() + m_grad * pow(in_1->get_val(), p - 1) * p; 
	double new_grad_2 = in_1->get_grad() + m_grad * (m_val * ln(in_1->get_val())); 
	in_1->set_grad(new_grad_1);
	in_2->set_grad(new_grad_2);
	// Recursively calling backwardProp for every node
	in_1->backwardProp();
	in_2->backwardProp();
}

void PowNode::forwardDebug() {
	if (dinit)return;
	Node::set_expr(in_1->get_expr() + "^" + in_2->get_expr());
	dinit = true;
}

void PowNode::backwardDebug(bool first) {
	if (first)grad_expr = "1";
	std::string new_grad_expr_1 = "((" + grad_expr + ")*(" + in_1->get_expr() + ")^(" + in_2->get_expr() + "-1)*(" + in_2->get_expr() + "))";
	if (in_1->get_grad_expr() != "")new_grad_expr_1 += "+" + in_1->get_grad_expr();
	std::string new_grad_expr_2 = "((" + grad_expr + ")*((" + Node::get_expr() + ")*ln(" + in_1->get_expr() + "))";
	if (in_2->get_grad_expr() != "")new_grad_expr_2 += "+" + in_2->get_grad_expr();
	in_1->set_grad_expr(new_grad_expr_1);
	in_2->set_grad_expr(new_grad_expr_2);
	in_1->backwardDebug();
	in_2->backwardDebug();
}