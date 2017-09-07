#pragma once

#include "CosNode.h"

void CosNode::forwardProp() { m_val = cos(prev->get_val()); }

void CosNode::backwardProp(bool first) {
	if (first)m_grad = 1;
	double new_grad = prev->get_grad() + sin(prev->get_val()) * m_grad * (-1);
	prev->set_grad(new_grad);
	prev->backwardProp();
}

void CosNode::forwardDebug() {
	if (dinit) return;
	Node::set_expr("cos(" + prev->get_expr() + ")");
	dinit = true;
}

void CosNode::backwardDebug(bool first) {
	if (first)grad_expr = "1";
	std::string new_expr = prev->get_grad_expr() != "" ? (prev->get_grad_expr() + "+" + "(-sin(" + prev->get_expr() + "))*(" + grad_expr + ")") : "(-sin(" + prev->get_expr() + "))*(" + grad_expr + ")";
	prev->set_grad_expr(new_expr);
	prev->backwardDebug();
}