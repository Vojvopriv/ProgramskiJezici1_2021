
#include "Complex.h"
#include <iostream>

namespace Math {

	Complex::Complex(double re, double im)
	{
		this->re = re; this->im = im;
	} 
	//Parametrizovani konstruktor

	Complex::Complex(const Complex& z) : re(z.re), im(z.im) {}
	//Konstruktor kopije (nepotreban trenutno)

	const Complex operator+ (const Complex& c1, const Complex& c2)
	{
		return Complex(c1.re + c2.re, c1.im + c2.im);
	}

	const Complex operator* (const Complex& c1, const Complex& c2)
	{
		return Complex(c1.re * c2.re - c1.im * c2.im, c1.re * c2.im + c1.im * c2.re);
	}

	void Complex::print() const
	{
		std::cout << this->re << " + " << this->im << "i" << std::endl;
	}


}
