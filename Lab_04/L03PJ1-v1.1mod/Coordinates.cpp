#include "Coordinates.h"
#include <iostream>

Coordinate::Coordinate(double x, double y) {
	this->x = x;
	this->y = y;
}

double Coordinate::getXCoordinate() const {
	return this->x;
}

double Coordinate::getYCoordinate() const {
	return this->y;
}

bool Coordinate::operator==(Coordinate c) const {
	if (this->x == c.x && this->y == y)
		return true;

	return false;
}

bool Coordinate::isXBigger(Coordinate c) const {
	if (this->x >= c.x)
		return true;

	return false;
}

bool Coordinate::isYBigger(Coordinate c) const {
	if (this->y >= c.y)
		return true;

	return false;
}
