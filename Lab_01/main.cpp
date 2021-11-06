// Lab01.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Set.h"


int main()
{
	using Numbers::Set;

	Set s1, s2;

	s1.addToArray(7);
	s1.addToArray(8);
	s1.addToArray(6);
	s1.addToArray(3);
	s1.addToArray(4);
	s1.addToArray(7);

	s1.deleteElement(8);
	s1.print();

	s2.addToArray(3);
	s2.addToArray(2);
	s2.addToArray(7);
	s2.addToArray(-99);
	s2.addToArray(4);

	s2.deleteElement(-99);
	s2.print();

	if (s1.isEqual(s2.getArray(), s2.getArraySize())) std::cout << "Jednaki su" << std::endl;
	else std::cout << "Nisu jednaki" << std::endl;
}