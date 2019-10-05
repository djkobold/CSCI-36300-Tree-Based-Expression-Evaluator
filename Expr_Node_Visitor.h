// Daniel Kobold
// CSCI363 PA4
// Expr_Node_Visitor.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_EXPR_NODE_VISITOR_H_
#define _CS363_EXPR_NODE_VISITOR_H_

class Expr_Node;
class Binary_Expr_Node;
class Unary_Expr_Node;
class Addition_Node;
class Subtraction_Node;
class Multiplication_Node;
class Division_Node;
class Modulus_Node;
class Number_Node;

#include <iostream>

class Expr_Node_Visitor
{
public:
	///Constructor
	Expr_Node_Visitor(void);
	
	///Virtual Destructor
	virtual ~Expr_Node_Visitor (void);
	
	///Visit - methods for visitiing concrete nodes
	virtual void Visit_Addition_Node (Addition_Node & node) = 0;
	virtual void Visit_Subtraction_Node (Subtraction_Node & node) = 0;
	virtual void Visit_Multiplication_Node (Multiplication_Node & node) = 0;
	virtual void Visit_Division_Node (Division_Node & node) = 0;
	virtual void Visit_Modulus_Node (Modulus_Node & node) = 0;
	virtual void Visit_Number_Node (Number_Node & node) = 0;
};

#include "Expr_Node_Visitor.cpp"

#endif // !defined _CS363_EXPR_NODE_VISITOR_H_
