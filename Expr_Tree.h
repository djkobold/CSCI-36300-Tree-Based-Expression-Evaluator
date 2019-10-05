// Daniel Kobold
// CSCI363 PA4
// Expr_Tree.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_EXPR_TREE_H_
#define _CS363_EXPR_TREE_H_

#include "Expr_Node.h"
#include <iostream>

class Expr_Tree
{
public:
	///Default Constructor
	Expr_Tree (void);
	
	///Initialization Constructor - includes a head node
	Expr_Tree (Expr_Node * head);
	
	///Destructor
	~Expr_Tree (void);

	///Get Head Node
	Expr_Node * get_head_node (void);
	
	///Set Head Node
	void set_head_node (Expr_Node * newHead);
	
private:
	//Head of the tree
	Expr_Node * head_;
};

#include "Expr_Tree.cpp"

#endif // !defined _CS363_EXPR_TREE_H_