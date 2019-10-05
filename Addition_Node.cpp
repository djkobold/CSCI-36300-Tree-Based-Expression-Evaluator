// Daniel Kobold
// CSCI363 PA4
// Addition_Node.cpp

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

///Constructor
Addition_Node::Addition_Node (void)
	:Binary_Expr_Node()
{
	//Does nothing else
}

///Evaluate
int Addition_Node::eval(void)
{
	//Get left and right elements
	int n1 = getLeft()->eval();
	int n2 = getRight()->eval();

	return n1 + n2;
}

///Get Precedence
int Addition_Node::getPrecedence(void)
{
	return 2;
}

///Print this Element
std::string Addition_Node::print(void)
{
	return "+";
}

///Accept Visitor
void Addition_Node::accept (Expr_Node_Visitor & v)
{
	v.Visit_Addition_Node (*this);
}
