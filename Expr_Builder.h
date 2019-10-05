// Daniel Kobold
// CSCI363 PA4
// Expr_Builder.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_EXPR_BUILDER_H_
#define _CS363_EXPR_BUILDER_H_

#include "Addition_Node.h"
#include "Subtraction_Node.h"
#include "Multiplication_Node.h"
#include "Division_Node.h"
#include "Modulus_Node.h"
#include "Number_Node.h"
#include "Expr_Node.h"
#include "Stack.h"

class Expr_Builder
{
public:
	///Constructor - does nothing
	Expr_Builder(void);
	
	///Pure Virtual Destructor
	virtual ~Expr_Builder(void) = 0;

	///Start Expression
	virtual void start_expression (void) = 0;
	
	///Build Operator or Number
	virtual void build_number (int n)=0;
	virtual void build_addition_operator (void)=0;
	virtual void build_subtraction_operator (void)=0;
	virtual void build_multiplication_operator (void)=0;
	virtual void build_division_operator (void)=0;
	virtual void build_modulus_operator (void)=0;
	virtual void build_open_parenthesis (void)=0;
	virtual void build_close_parenthesis (void)=0;
};

#include "Expr_Builder.cpp"

#endif // !defined _CS363_EXPR_BUILDER_H_