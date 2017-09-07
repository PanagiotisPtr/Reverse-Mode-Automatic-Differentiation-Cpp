#pragma once

#include "MulNode.h"

// Multiplication: f(a, b) = a * b
void MulNode::forwardProp() { m_val = in_1->get_val() * in_2->get_val(); }

// Multiplication derivateve: df/da = b, df/db = a
void MulNode::backwardProp(bool first) {
	if (first)m_grad = 1;
	// Chain rule
	double new_grad_1 = in_1->get_grad() + m_grad * in_2->get_val();
	double new_grad_2 = in_2->get_grad() - m_grad * in_1->get_val();
	in_1->set_grad(new_grad_1);
	in_2->set_grad(new_grad_2);
	// Recursively calling backwardProp for every node
	in_1->backwardProp();
	in_2->backwardProp();
}

void MulNode::forwardDebug() {
	if (dinit) return;
	Node::set_expr("((" + in_1->get_expr() + ")*(" + in_2->get_expr() + "))");
	dinit = true;
}

void MulNode::backwardDebug(bool first) {
	if (first)grad_expr = "1";
	std::string new_expr_1 = in_1->get_grad_expr() != "" ? (in_1->get_grad_expr() + "+" + "((" + in_2->get_expr() + ")*(" + grad_expr + "))") : "((" + in_2->get_expr() + ")*(" + grad_expr + "))";
	std::string new_expr_2 = in_2->get_grad_expr() != "" ? (in_2->get_grad_expr() + "+" + "((" + in_1->get_expr() + ")*(" + grad_expr + "))") : "((" + in_1->get_expr() + ")*(" + grad_expr + "))";
	in_1->set_grad_expr(new_expr_1);
	in_2->set_grad_expr(new_expr_2);
	in_1->backwardDebug();
	in_2->backwardDebug();
}