
#include "Matrix.h"
#include "Complex.h"
namespace Math {

	Matrix::Matrix(Complex z1, Complex z2, Complex z3, Complex z4)
	{
		matrix[0] = new Complex[2 * 2];
		for (int i = 1; i < 2; i++)           //1 - rows
		{
			matrix[i] = matrix[0] + i * 2;   //i*cols
		}

		matrix[0][0] = z1;
		matrix[0][1] = z2;
		matrix[1][0] = z3;
		matrix[1][1] = z4;
	}
	//Parametrizovani konstruktor

	Matrix::Matrix(const Matrix& m)
	{
		matrix[0] = new Complex[2 * 2];
		for (int i = 1; i < 2; i++)           //1 - rows
		{
			matrix[i] = matrix[0] + i * 2;   //i*cols
		}

		matrix[0][0] = m.matrix[0][0];
		matrix[0][1] = m.matrix[0][1];
		matrix[1][0] = m.matrix[1][0];
		matrix[1][1] = m.matrix[1][1];
	}
	//Konstruktor kopije

	Matrix::~Matrix()
	{
		delete [] matrix[0];
		delete[] matrix;
	}
	//Destruktor za unistavanje dinamicki alocirane matrice

	const Matrix operator+ (const Matrix& m1, const Matrix& m2)
	{
		return Matrix(m1.matrix[0][0] + m2.matrix[0][0], m1.matrix[0][1] + m2.matrix[0][1], m1.matrix[1][0] + m2.matrix[1][0], m1.matrix[1][1] + m2.matrix[1][1]);
	}

	const Matrix operator* (const Matrix& m1, const Matrix& m2)
	{
		Complex z1 = m1.matrix[0][0] * m2.matrix[0][0] + m1.matrix[0][1] * m2.matrix[1][0];
		Complex z2 = m1.matrix[0][0] * m2.matrix[0][1] + m1.matrix[0][1] * m2.matrix[1][1];
		Complex z3 = m1.matrix[1][0] * m2.matrix[0][0] + m1.matrix[1][1] * m2.matrix[1][0];
		Complex z4 = m1.matrix[1][0] * m2.matrix[0][1] + m1.matrix[1][1] * m2.matrix[1][1];

		return Matrix(z1, z2, z3, z4);
	}


}
