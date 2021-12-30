#include <iostream>
#include "Rectangle.h"
#include "Coordinates.h"
#include <math.h>

Rectangle::Rectangle() : a(0.0), b(0.0) {
	Coordinate A;
	this->A = A;
	this->B = A;
	this->C = A;
	this->D = A;
}

Rectangle::Rectangle(Coordinate A, Coordinate D) {
	this->A = A;
	this->D = D;
	this->C = this->setCCoordinate();
	this->B = this->setBCoordinate();
	this->a = B.getXCoordinate() - A.getXCoordinate();
	this->b = C.getYCoordinate() - A.getYCoordinate();
}

Rectangle Rectangle::operator+(Rectangle r) {
	Rectangle rez;
	if (this->getArea() >= r.getArea()) {
		rez = this->helpForPlus(r);
	}
	else {
		rez = r.helpForPlus(*this);
	}
	return rez;
}

Rectangle Rectangle::operator*(double X) {
	if (X <= 0) {
		std::cout << "Nije dozvoljena vrijednost manja ili jednaka od nule!" << std::endl;
		return *this;
	}

	double newA = this->a * sqrt(X);
	double newB = this->b * sqrt(X);

	//double temp = pow(this->a / 2, 2) + pow(this->b / 2, b);
	//double diag = sqrt(temp);
	double diagX = this->getCenter().getXCoordinate();
	double diagY = this->getCenter().getYCoordinate();

	this->a = newA;
	this->b = newB;

	double newcoordAX = diagX - this->a / 2;
	double newcoordAY = diagY - this->b / 2;
	double newcoordBX = diagX + this->a / 2;
	double newcoordBY = diagY - this->b / 2;
	double newcoordCX = diagX - this->a / 2;
	double newcoordCY = diagY + this->b / 2;
	double newcoordDX = diagX + this->a / 2;
	double newcoordDY = diagY + this->b / 2;

	Coordinate A1(newcoordAX, newcoordAY);
	Coordinate B1(newcoordBX, newcoordBY);
	Coordinate C1(newcoordCX, newcoordCY);
	Coordinate D1(newcoordDX, newcoordDY);

	this->A = A1;
	this->B = B1;
	this->C = C1;
	this->D = D1;

	return *this;
}

Rectangle Rectangle::operator&(Rectangle r) {
	Rectangle def;
	if (!this->minmaxX() || !r.minmaxX() || !this->minmaxY() || !r.minmaxY() || !doTheyOverlap(r)) {
		std::cout << "Nisu ispunjeni uslovi za presjek pravougaonika, vraca se default konstruktor" << std::endl;
		return def;
	}

	if (doTheyOverlap(r)) {
		double x5, x6, y5, y6;
		if (this->A.isXBigger(r.A)) {
			x5 = this->A.getXCoordinate();
		}
		else {
			x5 = r.A.getXCoordinate();
		}

		if (this->A.isYBigger(r.A)) {
			y5 = this->A.getYCoordinate();
		}
		else {
			y5 = r.A.getYCoordinate();
		}

		if (this->D.isXBigger(r.D)) {
			x6 = r.D.getXCoordinate();
		}
		else {
			x6 = this->D.getXCoordinate();
		}

		if (this->D.isYBigger(r.D)) {
			y6 = r.D.getYCoordinate();
		}
		else {
			y6 = this->D.getYCoordinate();
		}

		double xC = x5;
		double yC = y6;
		double xB = x6;
		double yB = y5;

		Coordinate aRez(x5, y5);
		Coordinate dRez(x6, y6);

		Rectangle rez(aRez, dRez);
		return rez;
	}
}

double Rectangle::getA() const {
	return this->a;
}

double Rectangle::getB() const {
	return this->b;
}

Coordinate Rectangle::getCoordinateA() const {
	return this->A;
}

Coordinate Rectangle::getCoordinateB() const {
	return this->B;
}

Coordinate Rectangle::getCoordinateC() const {
	return this->C;
}

Coordinate Rectangle::getCoordinateD() const {
	return this->D;
}

Coordinate Rectangle::getCenter() const {
	Coordinate c(this->A.getXCoordinate() + this->a / 2, this->A.getYCoordinate() + this->b / 2);
	return c;
}

void Rectangle::printRectangle(std::ostream& os) const {
	os << "(" << this->a << "," << this->b << ")" << ", (" << this->getCoordinateA().getXCoordinate()
		<< ", " << this->getCoordinateA().getYCoordinate() << "), " << "(" << this->getCoordinateB().getXCoordinate() <<
		"," << this->getCoordinateB().getYCoordinate() << "), " << "(" <<
		this->getCoordinateC().getXCoordinate() << ", " << this->getCoordinateC().getYCoordinate() << "), " << " (" <<
		this->getCoordinateD().getXCoordinate() << ", " << this->getCoordinateD().getYCoordinate() <<
		")" << std::endl;
}

/*bool Rectangle::condition(Coordinate A, Coordinate B, Coordinate C, Coordinate D) const {
	if (B.getXCoordinate() - A.getXCoordinate() == D.getXCoordinate() - C.getXCoordinate()
		&& C.getYCoordinate() - A.getYCoordinate() == D.getYCoordinate() - B.getYCoordinate())
		return true;

	return false;
}*/

