#include <iostream>
#include <stdexcept>
#include <iomanip>  
#include <windows.h>
#include <algorithm>
#include "Social_media.h"
using namespace std;
Social_media S;
void underline()
{
	for (int i = 0; i < 100; ++i) {
		cout << '-';
	}
	cout << "\n";
}

/// OPTION FUNCTION
void options()
{
	cout
		<< "|\t\t[1]-User Insertion ." << setw(66) << " | \n"
		<< "|\t\t[2]-User Deletion ." << setw(67) << " | \n"
		<< "|\t\t[3]-User Search ." << setw(69) << " | \n"
		<< "|\t\t[4]-Show All Users ." << setw(66) << " | \n"
		<< "|\t\t[0]-Exit ." << setw(75) << " |\n";
	underline();
}
int welcome()
{
	underline();
	cout << setw(35) << "|\t\t\t  ## Welcome To Social media (*^_^*) ##" << setw(37) << " | \n";
	underline();
	cout << "| \tMain Menu :" << setw(83) << " | \n";
	options();
	cout << "Enter Your Choice : ";
	int n;
	cin >> n;
	return n;
}

/// ADDING FUNCTION
void add(int pos)
{
	S.insert();
	cout << "\n\t\t## Added Sucessfully ##\n";
	underline();
}

/// REMOVE FUNCTION
void remove(int pos)
{
	S.delete_();
	cout << "\n\t\t## Removed Sucessfully ##\n";
	underline();
}


/// MAIN FUNCTION
int main()
{
	int pos = -1;
	while (pos)
	{
		int h;
		system("cls");
		switch (welcome())
		{
		case 1:
			S.insert();
			break;
		case 2:
			underline();
			S.delete_();
			break;
		case 3:
			underline();
			S.search();
			break;
		case 4:
			S.display();
			break;
		default:
			throw out_of_range("INVALID SYNTAX\n");
			break;
		}
		cout << "Continue ? [(1)-YES / (0)-NO] : ";
		cin >> pos;
	}
	underline();
	cout << "|\t\t\t\t## Thank You (*^_^*) ##" << setw(46) << "|\n";
	underline();
	return 0;
}