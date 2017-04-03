//============================================================================
// Name        : Module8_ExpressionTree.cpp
// Author      : Justin Kim
// Description : This file is a set of classes that can represent
//				 arithmetic expressions. That is, tree where the intereior nodes
//			     are arithmetic operations and the leaves are either variables or
//      		 constants.
//============================================================================

#include <iostream>
#include <sstream>
#include <map>
using namespace std;

/**
 * This Node class is a parent class of tree,
 * constant, and variable
 */
class Node {

public:

	virtual double evaluate() = 0;
};

/**
 * This Constant class is inherited from Node class
 * This class contains a number of constant
 */
class Constant: public Node {

	double number;

public:

	// constructor
	Constant(double value) {
		number = value;

	}

	// evaluate() returns a constant number
	double evaluate() {
		return number;
	}

};

/**
 * This Variable class is inherited from Node class
 * This class contains a variable and its number as a double
 */
class Variable: public Node {

	double number;
	string variable;

public:

	// constructor for double value
	Variable(double value) {
		number = value;
	}

	// constructor for string value
	Variable(string const& v) : variable(v) {

	}

	// evaluate() returns a number of the variable
	double evaluate() {
		return number;
	}

	// getVariable() returns its string value
	string getVariable() {
		return variable;
	}
};

/**
 * This Tree class is inherited from Node class
 * This class contains two node, left node and right node.
 * Also, this class contains a table allows to store
 * and retrieve the value associated with each variable
 */
class Tree : public Node {

protected:

	Node *leftNode;
	Node *rightNode;
	map<string, double> symbolTable;
};

/**
 * This Add class is add arithmetic operations class
 * that adds left node and right node
 */
class Add : public Tree {

public:

	// constructor
	Add(Node *leftNode, Node *rightNode) {
		this -> leftNode = leftNode;
		this -> rightNode = rightNode;
	}

	// evaluate() adds values of left node and right node
	double evaluate() {
		double leftNodeValue = leftNode -> evaluate();
		double rightNodeValue = rightNode -> evaluate();

		return leftNodeValue + rightNodeValue;
	}

	friend ostream& operator<<(ostream& os, const Add& add);

	// return output an expression tree of add
	string getExpression() const {

		ostringstream lstrs;
		lstrs << leftNode -> evaluate();
		string leftStr = lstrs.str();

		ostringstream rstrs;
		rstrs << rightNode -> evaluate();
		string rightStr = rstrs.str();

		return "(" + leftStr + " + " + rightStr + ")";
	}
};

// overload for operator << to display
ostream& operator<<(ostream& os, const Add& add) {
	os << add.getExpression();
	return os;
}

/**
 * This Sub class is subtract arithmetic operations class
 * that subtracts left node and right node
 */
class Sub : public Tree {

public:

	// constructor
	Sub(Node *leftNode, Node *rightNode) {
		this -> leftNode = leftNode;
		this -> rightNode = rightNode;
	}

	// evaluate() subtract values of left node and right node
	double evaluate() {
		double leftNodeValue = leftNode -> evaluate();
		double rightNodeValue = rightNode -> evaluate();

		return leftNodeValue - rightNodeValue;
	}

	friend ostream& operator<<(ostream& os, const Sub& sub);

	// return output an expression tree of subtraction
	string getExpression() const {
		ostringstream lstrs;
		lstrs << leftNode -> evaluate();
		string leftStr = lstrs.str();

		ostringstream rstrs;
		rstrs << rightNode -> evaluate();
		string rightStr = rstrs.str();

		return "(" + leftStr + " - " + rightStr + ")";
	}
};

// overload for operator << to display
ostream& operator<<(ostream& os, const Sub& sub) {
	os << sub.getExpression();
	return os;
}

/**
 * This Mul class is multiple arithmetic operations class
 * that multiplies left node and right node
 */
class Mul : public Tree {

public:

	// constructor
	Mul(Node *leftNode, Node *rightNode) {
		this -> leftNode = leftNode;
		this -> rightNode = rightNode;
	}

	// evaluate() multiplies values of left node and right node
	double evaluate() {
		double leftNodeValue = leftNode -> evaluate();
		double rightNodeValue = rightNode -> evaluate();

		return leftNodeValue * rightNodeValue;
	}

	friend ostream& operator<<(ostream& os, const Mul& mul);

	// return output an expression tree of multiple
	string getExpression() const {
		ostringstream lstrs;
		lstrs << leftNode -> evaluate();
		string leftStr = lstrs.str();

		ostringstream rstrs;
		rstrs << rightNode -> evaluate();
		string rightStr = rstrs.str();

		return "(" + leftStr + " * " + rightStr + ")";
	}
};

// overload for operator << to display
ostream& operator<<(ostream& os, const Mul& mul) {
	os << mul.getExpression();
	return os;
}

/**
 * This Div class is divide arithmetic operations class
 * that divides left node by right node
 */
class Div : public Tree {

public:

	// constructor
	Div(Node *leftNode, Node *rightNode) {
		this -> leftNode = leftNode;
		this -> rightNode = rightNode;
	}

	// evaluate() divides values of left node and right node
	double evaluate() {
		double leftNodeValue = leftNode -> evaluate();
		double rightNodeValue = rightNode -> evaluate();

		// error check : when the number is divided by 0
		// only right node value is not a zero, then
		// divide the numbers
		if(rightNodeValue !=0 ) {
			return leftNodeValue / rightNodeValue;
		}
		// if the right node value is zero, then just return 0
		else {
			return 0;
		}
	}

	friend ostream& operator<<(ostream& os, const Div& div);

	// return output an expression tree of divide
	string getExpression() const {
		ostringstream lstrs;
		lstrs << leftNode -> evaluate();
		string leftStr = lstrs.str();

		ostringstream rstrs;
		rstrs << rightNode -> evaluate();
		string rightStr = rstrs.str();

		return "(" + leftStr + " / " + rightStr + ")";
	}
};

// overload for operator << to display
ostream& operator<<(ostream& os, const Div& div) {
	os << div.getExpression();
	return os;
}

int main() {

	// test Add
	Add a(Add(new Constant(1.0), new Constant(4.0)));
	cout << "Add = " << a << endl;
	cout << "Add value = " << a.evaluate() << endl;

	// test Sub
	Sub b(Sub(new Constant(5.0), new Constant(3.0)));
	cout << "Sub = " << b << endl;
	cout << "Sub value = " << b.evaluate() << endl;

	// test Mul
	Mul c(Mul(new Constant(2.0), new Constant(8.0)));
	cout << "Mul = " << c << endl;
	cout << "Mul value = " << c.evaluate() << endl;

	// test Div
	Div d(Div(new Constant(10.0), new Constant(2.0)));
	cout << "Div = " << d << endl;
	cout << "Div value = " << d.evaluate() << endl;

	// test Div divided by 0
	Div e(Div(new Constant(10.0), new Constant(0.0)));
	cout << "Div = " << e << endl;
	cout << "Div value = " << e.evaluate() << endl;

	return 0;
}