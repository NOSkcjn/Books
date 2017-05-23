#include "Book.h"
#include "Constants.h"

Book::Book()
{
	this->_ID = currentID++;
}

Book::Book(int id)
{
	this->_ID = id;
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
			return gcnew String(FANTASTIC);
		case Genres::Novel:
			return gcnew String(NOVEL);
		case Genres::Thriller:
			return gcnew String(THRILLER);
		default:
			return gcnew String(NOVEL);
	}
}

void Book::Genre::set(String^ value)
{
	if (value == gcnew String(FANTASTIC))
		_genre = Genres::Fantastic;
	else if (value == gcnew String(THRILLER))
		_genre = Genres::Thriller;
	else
		_genre = Genres::Novel;
}

void Book::Input(int _pages, String^ _author, String^ _name, String^ genre)
{
	this->_pages = _pages;
	this->_author = _author;
	this->_name = _name;
	this->Genre = genre;
}

void Book::Input(Book^ inputBook)
{
	this->_pages = inputBook->Pages;
	this->_author = inputBook->Author;
	this->_name = inputBook->Name;
	this->Genre = inputBook->Genre;
}

void Book::AddID(int value)
{
	currentID += value;
}