/*bool Rectangle::isInLine(Coordinate A, Coordinate B, Coordinate C, Coordinate D) const {
	if (A.getXCoordinate() - C.getXCoordinate() == 0 && B.getXCoordinate() - D.getXCoordinate() == 0 &&
		A.getYCoordinate() - B.getYCoordinate() == 0 && C.getYCoordinate() - D.getYCoordinate() == 0)
		return true;
	else
		return false;
}*/

/*bool Rectangle::areCoordinatesRight(Coordinate A, Coordinate B, Coordinate C, Coordinate D) const {
	if (A.getXCoordinate() >= B.getXCoordinate() ||
		A.getYCoordinate() >= C.getYCoordinate() ||
		C.getXCoordinate() >= D.getXCoordinate() ||
		B.getYCoordinate() >= D.getYCoordinate())
		return false;

	return true;
}*/

bool Rectangle::doTheyOverlap(Rectangle r) const {
	if (
		(r.D.getXCoordinate() <= this->A.getXCoordinate()) ||
		(r.A.getXCoordinate() >= this->D.getXCoordinate()) ||
		(r.D.getYCoordinate() <= this->A.getYCoordinate()) ||
		(r.A.getYCoordinate() >= this->D.getYCoordinate()) ||
		(this->D.getXCoordinate() <= r.A.getXCoordinate()) ||
		(this->A.getXCoordinate()) >= r.D.getXCoordinate() ||
		(this->D.getYCoordinate() <= r.A.getYCoordinate()) ||
		(this->A.getYCoordinate() >= r.D.getYCoordinate())
		)
		return false;
	else
		return true;
}

double Rectangle::getArea() const {
	return this->a * this->b;
}

Rectangle Rectangle::helpForPlus(Rectangle r2) const {
	Rectangle rez;

	if (this->a >= r2.a && this->b >= r2.b) {
		rez.a = this->a + r2.a;
		rez.b = this->b;
		Coordinate aNew(this->A.getXCoordinate(), this->A.getYCoordinate());
		Coordinate bNew(this->B.getXCoordinate() + r2.a, this->B.getYCoordinate());
		Coordinate cNew(this->C.getXCoordinate(), this->C.getYCoordinate());
		Coordinate dNew(this->D.getXCoordinate() + r2.a, this->D.getYCoordinate());
		rez.A = aNew;
		rez.B = bNew;
		rez.C = cNew;
		rez.D = dNew;
	}
	else if (this->a > r2.a && this->b < r2.b) {
		rez.a = this->a + r2.a;
		rez.b = r2.b;
		Coordinate aNew(this->A.getXCoordinate(), this->A.getYCoordinate());
		Coordinate bNew(this->B.getXCoordinate() + r2.a, this->B.getYCoordinate());
		Coordinate cNew(this->C.getXCoordinate(), this->A.getYCoordinate() + r2.b);
		Coordinate dNew(this->D.getXCoordinate() + r2.a, this->B.getYCoordinate() + r2.b);
		rez.A = aNew;
		rez.B = bNew;
		rez.C = cNew;
		rez.D = dNew;
	}
	else if (this->a < r2.a && this->b > r2.b) {
		rez.a = r2.a;
		rez.b = this->b + r2.b;
		Coordinate aNew(this->A.getXCoordinate(), this->A.getYCoordinate());
		Coordinate bNew(this->A.getXCoordinate() + r2.a, this->B.getYCoordinate());
		Coordinate cNew(this->C.getXCoordinate(), this->C.getYCoordinate() + r2.b);
		Coordinate dNew(this->A.getXCoordinate() + r2.a, this->D.getYCoordinate() + r2.b);
		rez.A = aNew;
		rez.B = bNew;
		rez.C = cNew;
		rez.D = dNew;
	}

	if (rez.minmaxX() && rez.minmaxY()) {
		return rez;
	}
	else {
		Rectangle def;
		return def;
	}
}

bool Rectangle::minmaxX() const {
	return (this->A.getXCoordinate() >= -50 && this->D.getXCoordinate() <= 50);
}

bool Rectangle::minmaxY() const {
	return (this->A.getYCoordinate() >= -50 && this->D.getYCoordinate() <= 50);
}

Coordinate Rectangle::setBCoordinate() {
	return Coordinate(this->D.getXCoordinate(), this->A.getYCoordinate());
}

Coordinate Rectangle::setCCoordinate() {
	return Coordinate(this->A.getXCoordinate(), this->D.getYCoordinate());
}

double Rectangle::computePerimeter() const {
	return 2 * a + 2 * b;
}

double Rectangle::computeDistance() const {
	Coordinate center = this->getCenter();
	double x = pow(center.getXCoordinate(), 2);
	double y = pow(center.getYCoordinate(), 2);
	double z = sqrt(x + y);
	return z;
}

ICloneable* Rectangle::clone() const {
	return new Rectangle(*this);
}

void Rectangle::print(std::ostream& os) const {
	os << "Rectangle:" << std::endl;
	this->printRectangle(os);
	if (this->perimeterComparison == true) {
		os << this->computePerimeter() << std::endl;
	}
	else {
		os << this->computeDistance() << std::endl;
	}
}

void Rectangle::perimeterComparisonFunc(bool condition) {
	this->perimeterComparison = condition;
}

bool Rectangle::returnPerimeterComparison() const {
	return this->perimeterComparison;
}