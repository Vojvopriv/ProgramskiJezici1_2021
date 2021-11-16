// Zad_01.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Complex.h"
#include "Matrix.h"


int main()
{
    Math::Complex c1(1, 2);
    Math::Complex c2(0, 1);
    Math::Complex c3(5, 2);
    Math::Complex c4(-2, 3);

    c1.print();
    c2.print();
    c3.print();
    c4.print();

    Math::Complex c5 = c1 + c2;
    Math::Complex c6 = c1 * c2;
    Math::Complex c7 = c2 + c3;
    Math::Complex c8 = c3 * c4;

    c5.print();
    c6.print();
    c7.print();
    c8.print();





    std::cout << "Hello World!\n";
}
