// Daniel Kobold
// CSCI363 PA4
// Expr_Tree_Builder.cpp

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

Expr_Tree_Builder::Expr_Tree_Builder (void)
	:tree_(nullptr),
	sub_(nullptr),
	level_(1),
	details_(false)
{
	tree_ = new Expr_Tree();
}

Expr_Tree_Builder::~Expr_Tree_Builder (void)
{
	if(tree_!= nullptr)
		delete tree_;
	
	if(sub_!= nullptr)
	{
		if(details_)
			std::cout << "Sub Builder DELETED\n";
		delete sub_;
	}
}

///Start Expression - set the new head node (at the beginning)
void Expr_Tree_Builder::start_expression (void)
{
	
}	

void Expr_Tree_Builder::build_number (int n)
{
	Number_Node * node_ = new Number_Node(n);
	insert_node(node_);
}

void Expr_Tree_Builder::build_addition_operator (void)
{
	Addition_Node * node_ = new Addition_Node();
	insert_node(node_);
}

void Expr_Tree_Builder::build_subtraction_operator (void)
{
	Subtraction_Node * node_ = new Subtraction_Node();
	insert_node(node_);
}

void Expr_Tree_Builder::build_multiplication_operator (void)
{
	Multiplication_Node * node_ = new Multiplication_Node();
	insert_node(node_);
}

void Expr_Tree_Builder::build_division_operator (void)
{
	Division_Node * node_ = new Division_Node();
	insert_node(node_);
}

void Expr_Tree_Builder::build_modulus_operator (void)
{
	Modulus_Node * node_ = new Modulus_Node();
	insert_node(node_);
}

void Expr_Tree_Builder::build_open_parenthesis (void)
{
	//Does nothing (really does something elsewhere)
}

void Expr_Tree_Builder::build_close_parenthesis (void)
{
	//Does nothing
}

bool Expr_Tree_Builder::insert_node (Expr_Node * node)
{	
	//Used for moving a node to the left or the right
	Expr_Node * tempLeft;
	Expr_Node * tempRight;
	
	//Keeps track of if the node has been placed yet
	bool placed = false;

	//Used for selecting a node to add a child to
	Expr_Node * temp = nullptr;
	
	//"Focus" or starting point for the search
	Expr_Node * focus;
	
	if(details_)
		std::cout<< "\t(" << getLevel() << ")";

	//If node is a number
	if(node->getPrecedence() == 1)
	{
		if(details_)
			std::cout << "->Number, ";
		
		//Set head node
		if(tree_->get_head_node() == nullptr)
		{
			if(details_)
				std::cout << "New Head Node\n";
			
			tree_->set_head_node(node);
			//placed = true;
			return true;
		}
		else
		{
			if(details_)
				std::cout << "Something Else, ";
			
			//Search the tree and (if possible) insert the node into the tree
			placed = search(tree_->get_head_node(),node);		
			
			if(details_)
				std::cout << placed << "\n";
			
			return placed;
		}
	}
	else
	{
		if(details_)
			std::cout << "->Operator, ";
		
		if(tree_->get_head_node()->getPrecedence() == 1)
		{
			if(details_)
				std::cout << "New Head Node from Number\n";
			
			tempLeft = tree_->get_head_node();
			tree_->set_head_node(node);
			tree_->get_head_node()->setLeft(tempLeft);
			
		}
		//If precedence is lower or equal, make new head node IF the node to be added is not a sub-expression
		else if(node->getPrecedence() <= tree_->get_head_node()->getPrecedence() && node->getLeft()==nullptr)
		{
			if(details_)
				std::cout << "New Head Node from Operator\n";
			
			//Prepare to move current head to be the left child
			tempLeft = tree_->get_head_node();
			
			//Set this node as new head node
			tree_->set_head_node(node);
		
			//Transfer to the left node of the new head node
			tree_->get_head_node()->setLeft(tempLeft);
		}
		else
		{
			if(details_)
				std::cout << "Something Else, ";
			
			//Replace number on right IF the node to be added is not a sub-expression
			if(tree_->get_head_node()->getRight() != nullptr && node->getLeft()==nullptr)
			{
				if(details_)
					std::cout << "Replaced a Number on the Right\n";
				
				//Prepare to move current head to be the left child
				tempRight = tree_->get_head_node()->getRight();
				
				//Set this node as new head node
				tree_->get_head_node()->setRight(node);
			
				//Transfer to the left node of the new head node
				tree_->get_head_node()->getRight()->setLeft(tempRight);
			}
			else if(node->getLeft()==nullptr)
			{
				if(details_)
					std::cout << "Inserted Directly on Right\n";
				
				tree_->get_head_node()->setRight(node);
			}
			//Only happens if node being added is a head of a sub-expression
			else
			{
				focus = tree_->get_head_node();
				while(focus->getRight() != nullptr && focus->getPrecedence() != 1)
				{
					focus = focus->getRight();
				}
				
				if(focus->getRight() == nullptr)
					focus->setRight(node);
				else
					return false;
			}
		}
		
	}
}

bool Expr_Tree_Builder::search(Expr_Node * focus, Expr_Node * node)
{
	bool temp = false;
	
	//If node is binary
	if(focus->getPrecedence() == 2 || focus->getPrecedence() == 3)
	{
		
		if(focus->getRight() == nullptr && !temp)
		{
			if(details_)
				std::cout << "Right";
			focus->setRight(node);
			return true;
		}
		
		if(focus->getLeft() == nullptr && !temp)
		{
			if(details_)
				std::cout << "Left";
			
			focus->setLeft(node);
			return true;
		}
		
		//Try another branch
		if(focus->getRight() != nullptr && !temp)
		{
			if(details_)
				std::cout << "Right Branch, ";
			
			temp = search(focus->getRight(),node);
		}
		
		if(focus->getLeft() != nullptr && !temp)
		{
			if(details_)
				std::cout << "Left Branch, ";
			
			temp = search(focus->getLeft(),node);
		}
		
		
	}
	return false;
}

///Get Tree
Expr_Tree * Expr_Tree_Builder::get_tree(void)
{
	return tree_;
}

///Set Level
void Expr_Tree_Builder::setLevel(int lv)
{
	level_ = lv;
}

///Get Level
int Expr_Tree_Builder::getLevel (void)
{
	return level_;
}

//Same as insert, but strictly for inserting on the right side of a node
bool Expr_Tree_Builder::insert_node_on_right(Expr_Node * node)
{
	if(node->getPrecedence() == 1)
	{
		return false;
	}
	else if(node->getRight() == nullptr)
	{
		node->setRight(node);
		return true;
	}
	else
	{
		if(details_)
			std::cout << "Right,";
		
		return insert_node_on_right(node->getRight());
	}
	
}

///Set Details
void Expr_Tree_Builder::setDetails(void)
{
	details_ = true;
}

///Set Sub-Builder (allows deletion later)
void Expr_Tree_Builder::setSubBuilder(Expr_Tree_Builder * sub)
{
	if(details_)
		std::cout << "Sub Builder acknowledged.\n";
	sub_ = sub;
}




