// Daniel Kobold
// CSCI363 PA4
// Print_Postorder_Expression.cpp

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

Print_Postorder_Expression::Print_Postorder_Expression(void)
	:result_("")
{
	//Does nothing
}

Print_Postorder_Expression::~Print_Postorder_Expression(void)
{
	//Does nothing
}

//Methods for visiting concrete nodes
///Visit Addition Node
void Print_Postorder_Expression::Visit_Addition_Node (Addition_Node & node)
{
	//String for if exception is called
	std::string missingOperands = "Evaluating the expression using a visitor has failed."; 
	
	//If left and right children exist
	if(node.getLeft() != nullptr && node.getRight() != nullptr)
	{
		//Visit left, retrieve result
		node.getLeft()->accept(*this);
		std::string s1 = this->result();
				
		//Visit right, retrieve result
		node.getRight()->accept(*this);
		std::string s2 = this->result();
		
		//Next is addition sign
		std::string s3 = "+";
		
		//Clear result, append sub-results
		result_ = "";
		result_.append(s1);
		result_.append(" ");
		result_.append(s2);
		result_.append(" ");
		result_.append(s3);
	}
	else
		throw missingOperands;
}

///Visit Subtraction_Node
void Print_Postorder_Expression::Visit_Subtraction_Node (Subtraction_Node & node)
{
	//String for if exception is called
	std::string missingOperands = "Evaluating the expression using a visitor has failed."; 
	
	//If left and right children exist
	if(node.getLeft() != nullptr && node.getRight() != nullptr)
	{
		//Visit left, retrieve result
		node.getLeft()->accept(*this);
		std::string s1 = this->result();
		
		//Visit right, retrieve result
		node.getRight()->accept(*this);
		std::string s2 = this->result();
		
		//Next is minus sign
		std::string s3 = "-";
		
		//Clear result, append sub-results
		result_ = "";
		result_.append(s1);
		result_.append(" ");
		result_.append(s2);
		result_.append(" ");
		result_.append(s3);
	}
	else
		throw missingOperands;
}

///Visit Multiplication_Node
void Print_Postorder_Expression::Visit_Multiplication_Node (Multiplication_Node & node)
{
	//String for if exception is called
	std::string missingOperands = "Evaluating the expression using a visitor has failed."; 
	
	//If left and right children exist
	if(node.getLeft() != nullptr && node.getRight() != nullptr)
	{
		//Visit left, retrieve result
		node.getLeft()->accept(*this);
		std::string s1 = this->result();
				
		//Visit right, retrieve result
		node.getRight()->accept(*this);
		std::string s2 = this->result();
		
		//Next is multiplication sign
		std::string s3 = "*";
		
		//Clear result, append sub-results
		result_ = "";
		result_.append(s1);
		result_.append(" ");
		result_.append(s2);
		result_.append(" ");
		result_.append(s3);
	}
	else
		throw missingOperands;
}

///Visit Division Node
void Print_Postorder_Expression::Visit_Division_Node (Division_Node & node)
{
	//String for if exception is thrown
	std::string missingOperands = "Evaluating the expression using a visitor has failed."; 
	
	//If left and right children exist
	if(node.getLeft() != nullptr && node.getRight() != nullptr)
	{
		//Visit left, retrieve result
		node.getLeft()->accept(*this);
		std::string s1 = this->result();
		
		//Visit right, retrieve result
		node.getRight()->accept(*this);
		std::string s2 = this->result();
		
		//Next is division sign
		std::string s3 = "/";
		
		//Clear result, append sub-results
		result_ = "";
		result_.append(s1);
		result_.append(" ");
		result_.append(s2);
		result_.append(" ");
		result_.append(s3);
	}
	else
		throw missingOperands;
}

///Visit Modulus Node
void Print_Postorder_Expression::Visit_Modulus_Node (Modulus_Node & node)
{
	//String for if exception is thrown
	std::string missingOperands = "Evaluating the expression using a visitor has failed."; 
	
	//If left and right children exist
	if(node.getLeft() != nullptr && node.getRight() != nullptr)
	{
		//Visit left, retrieve result
		node.getLeft()->accept(*this);
		std::string s1 = this->result();
				
		//Visit right, retrieve result
		node.getRight()->accept(*this);
		std::string s2 = this->result();
		
		//Next is modulus sign
		std::string s3 = "%";
		
		//Clear result, append sub-results
		result_ = "";
		result_.append(s1);
		result_.append(" ");
		result_.append(s2);
		result_.append(" ");
		result_.append(s3);
	}
	else
		throw missingOperands;
}

///Visit Number Node
void Print_Postorder_Expression::Visit_Number_Node (Number_Node & node)
{
	//Retrieve number from number node
	result_ = node.print();
}

//Return result
std::string Print_Postorder_Expression::result (void)
{
	return result_;
}
