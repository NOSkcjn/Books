#pragma once
#include "Book.h"

[Serializable]
ref class HandwrittenBook :
	public Book
{
public:
	property bool Handwritten
	{
		bool get();
		void set(bool value);
	}

	HandwrittenBook();
	HandwrittenBook(int id);
	String^ ToString() override;

private:
	bool _handwritten;
};

