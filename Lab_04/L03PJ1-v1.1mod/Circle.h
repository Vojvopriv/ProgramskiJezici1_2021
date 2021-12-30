#pragma once
#include "Coordinates.h"
#include "IObject.h"

class Circle : virtual public IObject {
private:
	Coordinate center;
	double r;
public:
	Circle(Coordinate center, double r);
	double getR() const;
	Coordinate getCenter() const;
	virtual double computePerimeter() const override;
	virtual double computeDistance() const override;
	virtual ICloneable* clone() const override;
	virtual bool operator==(const IObject& other) const override;
private:
	void printCircle(std::ostream& os) const;
	virtual void print(std::ostream& os) const override;
};