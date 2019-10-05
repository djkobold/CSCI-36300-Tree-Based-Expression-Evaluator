// Daniel Kobold
// CSCI363 PA4
// Unary_Expr_Node.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_UNARY_EXPR_NODE_H_
#define _CS363_UNARY_EXPR_NODE_H_

#include "Expr_Node.h"

class Unary_Expr_Node: public Expr_Node
{
public:
	///Default Constructor
	Unary_Expr_Node (void);
	
	///Destructor
	~Unary_Expr_Node (void);
	
	///Evaluate
	int eval (void);
	
	///Additional Operations
	virtual void print_preorder (std::ostream & out);
	virtual void print_inorder (std::ostream & out);
	
	///Get Precedence
	int getPrecedence (void);
	
	///Print this element
	std::string print (void);
	
	virtual void accept (Expr_Node_Visitor & v);

protected:
	//Singular child element
	Expr_Node * child_;

};

#include "Unary_Expr_Node.cpp"

#endif // !defined _CS363_UNARY_EXPR_NODE_H_