#pragma once
#include "Book.h"
ref class HandwrittenBook :
	public Book
{
public:
	HandwrittenBook();
	String^ ToString() override;
};

