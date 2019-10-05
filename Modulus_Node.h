// Daniel Kobold
// CSCI363 PA4
// Modulus_Node.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_MODULUS_NODE_H_
#define _CS363_MODULUS_NODE_H_

#include "Binary_Expr_Node.h"

class Modulus_Node: public Binary_Expr_Node
{
public:
	///Constructor - calls Binary_Expr_Node constructor
	Modulus_Node (void);
	
	///Evaluate - completes modulus
	int eval (void);
	
	///Get Precedence - returns precedence level
	int getPrecedence(void);
	
	///Print this Element
	virtual std::string print (void);
	
	///Accept Visitor
	virtual void accept (Expr_Node_Visitor & v);

};

#include "Modulus_Node.cpp"

#endif // !defined _CS363_Modulus_NODE_H_