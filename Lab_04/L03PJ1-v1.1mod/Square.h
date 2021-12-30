#pragma once
#include "Rectangle.h"
#include "IObject.h"

class Square : virtual public IObject {
private:
	Rectangle r;
public:
	Square(Coordinate A, Coordinate D);
	double getA() const;
	virtual double computePerimeter() const override;
	virtual double computeDistance() const override;
	virtual ICloneable* clone() const override;
	virtual bool operator==(const IObject& other) const override;
private:
	void printSquare(std::ostream& os) const;
	virtual void print(std::ostream& os) const override;
};