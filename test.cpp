#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>

#include "../src/Graph.h"

using namespace std;

int main() {
	cout << "Running tests..." << endl;
	// The following test is used to measure memory leaks and time complexity
	for (int i = 1; i <= 20000; i++) {
		Node x("x");
		float e = exp(1);
		Graph g = (sin(pow(e, x) + pow(x, 2))*cos(e*pow(x, 4)*ln(x))) / (tan(6 * x)*ln(pow(x, 2) + 6 * x - 32));
		g.init({ { &x, 13 } });
		g.get_output();
		g.get_grad(&x);
		g.output_debug();
		g.grad_debug(&x);
		if (i % 10000 == 0)printf("%d\n", i);
	}
	// Correct derivative for x = 13 is: 19811.8012443
	// Correct output for x = 13 is: 0.0052306755

	// f(x) = (sin(e^x+x^2)*cos(e*x^4*ln(x)))/(tan(6*x)*ln(x^2+6*x-32))
	// f'(x) = -((4*e*x^3*ln(x)+e*x^3)*sin(e^x+x^2)*sin(e*x^4*ln(x)))/(tan(6*x)*ln(x^2+6*x-32))-(6*sec(6*x)^2*sin(e^x+x^2)*cos(e*x^4*ln(x)))/(tan(6*x)^2*ln(x^2+6*x-32))-((2*x+6)*sin(e^x+x^2)*cos(e*x^4*ln(x)))/((x^2+6*x-32)*tan(6*x)*ln(x^2+6*x-32)^2)+((e^x+2*x)*cos(e^x+x^2)*cos(e*x^4*ln(x)))/(tan(6*x)*ln(x^2+6*x-32))
	
	cout << "SUCCESS" << endl;
}