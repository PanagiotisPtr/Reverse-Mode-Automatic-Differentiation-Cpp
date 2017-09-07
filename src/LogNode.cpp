#pragma once

#include "LogNode.h"

// Logarithm: f(base, x) = log(x)/log(base), // using the formula to change the base
void LogNode::forwardProp() { m_val = log(in_2->get_val()) / log(in_1->get_val()); }

// Logairthm derivative: d/dbase(log(base, x)) = -ln(x)/(ln(base)*ln(base)*base)
//						 d/dx(log(base, x)) = 1/(x * ln(base))
void LogNode::backwardProp(bool first) {
	if (first)m_grad = 1;
	double p = in_2->get_val();
	// Chain rule
	double new_grad_1 = in_1->get_grad() + m_grad * (-1) * ln(in_2->get_val()) / (ln(in_1->get_val())*ln(in_1->get_val())*in_1->get_val());
	double new_grad_2 = in_2->get_grad() + m_grad * 1 / (in_2->get_val() * ln(in_1->get_val()));
	in_1->set_grad(new_grad_1);
	in_2->set_grad(new_grad_2);
	// Recursively calling backwardProp for every node
	in_1->backwardProp();
	in_2->backwardProp();
}

void LogNode::forwardDebug() {
	if (dinit)return;
	if (in_1->get_val() == 10) Node::set_expr("log(" + in_2->get_expr() + ")");
	else if (in_1->get_val() == exp(1)) Node::set_expr("ln(" + in_2->get_expr() + ")");
	else Node::set_expr("log(" + in_1->get_expr() + ", " + in_2->get_expr() + ")");
	dinit = true;
}

void LogNode::backwardDebug(bool first) {
	if (first)grad_expr = "1";
	std::string new_grad_expr_1 = "(" + grad_expr + ")*(-ln(" + in_2->get_expr() + ")/(ln(" + in_1->get_expr() + ")^2*(" + in_1->get_expr() + ")))";
	if (in_1->get_grad_expr() != "")new_grad_expr_1 += "+" + in_1->get_grad_expr();
	std::string new_grad_expr_2 = "(" + grad_expr + ")*(1/((" + in_2->get_expr() + ")*ln(" + in_1->get_expr() + ")))";
	if (in_2->get_grad_expr() != "")new_grad_expr_2 += "+" + in_2->get_grad_expr();
	in_1->set_grad_expr(new_grad_expr_1);
	in_2->set_grad_expr(new_grad_expr_2);
	in_1->backwardDebug();
	in_2->backwardDebug();
}