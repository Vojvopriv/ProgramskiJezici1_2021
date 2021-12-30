#pragma once
#include "IShape2D.h"
#include "IPosition2D.h"

class IObject : virtual public IShape2D, virtual public IPosition2D {
public:
	virtual void perimeterComparisonFunc(bool condition) = 0;
	virtual bool returnPerimeterComparison() const = 0;

	virtual bool operator==(const IEquatable& other) const override {
		if (this->returnPerimeterComparison() == true) {
			const IShape2D* p = dynamic_cast<const IShape2D*>(&other);
			return this->isPerimeterEqual(*p);
		}
		else {
			const IPosition2D* p = dynamic_cast<const IPosition2D*>(&other);
			return this->isDistanceEqual(*p);
		}
	}

	virtual bool operator>=(const IEquatable& other) const override {
		if (this->returnPerimeterComparison() == true) {
			const IShape2D* p = dynamic_cast<const IShape2D*>(&other);
			return (this->isPerimeterEqual(*p) || this->comparePerimeter(*p));
		}
		else {
			const IPosition2D* p = dynamic_cast<const IPosition2D*>(&other);
			return (this->isDistanceEqual(*p) || this->compareDistance(*p));
		}
	}

	virtual bool operator>(const IEquatable& other) const override {
		if (this->returnPerimeterComparison() == true) {
			const IShape2D* p = dynamic_cast<const IShape2D*>(&other);
			return (this->comparePerimeter(*p));
		}
		else {
			const IPosition2D* p = dynamic_cast<const IPosition2D*>(&other);
			return (this->compareDistance(*p));
		}
	}
};