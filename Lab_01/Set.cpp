#include "Set.h"
#include <iostream>

namespace Numbers {
	Set::Set() : arraySize(0), arrayCapacity(0), array(nullptr) {} 
	//Podrazumijevani konstruktor
	
	/*Set::Set(int size, int* arr) 
	{
		this->arraySize = size; this->arrayCapacity = size;
		array = new int[size];

		for (int i = 0; i < size; i++)
		{
			this->array[i] = arr[i];
		}
	}*/       
	//Parametrizovani konstruktor

	int* Set::getArray()
	{
		return this->array;
	}
	int Set::getArraySize()
	{
		return this->arraySize;
	}

	Set::~Set()
	{
		delete[] this->array;
	}
	//Destruktor se poziva kad odumru staticki alocirani objekti, taman ujedno da se izbrise i dinamicki niz

	void Set::addToArray(int num)
	{
		if (!this->isThere(num))
		{
			if (this->arraySize >= this->arrayCapacity)
			{
				this->reallocate();
			}

			this->array[arraySize] = num;
			this->arraySize++;
		}
	}
	//Prvo provjerava jedinstvenost, pa ima li memorije, pa dodaje 

	int Set::isThere(int x) const
	{
		for (int i = 0; i < this->arraySize; i++)
			if (this->array[i] == x) return -1;
		return 0;
	}
	//Provjerava jedinstvenost elementa

	void Set::reallocate()
	{
		this->reallocate(this->arrayCapacity > 0 ? this->arrayCapacity * 2 : 1);
	}
	void Set::reallocate(int newCapacity)
	{
		int* newArray = new int[newCapacity]();
		this->arrayCapacity = newCapacity;
		this->arraySize = this->arrayCapacity > this->arraySize ? this->arraySize : this->arrayCapacity;
		for (int i = 0; i < this->arraySize; i++)
		{
			newArray[i] = this->array[i];
		}
		delete[] this->array;
		this->array = newArray;
	}


	int Set::deleteElement(int x)
	{
		for (int i = 0; i < this->arraySize; i++)
		{
			if (this->array[i] == x)
			{
				this->array[i] = this->array[arraySize-1];
				this->arraySize--;
				return 0;
			}
		}
	}
	//Uzme zadnji umjesto zadanog pa smanji duzinu niza, ne provjerava dal taj uopste postoji

	void Set::print() const
	{
		for (int i = 0; i < this->arraySize; i++)
		{
			std::cout << this->array[i] << " ";
		}

		std::cout << std::endl;
	}

	int Set::isEqual(int* array, int arrSize) const
	{
		if (this->arraySize != arrSize) return 0; //Nisu jednaki ako su razlicite duzine

		for (int i = 0; i < this->arraySize; i++)
		{
			int pom = 0;
			for (int j = 0; j < arrSize; j++)
			{
				if (this->array[i] == array[j]) pom--;
				else pom++;
			}
			if (pom != this->arraySize - 2)  return 0;   //Nisu jednaki
		}
		return 1; //Jednaki su
	}
	//Ovdje sam proslijedio "getere" jer kad proslijedim klasu cijelu, pozove mi se destruktor a to ne zelim

}