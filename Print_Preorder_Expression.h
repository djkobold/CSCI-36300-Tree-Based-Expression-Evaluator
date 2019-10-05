// Daniel Kobold
// CSCI363 PA4
// Print_Preorder_Expression.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_PRINT_PRE_EXPR_H_
#define _CS363_PRINT_PRE_EXPR_H_

#include "Expr_Node_Visitor.h"
#include <string>
#include <exception>

class Print_Preorder_Expression : public Expr_Node_Visitor
{
public:
	///Default Constructor
	Print_Preorder_Expression (void);
	
	///Destructor
	virtual ~Print_Preorder_Expression (void);
	
	//Methods for visiting concrete nodes
	virtual void Visit_Addition_Node (Addition_Node & node);
	virtual void Visit_Subtraction_Node (Subtraction_Node & node);
	virtual void Visit_Multiplication_Node (Multiplication_Node & node);
	virtual void Visit_Division_Node (Division_Node & node);
	virtual void Visit_Modulus_Node (Modulus_Node & node);
	virtual void Visit_Number_Node (Number_Node & node);	
	
	std::string result (void);
	
private:
	std::string result_;
};

#include "Print_Preorder_Expression.cpp"

#endif // !defined _CS363_PRINT_PRE_EXPR_H_
