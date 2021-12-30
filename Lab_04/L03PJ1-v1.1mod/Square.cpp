#include "Square.h"
#include <iostream>

Square::Square(Coordinate A, Coordinate D) {
	if (D.getXCoordinate() - A.getXCoordinate() == D.getYCoordinate() - A.getYCoordinate()) {
		this->r = Rectangle(A, D);
	}
	else
		std::cout << "Neispravne koordinate, ne moze se kreirati kvadrat!" << std::endl;
}

double Square::getA() const {
	return this->r.getA();
}

double Square::computePerimeter() const {
	return this->r.computePerimeter();
}
double Square::computeDistance() const {
	return this->r.computeDistance();
}

ICloneable* Square::clone() const {
	return new Square(*this);
}

void Square::print(std::ostream& os) const {
	std::cout << "Square:" << std::endl;
	this->printSquare(os);
	os << "Perimeter: " << this->computePerimeter() << std::endl;
	os << "Distance: " << this->computeDistance() << std::endl;
}

void Square::printSquare(std::ostream& os) const {
	os << this->r.getA() << "( " << this->r.getCoordinateA().getXCoordinate() <<
		", " << this->r.getCoordinateA().getYCoordinate() << "), (" <<
		this->r.getCoordinateD().getXCoordinate() << ", " << this->r.getCoordinateD().getYCoordinate() <<
		")" << std::endl;
}

bool Square::operator==(const IObject& other) const {
	const Square* r = dynamic_cast<const Square*>(&other);
	if (r != nullptr) {
		if (this->r.getCoordinateA() == r->r.getCoordinateA() && this->r.getCoordinateD() == r->r.getCoordinateD())
			return true;
	}

	return false;
}
