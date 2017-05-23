#include "AudioBook.h"
#include "Constants.h"


AudioBook::AudioBook()
{
}

AudioBook::AudioBook(int id): Book(id)
{
}

int AudioBook::Length::get()
{
	return _length;
}

void AudioBook::Length::set(int value)
{
	_length = value;
}


String^ AudioBook::ToString()
{
	return gcnew String(AUDIOBOOK);
}