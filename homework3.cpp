/*
Jason Bell     CSCE1030.001     Homework3   3-6-17
*/

#include<iostream>
#include<string>
using namespace std;

/* 
Function : Test
Parameters : an integer representing an odd number between 1 and 19
Retrun : an int that specifies  wether or not the input was valid.
Description : This function checks the input to make sure it is an  odd integer between 1 and 19, and informs the user if not and prompts for a replacement.
*/
int test (int x)
{
	if ((x%2) == 0) // checks for evens
	{
		return 0; // 0 equals false
	}
	else if ((x < 1) || (x > 19)) // checks if too big or small
	{
		return 0; // 0 if flase
	}
	else
	{
		return 1; // 1 for true if it passes the prior checks
	}
}

/*
Function : Diamond
Parameters : a character for the pattern, and an integer for the number of rows.
Retrun : none, but it outputs a diamond.
Description : A function that builds a diamond to the specifcations provided by the user.
*/

void diamond (char pattern, int x)
{
	int  y, z = 0, space=(x/2), count;
	for (count=1; count <= x; count+=2) // runs for the build up part of the diamond
	{
		for (y = space; y > 0; y--) // outputs the spaces for each line
		{
			cout << " ";
		}
		for (y = 0; y <= z; y++) // outputs the characters for each line
		{
			cout << pattern;
		}
		z+=2; // adjust the z value to change the size of the line in the diamond
		space--; // adjust the space value to change the size of the spaces in the diamond
		cout << endl; // starts the next line of the diamond
	}

	z-=2; // adjustment so as not to repeat the line from before

	for (count = x; count > 0; count-=2) // runs for the build down of the diamond
	{
		z-=2; // same as above
		space++; // same as aboce
		for (y = 0; y <= space; y++) // outputs the spaces for the build down
		{
			cout << " ";
		}
		for (y = z; y >= 0; --y) // outputs the patter for the build down
		{
			cout << pattern;
		}
		cout << endl; // starts the next line of the diamond
	}
}


int main ()
{
	cout << "Jason Bell jtb0192 CSCE1030.001 jasonbell2@my.unt.edu\n" << endl;

	int x, y, sum=0, valid;
	char pattern;

	do // prompts and accepts an odd integer 1-19 and corrects if wrong
	{
		cout << "Input an odd integer between 1 - 19: ";
		cin >> x;

		valid = test(x); // runs the funciton test

		if (valid == 0)
		{
			cout << "\nError, invalid integer. ";
		}
	}
	while (valid == 0);

	y=x;
	
	while (y >= 0) // adds up the expounded value of x
	{
		sum += y--;
	}
	cout << "\nThe sum of integers from 1 to " << x << " is " << sum << "." << endl; 

	cout << "Please enter a printable character to draw the diamond: ";
	cin >> pattern;

	diamond(pattern, x); // runs the function diamond

	return 0;
}

