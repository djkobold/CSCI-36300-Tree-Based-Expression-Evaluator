// Daniel Kobold
// CSCI363 PA4
// Binary_Expr_Node.cpp

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

Binary_Expr_Node::Binary_Expr_Node (void)
	:left_(nullptr),
	right_(nullptr)
{
	
}

Binary_Expr_Node::~Binary_Expr_Node (void)
{
	if(left_ != nullptr)
		delete left_;
	if(right_ != nullptr)
		delete right_;
}

///Additional Operations
void Binary_Expr_Node::print_preorder (std::ostream & out)
{
	this->print();
	
	if(this->getLeft() != nullptr)
		this->getLeft()->print();
	else
		std::cout << "ERROR: Missing Element to Print.\n";
	
	if(this->getRight() != nullptr)
		this->getRight()->print();
	else
		std::cout << "ERROR: Missing Element to Print.\n";
	
}

void Binary_Expr_Node::print_inorder (std::ostream & out)
{
	if(this->getLeft() != nullptr)
		this->getLeft()->print();
	else
		std::cout << "ERROR: Missing Element to Print.\n";
	
	this->print();
	
	if(this->getRight() != nullptr)
		this->getRight()->print();
	else
		std::cout << "ERROR: Missing Element to Print.\n";
	
}

Expr_Node * Binary_Expr_Node::getLeft(void)
{
	return left_;
}

Expr_Node * Binary_Expr_Node::getRight(void)
{
	return right_;
}

void Binary_Expr_Node::setLeft(Expr_Node * left)
{
	left_ = left;
}

void Binary_Expr_Node::setRight(Expr_Node * right)
{
	right_ = right;
}

