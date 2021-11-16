#pragma once

#include "Complex.h"

namespace Math {

	class Matrix {
		// Matrice su podrazumijevano dimenzije 2x2
	public:
		Matrix(Complex z1 = 0, Complex z2 = 0, Complex z3 = 0, Complex z4 = 0);
		Matrix(const Matrix&);
		~Matrix();

		friend const Matrix operator+ (const Matrix& m1, const Matrix& m2);
		friend const Matrix operator* (const Matrix& m1, const Matrix& m2);

	private:
		Complex** matrix;
	};

}