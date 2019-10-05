// Daniel Kobold
// CSCI363 PA4
// Unary_Expr_Node.cpp

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

Unary_Expr_Node::Unary_Expr_Node(void)
	:child_(nullptr)
{
	
}

Unary_Expr_Node::~Unary_Expr_Node(void)
{
	
}

int Unary_Expr_Node::eval(void)
{
	if(this->child_)
		return this->child_->eval();
}

///Additional Operations
void Unary_Expr_Node::print_preorder (std::ostream & out)
{
	this->print();
	
	if(this->child_ != nullptr)
		this->child_->print();
	else
		std::cout << "ERROR: Missing Element to Print.\n";	
}

void Unary_Expr_Node::print_inorder (std::ostream & out)
{
	if(this->child_ != nullptr)
		this->child_->print();
	else
		std::cout << "ERROR: Missing Element to Print.\n";
	
	this->print();	
}

int Unary_Expr_Node::getPrecedence(void)
{
	return 6;
}

std::string Unary_Expr_Node::print(void)
{
	return "?";
}

void Unary_Expr_Node::accept (Expr_Node_Visitor & v)
{
	//Does nothing
}

