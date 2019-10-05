// Daniel Kobold
// CSCI363 PA4
// Stack_Expr_Builder.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_STACK_EXPR_BUILDER_H_
#define _CS363_STACK_EXPR_BUILDER_H_

class Stack_Expr_Builder: public Expr_Builder
{
public:
	Expr_Tree_Builder (Stack<int> stack);
	virtual ~Expr_Tree_Builder (void);
	
	virtual void start_expression (void);
	
	virtual void build_number (int n);
	virtual void build_add_operator (void);
	virtual void build_subtract_operator (void);
	/*...*/
	
	Expr_Tree * get_expression (void);
	
private:

};

#include "Stack_Expr_Builder.cpp"

#endif // !defined _CS363_STACK_EXPR_BUILDER_H_