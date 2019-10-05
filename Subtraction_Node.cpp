// Daniel Kobold
// CSCI363 PA4
// Subtraction_Node.cpp

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

///Constructor
Subtraction_Node::Subtraction_Node (void)
{
	//Does nothing else
}

///Evaluate
int Subtraction_Node::eval(void)
{
	int n1 = getLeft()->eval();
	int n2 = getRight()->eval();
	return n1 - n2;
}

///Get Precedence
int Subtraction_Node::getPrecedence(void)
{
	return 2;
}

///Get Flag - Returns Identification Number
int Subtraction_Node::getFlag(void)
{
	return 6;
}

///Print this Element
std::string Subtraction_Node::print(void)
{
	return "-";
}

///Accept Visitor
void Subtraction_Node::accept (Expr_Node_Visitor & v)
{
	v.Visit_Subtraction_Node (*this);
}

