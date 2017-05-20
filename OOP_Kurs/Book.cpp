#include "Book.h"
//using namespace System;




Book::Book()
{
	this->_ID = currentID++;
}

//ID
int Book::ID::get()
{
	return _ID;
}

void Book::ID::set(int value)
{
	_ID = value;
}

//Название книги
String^ Book::Name::get()
{
	return _name;
}

void Book::Name::set(String^ value)
{
	_name = value;
}

//Автор
String^ Book::Author::get()
{
	return _author;
}

void Book::Author::set(String^ value)
{
	_author = value;
}

//Количество страниц
int Book::Pages::get()
{
	return _pages;
}

void Book::Pages::set(int value)
{
	_pages = value;
}

//Жанр
String^ Book::Genre::get()
{
	switch (_genre)
	{
		case Genres::Fantastic:
			return FANTASTIC;
		case Genres::Novel:
			return NOVEL;
		case Genres::Thriller:
			return THRILLER;
	}
}

void Book::Genre::set(String^ value)
{
	if (value == FANTASTIC)
		_genre = Genres::Fantastic;
	else if(value == NOVEL)
		_genre = Genres::Novel;
	else if (value == THRILLER)
		_genre = Genres::Thriller;
}

void Book::input(int _pages, String^ _author, String^ _name, String^ genre)
{
	this->_pages = _pages;
	this->_author = _author;
	this->_name = _name;
	this->Genre = genre;
}

/*property String^ Book::Author
{
	String^ set(String^ value)
	{
		author = value
	}
	void get
	{
		return author;
	}
}*/

/*String ^ Book::ToString() {
	return name;
}*/