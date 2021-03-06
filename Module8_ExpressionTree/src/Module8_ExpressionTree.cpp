//============================================================================
// Name        : Module8_ExpressionTree.cpp
// Author      : Justin Kim
// Description : This file is a set of classes that can represent
//				 arithmetic expressions. That is, tree where the interior nodes
//			     are arithmetic operations and the leaves are either variables or
//      		 constants.
//============================================================================

#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

map<string, double> symbolTable;

/**
 * This Node class is a parent class of tree,
 * constant, and variable
 */
class Node {

public:

	virtual double evaluate() = 0;
	virtual string getExpression() const = 0;
	virtual double derivative() = 0;
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

	// getExpression() returns a string of number
	string getExpression() const {
		ostringstream numString;
		numString << number;
		return numString.str();
	}

	// derivative() returns 0
	double derivative() {
		return 0.0;
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
		return symbolTable[variable];
	}

	// getExpression() returns a string of the variable
	string getExpression() const {
		return variable;
	}

	// derivative() returns a number of variable
	double derivative() {
		return symbolTable[variable];
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

	// derivative() adds value of left node derivative value
	// and right node of derivative value
	// u + v = du + dv
	double derivative() {
		double leftNodeDerivativeValue = leftNode -> derivative();
		double rightNodeDerivativeValue = rightNode -> derivative();

		return leftNodeDerivativeValue + rightNodeDerivativeValue;
	}

	friend ostream& operator<<(ostream& os, const Add& add);

	// return output an expression tree of add
	string getExpression() const {

		return "(" + leftNode -> getExpression() + " + " +
					 rightNode -> getExpression() + ")";
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

	// derivative() subtracts value of left node derivative value
	// and right node of derivative value
	// u - v = ud - dv
	double derivative() {
		double leftNodeDerivativeValue = leftNode -> derivative();
		double rightNodeDerivativeValue = rightNode -> derivative();

		return leftNodeDerivativeValue - rightNodeDerivativeValue;
	}


	friend ostream& operator<<(ostream& os, const Sub& sub);

	// return output an expression tree of subtraction
	string getExpression() const {

		return "(" + leftNode -> getExpression() + " - " +
					 rightNode -> getExpression() + ")";
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

	// derivative() multiplies value of left node derivative value
	// and right node of derivative based on the formula
	// u * v = u*dv + v*du
	double derivative() {
		double value = leftNode -> evaluate() * rightNode -> derivative() +
				rightNode -> evaluate() * leftNode -> derivative();

		return value;
	}

	friend ostream& operator<<(ostream& os, const Mul& mul);

	// return output an expression tree of multiple
	string getExpression() const {
		return "(" + leftNode -> getExpression() + " * " +
					 rightNode -> getExpression() + ")";
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

	// derivative() divides value of left node derivative value
	// and right node of derivative based on the formula
	// u / v = (v*du - u*dv) / v*v
	double derivative() {
		double value = (rightNode -> evaluate() * leftNode -> derivative() -
						leftNode -> evaluate() * rightNode -> derivative()) /
						(rightNode -> evaluate() * rightNode -> evaluate());

		return value;
	}

	friend ostream& operator<<(ostream& os, const Div& div);

	// return output an expression tree of divide
	string getExpression() const {
		return "(" + leftNode -> getExpression() + " / " +
					 rightNode -> getExpression() + ")";
	}
};

// overload for operator << to display
ostream& operator<<(ostream& os, const Div& div) {
	os << div.getExpression();
	return os;
}

int main() {

	/****************************************
	//test regular expression tree
	*****************************************/

	cout << "******** Test regular expression tree ********" << endl;

	// let X = 2.0, Y = 3.0, Z = 5.0
	symbolTable["X"] = 2.0;
	symbolTable["Y"] = 3.0;
	symbolTable["Z"] = 5.0;

	cout << "X = " << symbolTable["X"] << ", Y = " << symbolTable["Y"] << ", Z = " << symbolTable["Z"] << endl;

	// 2.3 * X
	Mul m1(Mul(new Constant(2.3), new Variable("X")));

	// Z - X
	Sub s(Sub(new Variable("Z"), new Variable("X")));

	// Y * (Z - X)
	Mul m2(Mul(new Variable("Y"), &s));

	// (2.3 * X) + (Y * (Z - X)
	Add a(Add(&m1, &m2));

	// Output an expression tree
	cout << "Output: " << a << endl;

	// Evaluate an expression tree
	cout << "Value: " << a.evaluate() << endl;


	//Error check, when divided by 0 --> output is always 0
	Div d(Div(new Constant(2.3), new Constant(0)));
	cout << "**** Error Check : Divided by 0 -> output = 0 ***" << endl;
	cout << "Output: " << d << endl;
	cout << "Value: " << d.evaluate() << endl;




	/****************************************
	//test derivative expression tree
	*****************************************/

	cout << "******** Test derivative expression tree ********" << endl;

	// let X = 1.0, Y = 0.0, Z = 0.0
	symbolTable["X"] = 1.0;
	symbolTable["Y"] = 0.0;
	symbolTable["Z"] = 0.0;

	cout << "X = " << symbolTable["X"] << ", Y = " << symbolTable["Y"] << ", Z = " << symbolTable["Z"] << endl;

	// for output
	Mul dm1(Mul(new Constant(2.3), new Constant(1.0)));
	Mul dm2(Mul(new Variable("X"), new Constant(0.0)));

	Add da1(Add(&dm1, &dm2));

	Sub ds1(Sub(new Constant(0.0), new Constant(1.0)));
	Mul dm3(Mul(new Variable("Y"), &ds1));

	Sub ds2(Sub(new Variable("Z"), new Variable("X")));
	Mul dm4(Mul(&ds2, new Constant(0.0)));

	Add da2(Add(&dm3, &dm4));

	Add da3(Add(&da1, &da2));

	// Output an expression tree
	cout << "Output: " << da3 << endl;

//////////////////////////////////////////////////////////

	// 2.3 * X
	Mul d_m1(Mul(new Constant(2.3), new Variable("X")));

	// Z - X
	Sub d_s(Sub(new Variable("Z"), new Variable("X")));

	// Y * (Z - X)
	Mul d_m2(Mul(new Variable("Y"), &d_s));

	// (2.3 * X) + (Y * (Z - X)
	Add d_a(Add(&d_m1, &d_m2));


	// Derivative value of expression tree
	cout << "Derivative Value: " << d_a.derivative() << endl;


	return 0;
}
