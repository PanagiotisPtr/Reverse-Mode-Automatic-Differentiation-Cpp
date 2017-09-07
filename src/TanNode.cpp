#pragma once

#include "TanNode.h"

void TanNode::forwardProp() { m_val = tan(prev->get_val()); }

void TanNode::backwardProp(bool first) {
	if (first)m_grad = 1;
	double new_grad = prev->get_grad() + (1 / (cos(prev->get_val()) * cos(prev->get_val()))) * m_grad;
	prev->set_grad(new_grad);
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