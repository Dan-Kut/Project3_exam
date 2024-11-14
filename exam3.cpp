#include <iostream>
#include <windows.h>
#include"function.h"
using namespace std;


int main()
{
	HANDLE handler = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handler, FOREGROUND_GREEN);

	int size;
	cout << "Enter size of list with books: ";
	cin >> size;
	Book* listOfBook = new Book[size];
	fillArr(arguments);

	int action = 1;
	while (action != 0)
	{
		cout << "Operations: 0 - stop;\n 1 - show arr;\n 2 - sort elements by year;\n 3 - sort elements by pages;\n";
		cout << " 4 - find book by autor;\n 5 - edit book by id;\n 6 - add book;\n 7 - delet book" << endl;
		cout << "Enter an operation: ";
		cin >> action;
		cout << endl;

		if (action == 1)
		{
			showArr(arguments);
		}
		else if (action == 2)
		{
			sortByYear(arguments);
			cout << endl;
		}
		else if (action == 3)
		{
			sortByPages(arguments);
			cout << endl;
		}
		else if (action == 4)
		{
			findBookByAutor(arguments);
		}
		else if (action == 5)
		{
			editBookById(arguments);
		}
		else if (action == 6)
		{
			addBook(arguments);
		}
		else if (action == 7)
		{
			deletBook(arguments);
		}
		else
		{
			cout << "There is no that operation" << endl;
		}

	}

	clearMemory(arguments);
	cout << "Thanks for using program :)";


}