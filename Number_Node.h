// Daniel Kobold
// CSCI363 PA4
// Number_Node.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_NUMBER_NODE_H_
#define _CS363_NUMBER_NODE_H_

#include "Expr_Node.h"

class Number_Node: public Expr_Node
{
public:
	///Constructor - calls Expr_Node constructor
	Number_Node (int n);
	
	///Execute - call evaluate
	bool execute (void);
	
	///Evaluate - push number on stack
	int eval (void);
	
	///Additional Operations
	void print_preorder (void);
	void print_inorder (void);
	
	///Additional Operations
	void print_preorder (std::ostream & out);
	void print_inorder (std::ostream & out);
	
	///Get precedence level
	int getPrecedence (void);
	
	///Set Value
	void setValue (int val);
	
	///Get Value
	int getValue(void);
	
	///Print this Element
	std::string print (void);
	
	///Accept Visitor
	virtual void accept (Expr_Node_Visitor & v);
	
private:
	int value_;
};

#include "Number_Node.cpp"

#endif // !defined _CS363_NUMBER_NODE_H_