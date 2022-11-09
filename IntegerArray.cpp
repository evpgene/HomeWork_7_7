#include "IntegerArray.h"
#include <iostream>
#include <exception>
#include <string>
#include "MyException.h"
using namespace std;

IntegerArray::IntegerArray(const int size) : _size(size)
{
	if (_size < 0)
	{
		throw MyException("Exception: Array size is less then zero. Array not created!");
	}
	_dataPtr = new int[_size] {};
}

IntegerArray::IntegerArray(const IntegerArray* Source)
{
	this->_size = Source->_size;
	if (_size < 0)
	{
		throw MyException("Exception: Array size is less then zero. Array not created!");
	}
	_dataPtr = new int[_size] {};
	for (size_t i = 0; i < _size; i++)
	{
		this->_dataPtr[i] = Source->_dataPtr[i];
	}
}


IntegerArray::~IntegerArray()
{
	deleteArray();
}

IntegerArray& IntegerArray::operator= (const IntegerArray& Source)
{
	if (this != &Source) // protection against copy into self
	{
		this->_size = Source._size;
		if (_size < 0)
		{
			throw MyException("Exception: Array size is less then zero. Array not created!");
		}
		_dataPtr = new int[_size] {};
		for (size_t i = 0; i < _size; i++)
		{
			this->_dataPtr[i] = Source._dataPtr[i];
		}
	}
	return *this;
}


void IntegerArray::deleteArray()
{
	if (_dataPtr) //delete after
		delete[] _dataPtr;
	_dataPtr = nullptr;
	_size = 0;
}


int& IntegerArray::operator [] (int indx) const
{
	if (indx < 0 || indx >= _size)
	{
		throw MyException("Exception: Index outside array!");
	}
	return _dataPtr[indx];
}


void IntegerArray::setNewSize(const int sizeNew)
{
	if (_dataPtr)
		change(0, 0, sizeNew, 0);
	else
	{
		_size = sizeNew;
		if (_size < 0)
		{
			throw MyException("Exception: Array size is less then zero. Array not created!");
		}
		_dataPtr = new int[_size] {};
	}
}

void IntegerArray::setElement(const int indx, const int value)
{
	if (indx < 0 || indx >= _size)
	{
		throw MyException("Exception: Index outside array!");
	}
	_dataPtr[indx] = value;
}

int IntegerArray::getElement(const int indx)
{
	return _dataPtr[indx];
}

int IntegerArray::getSize() const
{
	return _size;
}

void IntegerArray::insertElement(const int indx, const int value)
{
	change(indx, value, 0, 1);
}

void IntegerArray::insertElementBeginning(const int value)
{
	IntegerArray::insertElement(0, value);
}

void IntegerArray::insertElementEnd(const int value)
{
	IntegerArray::insertElement(_size, value);
}

void IntegerArray::removeElement(const int indx)
{
	change(indx, 0, 0, 2);
}

void IntegerArray::removeElementBegining()
{
	removeElement(0);
}

void IntegerArray::removeElementEnd()
{
	removeElement(_size - 1);
}

int IntegerArray::findElement(const int value)
{
	int ret{ -1 };
	if (_dataPtr)
	{
		
		for (size_t i = 0; i < _size; i++)
		{
			if (_dataPtr[i] == value)
			{
				ret = i;
				break;
			}
		}
		if (ret == -1) {throw MyException("No such element in array!");
		}
	}
	return ret;
}

void IntegerArray::print()
{
	if (_dataPtr)
	{
		for (size_t i = 0; i < _size; i++)
		{
			cout << i << " : " << _dataPtr[i] << endl;
		}
	}
}

void IntegerArray::change(const int indx, const int value, int sizeNew, const int operation)
{
	if (sizeNew < 0)
	{
		throw MyException("Exception: Array size is less then zero. Array not created!");
	}
	if (indx < 0 || indx >= _size)
	{
		throw MyException("Exception: Index outside array!");
	}
	int* dataPtrNew{ nullptr }; //new array
	switch (operation)
	{
	case 0: // Resize
		dataPtrNew = new int[sizeNew] {};
		_size <= sizeNew ? partCopy(0, _size - 1, dataPtrNew) : partCopy(0, sizeNew - 1, dataPtrNew);
		break;
	case 1: // Insert element
		sizeNew = _size + 1;
		dataPtrNew = new int[sizeNew] {};
		partCopy(0, indx, dataPtrNew);
		partCopy(indx, sizeNew - 1, 1, dataPtrNew);
		dataPtrNew[indx] = value;
		break;
	case 2: // Remove element
		sizeNew = _size - 1;
		dataPtrNew = new int[sizeNew] {};
		partCopy(0, indx - 1, dataPtrNew);
		partCopy(indx + 1, sizeNew - 1, -1, dataPtrNew);
		break;
	default:
		break;
	}
	if (_dataPtr) //delete after
		delete[] _dataPtr;
	_dataPtr = dataPtrNew;
	_size = sizeNew;
	return;
}

void IntegerArray::partCopy(const int startIndx, const int endIndx, const int shift, int* dataPtrNew)
{
	for (size_t i = startIndx; i <= endIndx; i++)
	{
		dataPtrNew[i + shift] = _dataPtr[i];
	}
}
void IntegerArray::partCopy(const int startIndx, const int endIndx, int* dataPtrNew)
{
	for (size_t i = startIndx; i <= endIndx; i++)
	{
		dataPtrNew[i] = _dataPtr[i];
	}
}

