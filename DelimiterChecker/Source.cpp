//Jay Rosen
//COP2535.0M1
//This program checks a file for proper delimiter usage with a STL stack
#include "DelimiterChecker.h"
using namespace std;

// Program that uses the DelimiterChecker class
/**************************************************************
*               DelimiterChecker::display                      *
*		Display introduction to program and call rest of	   *
*       class functions: readFile and validate			       *
**************************************************************/
void DelimiterChecker::display()
{
	cout << "\a";
	cout << "\n\n\n\t+------------------------------------------------------------+";
	cout << "\n\t|   This program checks a file for proper delimiter usage.   |";
	cout << "\n\t|   Delimiters to search for are ( ), { }, and [ ] .         |";
	cout << "\n\t|   Make sure 'string.txt' is located in current directory.  |";
	cout << "\n\t+------------------------------------------------------------+";
	cout << "\n\t|              Press ENTER to continue . . .                 |";
	cout << "\n\t+------------------------------------------------------------+\n\t";
	cin.get();
	system("cls");

	readFile();

	validate();

}

/****************************************************************
*               DelimiterChecker::readFile                          *
*	Read string.txt file and check each character for a delimiter.  *
*   When opening delimiter is found, it is added to top of stack.   *
*   When closing delimiter is found, the stack removes top pair.    *
**************************************************************/
void DelimiterChecker::readFile()
{
	delimiter = ' ';
	count = 0;
	cout << "\n\n\n\t\t\t Reading file  ";
	int dot = 1;

	while (dot < 6)
	{	//Short animation sequence for loading a file by adding a period
		for (int i = 0; i <= 99999999; i++);
		cout << ". ";
		dot++;
	}

	//open and check if the string.txt file is accessible to program
	ifstream txt;
	txt.open("string.txt");
	if (!txt)
		cout << "Error opening data file\n";

	//read the file into a stack if it finds a delimitter
	else
	{
		system("cls");
		cout << "\a";
		cout << "\n\n\n\t+------------------------------------------------------------+";
		cout << "\n\t|                 Matching Delimiters Found                  |";
		cout << "\n\t+------------------------------------------------------------+";

		while (txt.get(catchChar)) //read each character
		{
			//If character is an opening delimiter
			if (catchChar == '(' || catchChar == '{' || catchChar == '[')
			{
				//push the delimiter to the top of the stack 
				charStack.push(catchChar);
				delimiter = charStack.top();
			}
			//If character is a closing delimiter
			if (catchChar == ')' || catchChar == '}' || catchChar == ']')
			{
				//Nested If to Determine if it matches the current delimiter at the top of the stack
				//If it matches, remove the delimiter at top of the stack, display the matching pair, and increase count
				if (delimiter == '(')
				{
					count++;
					cout << "\n\t|                                                            |\n\t\t";
					cout << count << ". " << charStack.top() << catchChar;
					charStack.pop();
				}

				if (delimiter == '{')
				{
					count++;
					cout << "\n\t|                                                            |\n\t\t";
					cout << count << ". " << charStack.top() << catchChar;
					charStack.pop();
				}

				if (delimiter == '[')
				{
					count++;
					cout << "\n\t|                                                            |\n\t\t";
					cout << count << ". " << charStack.top() << catchChar;
					charStack.pop();
				}
			}
		}
		//close text file
		txt.close();

		cout << "\n\t|                                                            |\n\t\t";
	}
}

/**************************************************************
*              DelimiterChecker::validate                          *
* Display error messages for 2 possible exceptions in string.txt.  *
* (1) no delimiters are found, display none.                       *
* (2) stack still contains delimters after reading end of file,    *
*  which means improper delimiters were used.                      *
**************************************************************/
void DelimiterChecker::validate()
{
	//Let user know that the string has no delimiters
	if (count < 1)
	{
		cout << "0. None";
	}

	cout << "\n\t+------------------------------------------------------------+\n\n\t\t\t";

	//Since the stack should be empty after finding a matching delimiter by the end of the file, if the stack is NOT empty, there must have been improper syntax in the string
	if (!charStack.empty())
	{
		cout << "\a";
		cout << "\n\n\t+------------------------------------------------------------+";
		cout << "\n\t| SYNTAX ERROR: Improper delimiter usage found  " << charStack.size() << " occurances |";
		cout << "\n\t|         Unable to find closing delimiter for               |";
		cout << "\n\t+------------------------------------------------------------+";

		//Use a loop to both display and remove the remainder of elements in the stack until the stack is empty
		for (int i = 0; i = charStack.size(); i++)
		{
			cout << "\n\t|                                                            |\n\t\t";
			cout << charStack.top();
			charStack.pop();
		}
		cout << "\n\t+------------------------------------------------------------+\n\n\t\t\t";
	}


}

/**************************************************************
*                                                               *
* 							Main		   			            *
*                                                               *
*                                                               *
**************************************************************/

int main()
{
	//create a stack object of the DelimiterChecker class
	DelimiterChecker stack;

	//Display the program
	stack.display();


	system("pause");
	return 0;
}