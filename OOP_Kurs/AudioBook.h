#pragma once
#include "Book.h"

[Serializable]
ref class AudioBook :
	public Book
{
public:
	property int Length
	{
		int get();
		void set(int value);
	}

	AudioBook();
	AudioBook(int id);
	String^ ToString() override;

private:
	int _length;
};

