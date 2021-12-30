#pragma once
#include "IObject.h"
#include "Coordinates.h"

class Polygon : virtual public IObject {
private:
	int numberOfCoordinates;
	Coordinate* cArray;
	bool perimeterComparison;
public:
	Polygon(int numberOfCoordinates, Coordinate* cArray);
	Polygon(const Polygon& other);
	Polygon(Polygon&& other);
	Polygon& operator=(const Polygon& other);
	Polygon& operator=(Polygon&& other);
	~Polygon();

	virtual double computePerimeter() const override;
	virtual double computeDistance() const override;
	virtual ICloneable* clone() const override;
	virtual bool returnPerimeterComparison() const override;
	void perimeterComparisonFunc(bool condition) override;
private:
	void dispose();
	Coordinate findMin() const;
	void printPolygon(std::ostream& os) const;
	virtual void print(std::ostream& os) const override;
};