#include "HandwrittenBook.h"
#include "Constants.h"

#pragma once

HandwrittenBook::HandwrittenBook()
{

}

HandwrittenBook::HandwrittenBook(int id):Book(id)
{
}

//печатная или рукописная
bool HandwrittenBook::Handwritten::get()
{
	return _handwritten;
}

void HandwrittenBook::Handwritten::set(bool value)
{
	_handwritten = value;
}

String^ HandwrittenBook:: ToString()
{
	return gcnew String(HANDWRITTENBOOK);
}
