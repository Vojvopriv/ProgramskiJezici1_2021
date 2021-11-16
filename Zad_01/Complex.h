#pragma once

namespace Math {

	class Complex {
	public:
		Complex(double re=0, double im =0);
		Complex(const Complex&);
		//~Complex();

		friend const Complex operator+ (const Complex&, const Complex&);
		friend const Complex operator* (const Complex&, const Complex&);

		void print() const;
	private:
		double re;
		double im;
	};

}