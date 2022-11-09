#include "Main.h"

int main()
{
	try
	{
		//—оздать контейнер (пустой)
		IntegerArray* array1Ptr = new IntegerArray();
		IntegerArray& array1 = (*array1Ptr);
		cout << "size = " << array1.getSize() << endl;

		//»зменить размер контейнера
		array1.setNewSize(10);
		cout << "size = " << array1.getSize() << endl;

		//«аполнить контейнер значени€ми, равными пор€дковому номеру элемента
		//с использованием индекса 
		for (size_t i = 0; i < array1.getSize(); i++)
		{
			array1[i] = i;
		}
		cout << endl << "array filled 1,2..n " << endl;
		array1.print();
		cout << "size = " << array1.getSize() << endl;

		//установить значение элемента
		array1Ptr->setElement(9, 500);
		array1Ptr->setElement(0, 102);

		//записать элемент за пределами контейнера
		cout << endl << "setting an element outside the array started" << endl;
		try
		{
			array1[1000] = 101;
		}
		catch (exception& except)
		{
			cout << endl << except.what() << endl;
		}
		cout << endl << "setting an element outside the array is complete" << endl;

		array1.print();

		//изменить размер массива
		array1.setNewSize(12);

		cout << endl << "new size is set =12 " << endl;
		array1.print();

		//вставить элемент
		array1.insertElement(10, 35);

		cout << endl << "inserted element 10 = 35 " << endl;
		array1.print();

		//убрать элемент
		array1.removeElement(9);
		cout << endl << "removed element 9" << endl;
		array1.print();


		array1[5] = 54321;
		int index = 5;
		cout << endl << "Element with index " << index << " = " << array1[index] << ' ' << endl;



		//поиск елемента
		cout << endl << "element search started..." << endl;
		try
		{
			int elIndex = array1.findElement(54321);
			cout <<  "found element with index: " << elIndex << endl;
		}
		catch (exception& except)
		{
			cout << endl << except.what() << endl;
		}

		// опирование контейнера
		IntegerArray* array2Ptr = new IntegerArray();
		IntegerArray& array2 = *array2Ptr;
		cout << endl << "Print array 2 before copy:" << endl;
		array2.print();
		array2 = array1;
		delete array1Ptr;
		cout << "Print array 2 after copy:" << endl;
		array2.print();
		delete array2Ptr;
		cout << "//////////// Goodbye! //////////////" << endl;
	}
	catch (exception& except)
	{
		cout << except.what() << endl;
	}
	return 0;
}