#pragma once
#include <iostream>
using namespace System;
using namespace System::Runtime::Serialization;

enum Genres
{
	Fantastic,
	Thriller,
	Novel
};

[Serializable]
public ref class Book
{
public:
	property int ID
	{
		int get();
		void set(int value);
	}

	property String^ Name
	{
		String^ get();
		void set(String^ value);
	}

	property String^ Author
	{
		String^ get();
		void set(String^ value);
	}

	property int Pages
	{
		int get();
		void set(int value);
	};

	property String^ Genre
	{
		String^ get();
		void set(String^ value);
	}

	Book();
	Book(int id);

	void Input(int _pages, String^ _author, String^ _name, String^ genre);
	void Input(Book^ book);
	static void AddID(int value);

private:
	static int currentID = 1;

	int _ID;
	int _pages;
	String^ _author;
	String^ _name;
	Genres _genre;
};

