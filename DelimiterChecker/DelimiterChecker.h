//Jay Rosen
//This class is used with Source program to check a file for proper delimiter usage with a STL stack
#ifndef DELIMITERCHECKER_H
#define DELIMITERCHECKER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

// DelimiterChecker class declaration
class DelimiterChecker
{
private:
	stack< char, vector<char> > charStack;	//STL stack container for character data-type
	char delimiter;							//element at the top of the stack
	char catchChar;							//character that is read from file
	int count;								//number of matching delimiters found
	ifstream txt;							//input text file
	void readFile();						//function to read the text file and use a stack to check for delimiters
	void validate();						//function to display errors if they occured

public:
	void display();							//function to display program, accessible to Main

}; // End DelimiterChecker class declaration


#endif