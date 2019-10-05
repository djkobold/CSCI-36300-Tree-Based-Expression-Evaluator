// Daniel Kobold
// CSCI363 PA4
// Binary_Expr_Node.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_BINARY_EXPR_NODE_H_
#define _CS363_BINARY_EXPR_NODE_H_

#include "Expr_Node.h"

class Binary_Expr_Node: public Expr_Node
{
public:
	///Default Constructor
	Binary_Expr_Node (void);

	///Destructor
	~Binary_Expr_Node (void);
	
	///Evaluate
	virtual int eval (void) = 0;
		
	///Additional Operations
	virtual void print_preorder (std::ostream & out);
	virtual void print_inorder (std::ostream & out);
	
	///Get Functions - get left or right node
	Expr_Node * getLeft (void);
	Expr_Node * getRight (void);
	
	///Set Functions - set left or right node
	void setLeft (Expr_Node * left);
	void setRight (Expr_Node * right);
	
	///Print this Element
	virtual std::string print (void) = 0;
	
	///Accept Visitor
	virtual void accept (Expr_Node_Visitor & v)=0;
	
protected:
	//Children nodes
	Expr_Node * left_;
	Expr_Node * right_;
};

#include "Binary_Expr_Node.cpp"

#endif // !defined _CS363_BINARY_EXPR_NODE_H_