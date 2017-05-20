#pragma once
#include "Book.h"
ref class AudioBook :
	public Book
{
public:
	AudioBook();
	String^ ToString() override;
};

