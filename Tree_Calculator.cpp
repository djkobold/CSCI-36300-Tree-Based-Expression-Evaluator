// Daniel Kobold
// CSCI363 PA4
// Tree_Calculator.cpp

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

Tree_Calculator::Tree_Calculator(void)
	:builder_(nullptr),
	details_(false)
{
	//Does nothing else
}

///Destructor
Tree_Calculator::~Tree_Calculator(void)
{
	if(builder_ != nullptr)
		delete builder_;
}

Expr_Tree_Builder * Tree_Calculator::parse_expr (const std::string & infix, int level)
{	
	//Create an input stream parser
	std::istringstream input (infix);

	//New builder
	builder_ = new Expr_Tree_Builder();

	
	if(details_)
		builder_->setDetails();
	
	Expr_Tree_Builder * topBuilder_;
	
	Expr_Tree_Builder * subBuilder_;
	
	//Set the level of sub-expression (if applicable)
	builder_->setLevel(level);

	//Current token in string/stream
	std::string token(" ");				

	//Precedence of current node being added
	int prec = 0;
	
	//Number of tokens that need to be skipped after subexpression insertion (parentheses)
	int indexCount = 0;
	
	//Number of left to right parentheses
	int parLevel = 0;
	
	int length = 0;
	
	while(!input.eof())
	{
		indexCount = 0;
		input >> token;
		
		if(details_)
			std::cout << "Token = " << token;
		
		Expr_Tree * subTree;
		Expr_Node * subExpression;
		
		//Token string comparison -> build operators
		if(token == "+")
		{
			builder_->build_addition_operator();
		}
		else if(token == "-")
		{
			builder_->build_subtraction_operator();
		}
		else if(token == "*")
		{
			builder_->build_multiplication_operator();
		}
		else if(token == "/")
		{
			builder_->build_division_operator();
		}
		else if(token == "%")
		{
			builder_->build_modulus_operator();
		}
		else if(token == "(")
		{
			parLevel++;
			indexCount++;
			
			while(parLevel != 0 && !input.eof())
			{
				input >> token;
				indexCount++;
				if(token == "(")
					parLevel++;
				else if(token == ")")
					parLevel--;
			}

			//Find length of the subexpression
			length = infix.rfind(")") - infix.find("(");
			
			if(details_)
				std::cout << "\nSubstring=" << infix.substr(infix.find("(")+1, length-2) << "\n";
			
			//Set aside the builder for the top level of this subexpression
			topBuilder_ = builder_;
			
			//This is used in the case of a double parentheses, adding a " 0 + " to the beginning of sub-expression
			if(builder_->get_tree()->get_head_node() == nullptr)
			{
				builder_->build_number(0);
				builder_->build_addition_operator();
			}
			
			//Parse the sub-expression and retrieve the subtree
			subBuilder_ =  parse_expr(infix.substr(infix.find("(")+1, length-2), this->builder_->getLevel()+1);
			this->builder_->setSubBuilder(subBuilder_);
			
			subTree = subBuilder_->get_tree();
			
			//Retrieve the head node from the subtree
			subExpression = subTree->get_head_node();
			
			
			
			//If details are on, print out info
			if(details_)
				std::cout << "\t\t(" << topBuilder_->getLevel() << ")=>";
			
			
			if(topBuilder_->get_tree()->get_head_node()->getRight() == nullptr)
			{
				if(details_)
					std::cout << "Placed right directly.\n";
				
				topBuilder_->get_tree()->get_head_node()->setRight(subExpression);
				
			}
			else
			{
				if(details_)
					std::cout << "Attempting Insertion...";
				
				if(topBuilder_->insert_node(subExpression))
				{
					if(details_)
						std::cout << "Insertion Successful.\n";
				}
				else
				{
					if(details_)
						std::cout << "Insertion FAILED.\n";
				}
			}
			
			builder_=topBuilder_;
			
		}
		else if(token == ")")
		{
			//Does nothing
		}
		else if(token.find_first_not_of("+-0123456789") == std::string::npos)
		{
			try{
				//Use stoi to change string to integer
				builder_->build_number(std::stoi(token));
			}
			catch(std::out_of_range & o)
			{
				//Out of range number was entered
				throw invalidNums();
			}
			catch(std::exception & e)
			{
				//Throw the error that occurred (probably stoi error)
				throw e;
			}
		}
		//Otherwise, an invalid argument was reached
		else
		{			
			throw invalidArgs();
		}		
	}

	return builder_;
}

