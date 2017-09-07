#pragma once

#include "TanNode.h"

// Tangent: f(x) = tan(x)
void TanNode::forwardProp() { m_val = tan(prev->get_val()); }

// Tangent derivateve: df/dx = 1/cos(x)^2
void TanNode::backwardProp(bool first) {
	if (first)m_grad = 1;
	// Chain rule
	double new_grad = prev->get_grad() + (1 / (cos(prev->get_val()) * cos(prev->get_val()))) * m_grad;
	prev->set_grad(new_grad);
	// Recursively calling backwardProp for every node
	prev->backwardProp();
}

void TanNode::forwardDebug() {
	if (dinit) return;
	Node::set_expr("tan(" + prev->get_expr() + ")");
	dinit = true;
}

void TanNode::backwardDebug(bool first) {
	if (first)grad_expr = "1";
	std::string new_expr = prev->get_grad_expr() != "" ? (prev->get_grad_expr() + "+" + "(1/cos(" + prev->get_expr() + ")^2)*(" + grad_expr + ")") : "(1/cos(" + prev->get_expr() + ")^2)*(" + grad_expr + ")";
	prev->set_grad_expr(new_expr);
	prev->backwardDebug();
}