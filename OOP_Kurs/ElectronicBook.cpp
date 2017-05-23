#include "ElectronicBook.h"
#include "Constants.h"


ElectronicBook::ElectronicBook()
{
	
}

ElectronicBook::ElectronicBook(int id): Book(id)
{
}

//размер файла в килобайтах
int ElectronicBook::Size::get()
{
	return _size;
}

void ElectronicBook::Size::set(int value)
{
	_size = value;
}

String^ ElectronicBook::ToString()
{
	return gcnew String(ELECTRONICBOOK);
}

