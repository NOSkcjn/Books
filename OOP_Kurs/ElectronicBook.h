#pragma once
#include "Book.h"

[Serializable]
ref class ElectronicBook :
	public Book
{
public:
	property int Size
	{
		int get();
		void set(int value);
	}

	ElectronicBook();
	ElectronicBook(int id);
	String^ ToString() override;

private:
	int _size;
};

