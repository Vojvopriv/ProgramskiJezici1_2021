#pragma once
#include "IEquatable.h"
#include "IPrintable.h"
#include "ICloneable.h"

class IShape2D : virtual public IPrintable, virtual public ICloneable {
public:
	virtual double computePerimeter() const = 0;
	virtual bool comparePerimeter(const IShape2D& other) const {
		if (this->computePerimeter() > other.computePerimeter())
			return true;
		return false;
	}

	virtual bool isPerimeterEqual(const IShape2D& other) const {
		if (this->computePerimeter() == other.computePerimeter())
			return true;
		
		return false;
	}

	virtual ~IShape2D() = 0 {}
};