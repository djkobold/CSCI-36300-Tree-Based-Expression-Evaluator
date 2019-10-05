// Daniel Kobold
// CSCI363 PA4
// Tree_Calculator.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_TREE_CALCULATOR_H_
#define _CS363_TREE_CALCULATOR_H_

#include "Stack.h"
#include "Array.h"
#include "Expr_Node.h"
#include "Expr_Builder.h"
#include "Expr_Tree_Builder.h"
#include "Expr_Tree.h"
#include "Expr_Node_Visitor.h"
#include "Eval_Expr_Tree.h"
#include "Print_Inorder_Expression.h"
#include "Print_Preorder_Expression.h"
#include "Print_Postorder_Expression.h"
#include <string>
#include <sstream>
#include <iostream>

class Tree_Calculator
{
public:
	///Constructor
	Tree_Calculator(void);
	
	///Destructor
	~Tree_Calculator(void);

	///Parse Expression
	Expr_Tree_Builder * parse_expr (const std::string & infix, int level);
	
	///Calculate
	void calculate (void);
	
	///Find Size
	size_t findSize(const std::string & infix);
	
	///Find Total Size (includes parentheses)
	size_t findTotalSize(const std::string & infix);
	
	///Exponent
	int exponent (int num, int exp);

	//Set details_ to true -> include full details during program execution
	void includeDetails (void);
private:
	Expr_Tree_Builder * builder_;
	
	//If true, this will print all details of setting up and traversing the tree
	bool details_;
};

#include "Tree_Calculator.cpp"

#endif // !defined _CS363_TREE_CALCULATOR_H_