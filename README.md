# Reverse-Mode-Automatic-Differentiation-Cpp
A simple implementation of reverse mode automatic differentiation in C++ without the use of any libraries.

### What is this project all about
This is an implementation of Reverse Mode AD in C++. A lot of the concepts of basic calculus are applied using the Chain Ruler and the derivatives of basic functions. The purpose of the project
was to help me understand how reverse mode AD works and potentially help others understand the concepts too. This 'library' isn't written using a fancy external library or anything. It is simple
and clear C++, easy to understand by programmers that don't know C++. So it may give you some insight nonetheless.

### The Code
The code is written in C++ and is split to several classes. Each operation is help by a seperate node. For example one node does addition one calculates the sine and so on. To keep things simple and
organized there is a simple hierarchy of classes that helps maintain the code and it looks like this:


```cpp
Node -> This is the base class the building block of anything else(also acts like a placeholder node that is useful when intializing a node with a single value)
UnaryNode and BinaryNode those are derived node classes that allow operations on 1 and 2 nodes respectively.
	
Some Binary nodes are:
LogNode(base, x)
PowNode(base, x)
AddNode(x1, x2) etc...
	
Some Unary nodes are:
sin(x)
cos(x)
tan(x)
```

There is also the Graph class that helps interface the nodes and perform more complex operations on them. Such as using them without initializing them, building a graph that is ran only when needed etc.

To use the library you just have to include the ```"Graph.h"``` file or ```"../src/Graph.h"``` depending on how you have set up your project

Here are some code examples of how you may use this library:

```cpp
Node x("x");
float e = exp(1);
Graph g = (sin(pow(e, x) + pow(x, 2))*cos(e*pow(x, 4)*ln(x))) / (tan(6 * x)*ln(pow(x, 2) + 6 * x - 32));
g.init({ { &x, 13 } });
g.get_output(); // get output value of expression (as a double)
g.get_grad(&x); // get gradient with respect to x (as a double)
g.output_debug(); // get output value of expression (as a string)
g.grad_debug(&x); // get gradient with respect to x (as a string)
```

```cpp
Node a("a");
Node b("b");
Node c("c");
Graph g = c * ln(a + b);
g.init({ { &x, 13 } });
g.get_output();
g.get_grad(&x);
g.output_debug();
g.grad_debug(&x);
```

### Tests
I have tested rigorously the code on several equations (both simple identities and complex expressions) and it passes all of them. The test file only includes one of those tests. The one fore memory leakage and
expression correctness. Sometimes the expressions need very high precision and as such double data types may not be enough. In that case it is useful to check the backwardDebug function that helps you see
the derived expression as text.


I hope that you find this project useful on understanding reverse mode automatic differentiation.


Panagiotis Petridis, High School Student,
Greece
