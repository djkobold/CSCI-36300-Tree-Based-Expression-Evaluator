// Daniel Kobold
// CSCI363 PA4
// Custom_Exception.cpp

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include <iostream>
#include <exception>

struct divByZero : public std::exception
{
	const char * what () const throw ()
	{
		return "Dividing by zero can cause undefinded behavior.";
	}
};

struct missingOperands : public std::exception
{
	const char * what () const throw ()
	{
		return "Evaluating the expression using a visitor has failed.";
	}
};

struct invalidNums : public std::exception
{
	const char * what () const throw ()
	{
		return "Out of range number was entered.";
	}
};

struct invalidArgs : public std::exception
{
	const char * what () const throw ()
	{
		return "Invalid argument was entered.";
	}
};
