#pragma once
#include "Book.h"
ref class ElectronicBook :
	public Book
{
public:
	ElectronicBook();
	String^ ToString() override;
};

