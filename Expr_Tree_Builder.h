// Daniel Kobold
// CSCI363 PA4
// Expr_Tree_Builder.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_EXPR_TREE_BUILDER_H_
#define _CS363_EXPR_TREE_BUILDER_H_

#include "Expr_Builder.h"
#include "Expr_Tree.h"
#include "Expr_Node.h"
#include "Binary_Expr_Node.h"
#include "Number_Node.h"

class Expr_Tree_Builder: public Expr_Builder
{
public:
	///Default Constructor
	Expr_Tree_Builder (void);
	
	///Destructor
	~Expr_Tree_Builder (void);
	
	///Start Expression
	void start_expression (void);
	
	///Build Operators / Numbers
	void build_number (int n);
	void build_addition_operator (void);
	void build_subtraction_operator (void);
	void build_multiplication_operator (void);
	void build_division_operator (void);
	void build_modulus_operator (void);
	void build_open_parenthesis (void);
	void build_close_parenthesis (void);
	
	///Search for a Place to Insert Node
	bool search(Expr_Node * focus, Expr_Node * node);
	
	///Insert Node
	bool insert_node (Expr_Node * node);

	///Get Tree
	Expr_Tree * get_tree (void);	
	
	///Set level of this builder/tree
	void setLevel (int lv);
	
	///Get level of this builder/tree
	int getLevel (void);
	
	//Insert Node as far right as possible
	bool insert_node_on_right (Expr_Node * node);
	
	//Sets details_ to true -> prints details of tree building
	void setDetails (void);
	
	///Set Sub-Builder (allows deletion later)
	void setSubBuilder(Expr_Tree_Builder * sub);
	
private:
	//Current state of expression tree
	Expr_Tree * tree_;
	
	//Sub-builder
	Expr_Tree_Builder * sub_;
	
	//What level this tree is on (example: a subtree would be level 2)
	int level_;
	
	//When true, this will print all details of tree building
	bool details_;
};

#include "Expr_Tree_Builder.cpp"

#endif // !defined _CS363_EXPR_TREE_BUILDER_H_