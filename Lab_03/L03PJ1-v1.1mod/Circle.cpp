#include <iostream>
#include "Circle.h"
#include <math.h>
#define PI 3.14

Circle::Circle(Coordinate center, double r) {
	this->center = center;
	this->r = r;
}

double Circle::getR() const {
	return this->r;
}

Coordinate Circle::getCenter() const {
	return this->center;
}

double Circle::computePerimeter() const {
	return 2 * PI * this->r;
}

double Circle::computeDistance() const {
	double x = this->center.getXCoordinate();
	double y = this->center.getYCoordinate();
	double z = std::pow(x, 2) + std::pow(y, 2);
	double distance = std::sqrt(z);
	return distance;
}

ICloneable* Circle::clone() const {
	return new Circle(*this);
}

void Circle::print(std::ostream& os) const {
	os << "Circle:" << std::endl;
	this->printCircle(os);
	if (this->perimeterComparison == true) {
		os << this->computePerimeter() << std::endl;
	}
	else {
		os << this->computeDistance() << std::endl;
	}
}

void Circle::perimeterComparisonFunc(bool condition) {
	this->perimeterComparison = condition;
}

void Circle::printCircle(std::ostream& os) const {
	os << this->r << ", " << "(" << this->center.getXCoordinate() << ", "
		<< this->center.getYCoordinate() << ")" << std::endl;
}

bool Circle::returnPerimeterComparison() const {
	return this->perimeterComparison;
}