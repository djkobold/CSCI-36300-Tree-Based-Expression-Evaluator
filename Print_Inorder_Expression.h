// Daniel Kobold
// CSCI363 PA4
// Print_Inorder_Expression.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_PRINT_IN_EXPR_H_
#define _CS363_PRINT_IN_EXPR_H_

#include "Expr_Node_Visitor.h"
#include <string>
#include <exception>
#include <iostream>

class Print_Inorder_Expression : public Expr_Node_Visitor
{
public:
	///Default Constructor
	Print_Inorder_Expression (void);
	
	///Destructor
	virtual ~Print_Inorder_Expression (void);
	
	//Methods for visiting concrete nodes
	virtual void Visit_Addition_Node (Addition_Node & node);
	virtual void Visit_Subtraction_Node (Subtraction_Node & node);
	virtual void Visit_Multiplication_Node (Multiplication_Node & node);
	virtual void Visit_Division_Node (Division_Node & node);
	virtual void Visit_Modulus_Node (Modulus_Node & node);
	virtual void Visit_Number_Node (Number_Node & node);
	
	///Return resulting string / substring
	std::string result (void);

private:
	std::string result_;
};

#include "Print_Inorder_Expression.cpp"

#endif // !defined _CS363_PRINT_IN_EXPR_H_
