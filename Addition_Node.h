// Daniel Kobold
// CSCI363 PA4
// Addition_Node.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_ADDITION_NODE_H_
#define _CS363_ADDITION_NODE_H_

#include "Binary_Expr_Node.h"
#include <string>

class Addition_Node: public Binary_Expr_Node
{
public:
	///Constructor - calls Binary_Expr_Node constructor
	Addition_Node (void);
	
	///Evaluate - completes addition
	int eval (void);
	
	///Get Precedence - returns precedence level
	int getPrecedence(void);
	
	///Print this Element
	std::string print(void);
	
	///Accept Visitor
	virtual void accept (Expr_Node_Visitor & v);

};

#include "Addition_Node.cpp"

#endif // !defined _CS363_ADDITION_NODE_H_