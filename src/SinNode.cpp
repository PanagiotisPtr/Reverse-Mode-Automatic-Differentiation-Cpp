#pragma once

#include "SinNode.h"

void SinNode::forwardProp() { m_val = sin(prev->get_val()); }

void SinNode::backwardProp(bool first) {
	if (first)m_grad = 1;
	double new_grad = prev->get_grad() + cos(prev->get_val()) * m_grad;
	prev->set_grad(new_grad);
	prev->backwardProp();
}

void SinNode::forwardDebug() {
	if (dinit) return;
	Node::set_expr("sin(" + prev->get_expr() + ")");
	dinit = true;
}

void SinNode::backwardDebug(bool first) {
	if (first)grad_expr = "1";
	std::string new_expr = prev->get_grad_expr() != "" ? (prev->get_grad_expr() + "+" + "cos(" + prev->get_expr() + ")*" + grad_expr) : "cos(" + prev->get_expr() + ")*" + grad_expr;
	prev->set_grad_expr(new_expr);
	prev->backwardDebug();
}