//Runs everything by calling other functions
void Tree_Calculator::calculate (void)
{
	//Input string for parsing
	std::string infix_;						

	//Get a line and store in string	
	std::getline(std::cin, infix_);		

	//Size of expression (by number of elements)
	size_t exprSize_ = 0;
	
	while(infix_ != "QUIT")
	{
		//Stack of integers
		Stack<int> numStack_;					

		//Integer to help stop this iteration execution if needed
		int detected_ = 0;						
		
		//Head node of the FULL expression
		Expr_Node * expression;
		
		Expr_Tree_Builder * exBuild_ = nullptr;
		
		//Find number of elements
		exprSize_ = findSize(infix_);
		
		Expr_Tree * exTree;
		
		if(details_)
			std::cout << "exprSize_ = " << exprSize_ << "\n";
		
		//Attempt to parse expression, catch any errors
		try{
			exBuild_ = parse_expr(infix_, 1);
			exTree = exBuild_->get_tree();
			expression = exTree->get_head_node();
		}
		catch(std::exception & ex){
			std::cout << "ERROR: " << ex.what() << "\n";
			detected_ = 1;
		}
		catch(std::string errCon){
			std::cout << "ERROR: " << errCon << "\n";
			detected_ = 1;
		}
		catch(...){
			std::cout << "ERROR: Infix to Postfix conversion failed.\n";
			detected_ = 1;
		}
		
		if(detected_ == 0)
		{
			if(details_)
				std::cout << "RESULT (using eval) = \t" << expression->eval() << "\n";		
			
			
			Print_Preorder_Expression preorder;
			expression->accept(preorder);
			std::string preorder_expression = preorder.result();
			std::cout << "PREORDER: \t" << preorder_expression << "\n";
			
			Print_Inorder_Expression inorder;
			expression->accept(inorder);
			std::string inorder_expression = inorder.result();
			std::cout << "INORDER: \t" << inorder_expression << "\n";
			
			Print_Postorder_Expression postorder;
			expression->accept(postorder);
			std::string postorder_expression = postorder.result();
			std::cout << "POSTORDER: \t" << postorder_expression << "\n";
			
			try{
				Eval_Expr_Tree problem;
				expression->accept(problem);
				int res = problem.result();
			
				if(details_)
					std::cout << "RESULT (using visitor) = \t" << res << "\n";
				else
					std::cout << "RESULT = \t" << res << "\n";
			
			
			}
			catch(std::exception & e)
			{
				std::cout << "ERROR: " << e.what() << "\n";
			}
			
			
		
		}
		
		//Output newlines (for formatting)
		std::cout << "\n\n";						

		//Get the next line
		std::getline(std::cin, infix_);				
	}
	
}

//Find number of elements to be made
size_t Tree_Calculator::findSize(const std::string & infix)	
{
	//Start size at 0
	size_t size_ = 0;					

	//Make stringstream
	std::stringstream inSize_(infix);	

	//Make a token
	std::string tok_;									
	
	//While not at end of input
	while(!inSize_.eof())								
	{
		//Move input to token
		inSize_ >> tok_;									
		
		//Increment postfix expression size as long as the token is not a parentheses
		if(tok_ != ")" && tok_ != "(")
			size_++;
	}
	
	return size_;
}

//Find size including parentheses
size_t Tree_Calculator::findTotalSize(const std::string & infix)
{
	//Start size at 0
	size_t size_ = 0;					

	//Make stringstream
	std::stringstream inSize_(infix);	

	//Make a token
	std::string tok_;									
	
	//While not at end of input
	while(!inSize_.eof())								
	{
		//Move input to token
		inSize_ >> tok_;									

		size_++;
	}
	
	return size_;
}

//Basic exponent evaluator
int Tree_Calculator::exponent(int num, int exp)
{
	int times = exp;
	int result = 1;
	while(times > 0)
	{
		result = result * num;
		times--;
	}
	
	return result;
	
}

void Tree_Calculator::includeDetails (void)
{
	details_ = true;
}




