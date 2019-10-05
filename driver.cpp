#include "Stack.h"
#include "Tree_Calculator.h"
#include "Expr_Node.h"
//#include "Custom_Exception.cpp"
#include "Binary_Expr_Node.h"
#include "Addition_Node.h"
#include "Subtraction_Node.h"
#include "Multiplication_Node.h"
#include "Division_Node.h"
#include "Modulus_Node.h"
#include "Number_Node.h"
#include "Unary_Expr_Node.h"
#include "Expr_Builder.h"
#include "Expr_Tree.h"
#include "Expr_Tree_Builder.h"
#include "Expr_Node_Visitor.h"
#include <iostream>
#include <string>
#include <sstream>

int main (int argc, char * argv[])
{	
	//Calculator wrapper-facade
	Tree_Calculator calc;
	
	for(int it = 0; it < argc; ++it)
	{
		std::string arg = argv[it];

		if(arg == "-details")
			calc.includeDetails();
	}
	
	
	//Call calculate to run calculation process
	calc.calculate();								
	
	return 0;
}