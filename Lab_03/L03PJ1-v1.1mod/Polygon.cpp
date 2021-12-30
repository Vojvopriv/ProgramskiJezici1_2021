#include "Polygon.h"
#include <iostream>

Polygon::Polygon(int numberOfCoordinates, Coordinate* cArray) {
	this->cArray = cArray;
	this->numberOfCoordinates = numberOfCoordinates;
}

Polygon::Polygon(const Polygon& other) : numberOfCoordinates(other.numberOfCoordinates), cArray(new Coordinate[other.numberOfCoordinates]) {
	for (int i = 0; i < numberOfCoordinates; i++)
		this->cArray[i] = other.cArray[i];
}

Polygon::Polygon(Polygon&& other) : numberOfCoordinates(other.numberOfCoordinates), cArray(other.cArray) {
	other.cArray = nullptr;
	other.numberOfCoordinates = 0;
}

Polygon& Polygon::operator=(const Polygon& other) {
	if (this == &other)
		return *this;

	this->dispose();
	this->cArray = new Coordinate[other.numberOfCoordinates];
	this->numberOfCoordinates = other.numberOfCoordinates;

	for (int i = 0; i < numberOfCoordinates; i++)
		this->cArray[i] = other.cArray[i];

	return *this;
}

Polygon& Polygon::operator=(Polygon&& other) {
	if (this == &other)
		return *this;

	this->dispose();
	this->cArray = other.cArray;
	this->numberOfCoordinates = other.numberOfCoordinates;

	return *this;
}

void Polygon::dispose() {
	delete[] this->cArray;
}

Polygon::~Polygon() {
	this->dispose();
}

double Polygon::computePerimeter() const {
	double perimeter = 0.0, dx, dy;
	for (int i = 0; i < this->numberOfCoordinates; i++) {
		int temp1 = (i + 1) % numberOfCoordinates;
		dx = this->cArray[temp1].getXCoordinate() - this->cArray[i].getXCoordinate();
		dy = this->cArray[temp1].getYCoordinate() - this->cArray[i].getYCoordinate();
		perimeter += std::sqrt(dx * dx + dy * dy);
	}
	return perimeter;
}

double Polygon::computeDistance() const {
	/*double signedArea = 0.0;
	double x0; // Current vertex X
	double y0; // Current vertex Y
	double x1; // Next vertex X
	double y1; // Next vertex Y
	double a;  // Partial signed area

	double rez1 = 0;
	double rez2 = 0;

	int i = 0;
	for (i = 0; i < numberOfCoordinates - 1; i++)
	{
		x0 = this->cArray[i].getXCoordinate();
		y0 = this->cArray[i].getYCoordinate();
		x1 = this->cArray[i + 1].getXCoordinate();
		y1 = this->cArray[i + 1].getYCoordinate();
		a = x0 * y1 - x1 * y0;
		signedArea += a;
		rez1 += (x0 + x1) * a;
		rez2 += (y0 + y1) * a;
	}

	x0 = this->cArray[i].getXCoordinate();
	y0 = this->cArray[i].getYCoordinate();
	x1 = this->cArray[0].getXCoordinate();
	y1 = this->cArray[0].getYCoordinate();
	a = x0 * y1 - x1 * y0;
	signedArea += a;
	rez1 += (x0 + x1) * a;
	rez2 += (y0 + y1) * a;

	signedArea *= 0.5;
	if (6.0 * signedArea == 0)
		return 0.0;
	rez1 /= (6.0 * signedArea);
	rez2 /= (6.0 * signedArea);

	double rez = std::sqrt(rez1 * rez1 + rez2 * rez2);

	return rez;*/

	Coordinate min = this->findMin();
	double x = min.getXCoordinate();
	double y = min.getYCoordinate();
	double z = std::pow(x, 2) + std::pow(y, 2);
	double distance = std::sqrt(z);
	return distance;
}

ICloneable* Polygon::clone() const {
	return new Polygon(*this);
}

void Polygon::print(std::ostream& os) const {
	std::cout << "Polygon:" << std::endl;
	this->printPolygon(os);
	if (this->perimeterComparison == true) {
		os << this->computePerimeter() << std::endl;
	}
	else {
		os << this->computeDistance() << std::endl;
	}
}

void Polygon::perimeterComparisonFunc(bool condition) {
	this->perimeterComparison = condition;
}

Coordinate Polygon::findMin() const {
	Coordinate rez;
	double min = this->cArray[0].getXCoordinate();
	for (int i = 1; i < this->numberOfCoordinates; i++) {
		if (this->cArray[i].getXCoordinate() < min) {
			min = this->cArray[i].getXCoordinate();
			rez = this->cArray[i];
		}
			
	}
	return rez;
}

void Polygon::printPolygon(std::ostream& os) const {
	for (int i = 0; i < this->numberOfCoordinates - 1; i++) {
		os << "(" << this->cArray[i].getXCoordinate() << ", " << this->cArray[i].getYCoordinate() << ")"
			<< ", ";
	}
	os << "(" << this->cArray[numberOfCoordinates - 1].getXCoordinate()
		<< ", " << this->cArray[numberOfCoordinates - 1].getYCoordinate() << ")" << std::endl;
}

bool Polygon::returnPerimeterComparison() const {
	return this->perimeterComparison;
}