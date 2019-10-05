// Daniel Kobold
// CSCI363 PA4
// Division_Node.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_DIVISION_NODE_H_
#define _CS363_DIVISION_NODE_H_

#include "Binary_Expr_Node.h"

class Division_Node: public Binary_Expr_Node
{
public:
	///Constructor - calls Binary_Expr_Node constructor
	Division_Node (void);
	
	///Evaluate - completes division
	int eval (void);
	
	///Get Precedence - returns precedence level
	int getPrecedence(void);
	
	std::string print (void);
	
	virtual void accept (Expr_Node_Visitor & v);

};

#include "Division_Node.cpp"

#endif // !defined _CS363_DIVISION_NODE_H_