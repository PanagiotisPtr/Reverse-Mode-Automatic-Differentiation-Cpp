#pragma once

#include "SabNode.h"

// Sabtraction: f(a, b) = a - b
void SabNode::forwardProp() { m_val = in_1->get_val() - in_2->get_val(); }

// Sabtraction derivateve: df/da = 1, df/db = -1
void SabNode::backwardProp(bool first) {
	if (first)m_grad = 1;
	// Chain rule
	double new_grad_1 = in_1->get_grad() + m_grad * 1;
	double new_grad_2 = in_2->get_grad() - m_grad * 1;
	in_1->set_grad(new_grad_1);
	in_2->set_grad(new_grad_2);
	// Recursively calling backwardProp for every node
	in_1->backwardProp();
	in_2->backwardProp();
}

void SabNode::forwardDebug() {
	if (dinit) return;
	Node::set_expr(in_1->get_expr() + "-" + in_2->get_expr());
	dinit = true;
}

void SabNode::backwardDebug(bool first) {
	if (first)grad_expr = "1";
	std::string new_expr_1 = in_1->get_grad_expr() != "" ? (in_1->get_grad_expr() + "+" + grad_expr) : grad_expr;
	std::string new_expr_2 = in_2->get_grad_expr() != "" ? (in_2->get_grad_expr() + "-" + grad_expr) : grad_expr;
	in_1->set_grad_expr(new_expr_1);
	in_2->set_grad_expr(new_expr_2);
	in_1->backwardDebug();
	in_2->backwardDebug();
}