#pragma once
#include "IObject.h"
#include "Coordinates.h"

class Rectangle : virtual public IObject {
private:
	double a, b;
	Coordinate A;
	Coordinate B;
	Coordinate C;
	Coordinate D;
	bool perimeterComparison = true;
public:
	Rectangle();
	Rectangle(Coordinate A, Coordinate D);
	Rectangle operator+(Rectangle r);
	Rectangle operator*(double X);
	Rectangle operator&(Rectangle r);

	double getA() const;
	double getB() const;
	Coordinate getCoordinateA() const;
	Coordinate getCoordinateB() const;
	Coordinate getCoordinateC() const;
	Coordinate getCoordinateD() const;
	Coordinate getCenter() const;

	virtual double computePerimeter() const override;
	virtual double computeDistance() const override;
	virtual ICloneable* clone() const override;
	virtual void perimeterComparisonFunc(bool condition) override;
	virtual bool returnPerimeterComparison() const override;
private:
	//bool condition(Coordinate A, Coordinate B, Coordinate C, Coordinate D) const;
	//bool isInLine(Coordinate A, Coordinate B, Coordinate C, Coordinate D) const;
	//bool areCoordinatesRight(Coordinate A, Coordinate B, Coordinate C, Coordinate D) const;
	bool doTheyOverlap(Rectangle r) const;
	double getArea() const;
	Rectangle helpForPlus(Rectangle r2) const;
	bool minmaxX() const;
	bool minmaxY() const;
	Coordinate setBCoordinate();
	Coordinate setCCoordinate();
	void printRectangle(std::ostream& os) const;
	virtual void print(std::ostream& os) const override;
};