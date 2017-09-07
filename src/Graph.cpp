#pragma once

#include "Graph.h"

double Graph::get_output() {
	if (fp)return output->get_val();
	output->forwardProp();
	fp = true;
	return output->get_val();
}

double Graph::get_grad(Node* x) {
	if (bp)return x->get_grad();
	if (!fp)output->forwardProp();
	output->backwardProp(true);
	bp = true;
	return x->get_grad();
}

void Graph::init(std::map<Node*, double> feed_dict) {
	for (std::pair<Node*, double> x : feed_dict) { x.first->set_val(x.second); }
	fp = false;
	bp = false;
}

void Graph::reset() {
	fp = false;
	bp = false;
	output->reset();
}

// Debugging
std::string Graph::output_debug() {
	output->forwardDebug();
	return output->get_expr();
}

std::string Graph::grad_debug(Node* x) {
	output->backwardDebug(true);
	return x->get_grad_expr();
}