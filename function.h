#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

#define arguments listOfBook, size


struct Book
{
	char* name;
	char* autor;
	int* publish_year;
	int* pages_num;
	int* id;
};



Book creatBook()
{
	cout << "Enter name: ";
	char* name = new char;
	cin >> name;
	cout << "Enter autor: ";
	char* autor = new char;
	cin >> autor;
	cout << "Enter publish_year: ";
	int* publish_year = new int;
	cin >> *(publish_year);
	cout << "Enter pages_num: ";
	int* pages_num = new int;
	cin >> *(pages_num);
	cout << "Enter id: ";
	int* id = new int;
	cin >> *(id);
	Book* bk = new Book{ name, autor, publish_year, pages_num, id };
	return *bk;
}


void showBook(Book* book)
{
	cout << "Name: " << book->name << endl;
	cout << "Autor: " << book->autor << endl;
	cout << "Publish_year: " << *(book->publish_year) << endl;
	cout << "Pages_num: " << *(book->pages_num) << endl;
	cout << "Id: " << *(book->id) << endl;
}



void showArr(Book* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		showBook(&(arr[i]));
		cout << endl;
	}
}


void fillArr(Book* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = creatBook();
		cout << endl;
	}

	showArr(arr, size);
}



void sortByYear(Book* arr, int size) {

	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (arr[j].publish_year > arr[j + 1].publish_year) {
				Book temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	cout << "Elements was sorted by year" << endl;
}




void sortByPages(Book* arr, int size) {

	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (arr[j].pages_num > arr[j + 1].pages_num) {
				Book temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	cout << "Elements was sorted by pages" << endl;
}




void findBookByAutor(Book* arr, int size)
{
	cout << "Which book do you want to find ?" << endl;
	char autor_name;
	cin >> autor_name;
	for (int i = 0; i < size; i++)
	{
		if (*(arr[i].autor) == autor_name)
		{
			showBook(&(arr[i]));
		}
	}
}





void editBook(Book* book)
{
	cout << "Enter name: ";
	cin >> book->name;
	cout << "Enter autor: ";
	cin >> book->autor;
	cout << "Enter publish_year: ";
	cin >> *(book->publish_year);
	cout << "Enter pages_num: ";
	cin >> *(book->pages_num);
	cout << "Enter id: ";
	cin >> *(book->id);
}


void editBookById(Book* arr, int size)
{
	cout << "Which book would you like to edit ?" << endl;
	int id_to_change;
	cout << "Enter id: ";
	cin >> id_to_change;
	for (int i = 0; i < size; i++)
	{
		if (*(arr[i].id) == id_to_change)
		{
			editBook(&(arr[i]));
		}
	}
	cout << "The book was edited" << endl;
}


void addBook(Book*& arr1, int& size)
{
	Book* arr2 = new Book[size + 1];
	for (int i = 0; i < size; i++)
	{
		arr2[i] = arr1[i];
	}
	arr2[size] = creatBook();
	cout << endl;
	delete[] arr1;
	arr1 = arr2;
	size++;
	cout << "The book was added" << endl;
}



void deletBook(Book* arr1, int& size)
{
	Book* arr2 = new Book[size - 1];
	cout << "Which book do you want to delet ?" << endl;
	int id_delete;
	cin >> id_delete;
	for (int i = 0, j = 0; i < size; i++)
	{
		if (*(arr1[i].id) != id_delete)
		{
			arr2[j] = arr1[i];
			j++;
		}
		else if (*(arr1[i].id) == id_delete)
		{
			delete[] arr1[i].name;
			arr1[i].name = nullptr;
			delete[] arr1[i].autor;
			arr1[i].autor = nullptr;
			delete[] arr1[i].publish_year;
			arr1[i].publish_year = nullptr;
			delete[] arr1[i].pages_num;
			arr1[i].pages_num = nullptr;
			delete[] arr1[i].id;
			arr1[i].id = nullptr;
		}
	}
	delete[] arr1;
	arr1 = arr2;
	size--;
	cout << "The book was deleted" << endl;
}



void clearMemory(Book* arr3, int size)
{
	for (int i = 0; i < size; i++)
	{
		delete[] arr3[i].name;
		delete[] arr3[i].autor;
		delete[] arr3[i].publish_year;
		delete[] arr3[i].pages_num;
		delete[] arr3[i].id;
	}
	delete[] arr3;
}

