// Daniel Kobold
// CSCI363 PA4
// Multiplication_Node.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_MULTIPLICATION_NODE_H_
#define _CS363_MULTIPLICATION_NODE_H_

#include "Binary_Expr_Node.h"

class Multiplication_Node: public Binary_Expr_Node
{
public:
	///Constructor - calls Binary_Expr_Node constructor
	Multiplication_Node (void);
	
	///Evaluate - completes multiplication
	int eval(void);
	
	///Get Precedence - returns precedence level
	int getPrecedence(void);
	
	///Print this Element
	std::string print (void);

	virtual void accept (Expr_Node_Visitor & v);
};

#include "Multiplication_Node.cpp"

#endif // !defined _CS363_MULTIPLICATION_NODE_H_