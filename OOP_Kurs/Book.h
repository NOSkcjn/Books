using namespace System;

#pragma once



enum Genres
{
	Fantastic,
	Thriller,
	Novel
};
public ref class Book
{
public:
	Book();
	
	void input(int _pages, String^ _author, String^ _name, String^ genre);

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

private:
	static int currentID = 1;

	int _ID;
	int _pages;
	String^ _author;
	String^ _name;
	Genres _genre;

	String^ FANTASTIC = "Фантастика";
	String^ NOVEL = "Роман";
	String^ THRILLER = "Триллер";
};

