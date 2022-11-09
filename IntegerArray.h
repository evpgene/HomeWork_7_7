#pragma once

class IntegerArray
{
public:
	IntegerArray() = default;
	IntegerArray(int size);
	IntegerArray(const IntegerArray* Source);
	IntegerArray& operator= (const IntegerArray& Source);
	~IntegerArray();
	void setNewSize(const int sizeNew);
	void setElement(const int indx, const int value);
	void deleteArray();
	int getElement(const int indx);
	int getSize() const;
	void insertElement(const int indx, const int value);
	void insertElementBeginning(const int value);
	void insertElementEnd(const int value);
	void removeElement(const int indx);
	void removeElementBegining();
	void removeElementEnd();
	int findElement(const int value);
	void print();
	int& operator [] (int) const;
private:
	int _size; //Длина массива
	int* _dataPtr{ nullptr };
	void partCopy(const int startIndx, const int endIndx, const int shift, int* dataPtrNew); //copy from ...to included with shift;
	void partCopy(const int startIndx, const int endIndx, int* dataPtrNew); //copy from ...to included;
	void change(const int indx, const int value, int sizeNew, const int operation);

};