// Daniel Kobold
// CSCI363 PA4
// Division_Node.cpp

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

///Constructor
Division_Node::Division_Node (void)
{
	//Does nothing else
}

///Evaluate
int Division_Node::eval(void)
{
	//std::string divByZero = "Dividing by zero causes undefined behavior.";
	
	int n1 = getLeft()->eval();
	int n2 = getRight()->eval();
	
	//If the number is not being divided by zero, complete the division
	//Otherwise, throw the exception
	if(n2 == 0)
	{
    // COMMENT I would recommend throwing an exception class, and not
    // a string.
	// RESPONSE An exception class is now thrown (see "Custom_Exception.cpp")
		throw divByZero();
	}
	else
	{
		return n1/n2;
	}
	
	return n1 * n2;
}

///Get Precedence
int Division_Node::getPrecedence(void)
{
	return 3;
}

///Print this Element
std::string Division_Node::print(void)
{
	return "/";
}

///Accept Visitor
void Division_Node::accept (Expr_Node_Visitor & v)
{
	v.Visit_Division_Node (*this);
}

