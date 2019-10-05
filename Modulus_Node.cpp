// Daniel Kobold
// CSCI363 PA4
// Modulus_Node.cpp

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

///Constructor
Modulus_Node::Modulus_Node (void)
{
	//Does nothing else
}

///Evaluate
int Modulus_Node::eval(void)
{
	int n1 = getLeft()->eval();
	int n2 = getRight()->eval();
	
	//If the number is not being divided by zero, complete the division
	//Otherwise, throw the exception
	if(n2 == 0)
	{
		throw divByZero();
	}
	else
	{
		return n1%n2;
	}
}

///Get Precedence
int Modulus_Node::getPrecedence(void)
{
	return 3;
}

///Print this Element
std::string Modulus_Node::print(void)
{
	return "%";
}

///Accept Visitor
void Modulus_Node::accept (Expr_Node_Visitor & v)
{
	v.Visit_Modulus_Node (*this);
}

