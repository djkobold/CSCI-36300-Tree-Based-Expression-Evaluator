// Daniel Kobold
// CSCI363 PA4
// Unary_Expr_Node.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Expr_Node.h"
#include "Binary_Expr_Node.h"
#include "Unary_Expr_Node.h"
#include "Addition_Node.h"
#include "Subtraction_Node.h"
#include "Multiplication_Node.h"
#include "Division_Node.h"
#include "Modulus_Node.h"
#include "Number_Node.h"

Eval_Expr_Tree::Eval_Expr_Tree(void)
	:result_(0)
{
	//Does nothing
}

Eval_Expr_Tree::~Eval_Expr_Tree(void)
{
	//Does nothing
}

//Methods for visiting concrete nodes
///Visit Addition Node
void Eval_Expr_Tree::Visit_Addition_Node (Addition_Node & node)
{
	//If left and right children exist
	if(node.getLeft() != nullptr && node.getRight() != nullptr)
	{
		try{
			//Visit left, retrieve result
			node.getLeft()->accept(*this);
			int res1 = this->result_;	
			
			//Visit right, retrieve result
			node.getRight()->accept(*this);
			int res2 = this->result_;
		
			result_ = res1 + res2;
		}
		catch(std::exception & e)
		{
			throw e;
		}
		
	}
	else
		throw missingOperands();
}

///Visit Subtraction Node
void Eval_Expr_Tree::Visit_Subtraction_Node (Subtraction_Node & node)
{	
	//If left and right children exist
	if(node.getLeft() != nullptr && node.getRight() != nullptr)
	{	
		try{
			
				//Visit left, retrieve result
				node.getLeft()->accept(*this);
			
			// COMMENT Why not just access result_ directly since it belongs
			// to this class, and you are setting it below.
			// RESPONSE result_ is now accessed directly.
			
				int res1 = this->result_;
				
				//Visit right, retrieve result
				node.getRight()->accept(*this);
			
			// COMMENT Why not just access result_ directly since it belongs
			// to this class, and you are setting it below.
			// RESPONSE result_ is now accessed directly.
			
				int res2 = this->result_;
		
			result_ = res1 - res2;
		}
		catch(std::exception & e)
		{
			throw e;
		}
		
		
	}
	else
		throw missingOperands();
}

///Visit Multiplication Node
void Eval_Expr_Tree::Visit_Multiplication_Node (Multiplication_Node & node)
{	
	//If left and right children exist
	if(node.getLeft() != nullptr && node.getRight() != nullptr)
	{
		try{
				//Visit left, retrieve result
				node.getLeft()->accept(*this);
			
			// COMMENT Why not just access result_ directly since it belongs
			// to this class, and you are setting it below.
			// RESPONSE result_ is now accessed directly.

				int res1 = this->result_;
					
				//Visit right, retrieve result
				node.getRight()->accept(*this);
			
			// COMMENT Why not just access result_ directly since it belongs
			// to this class, and you are setting it below.
			// RESPONSE result_ is now accessed directly.
			
				int res2 = this->result_;
			
			result_ = res1 * res2;
		}
		catch(std::exception & e)
		{
			throw e;
		}
		
	}
	else
		throw missingOperands();
}

///Visit Division Node
void Eval_Expr_Tree::Visit_Division_Node (Division_Node & node)
{	
	//If left and right children exist
	if(node.getLeft() != nullptr && node.getRight() != nullptr)
	{
		try{
				//Visit left, retrieve result
				node.getLeft()->accept(*this);

			// COMMENT Why not just access result_ directly since it belongs
			// to this class, and you are setting it below.
			// RESPONSE result_ is now accessed directly.

				int res1 = this->result_;
				
				//Visit right, retrieve result
				node.getRight()->accept(*this);
			
			// COMMENT Why not just access result_ directly since it belongs
			// to this class, and you are setting it below.
			// RESPONSE result_ is now accessed directly.
			
				int res2 = this->result_;
			
			//If bottom number of division is NOT zero,
			//Divide the sub-results
			if(res2 != 0)
				result_ = res1 / res2;
			else
				throw divByZero();
		
		}
		catch(std::exception & e)
		{
			throw e;
		}
		
		
	}
	else
		throw missingOperands();
}

///Visit Modulus Node
void Eval_Expr_Tree::Visit_Modulus_Node (Modulus_Node & node)
{	
	//If left and right children exist
	if(node.getLeft() != nullptr && node.getRight() != nullptr)
	{
		try{
			
				//Visit left, retrieve result
				node.getLeft()->accept(*this);
			
			// COMMENT Why not just access result_ directly since it belongs
			// to this class, and you are setting it below.
			// RESPONSE result_ is now accessed directly.

				int res1 = this->result_;
				
				//Visit right, retrieve result
				node.getRight()->accept(*this);
			
			// COMMENT Why not just access result_ directly since it belongs
			// to this class, and you are setting it below.
			// RESPONSE result_ is now accessed directly.
				
				int res2 = this->result_;
		
			//If bottom number of modulus is NOT zero,
			//Perform the modulus operation
			if(res2 != 0)
				result_ = res1 % res2;
			else
				throw divByZero();
		
		}
		catch(std::exception & e)
		{
			throw e;
		}
		
		
	}
	else
		throw missingOperands();
}

///Visit Number Node
void Eval_Expr_Tree::Visit_Number_Node (Number_Node & node)
{
	//Retrieve value from the number node
	result_ = node.getValue();
}

//Return result
int Eval_Expr_Tree::result (void)
{
	return result_;
}
