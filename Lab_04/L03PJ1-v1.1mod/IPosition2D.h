#pragma once
#include "IEquatable.h"
#include "IPrintable.h"
#include "ICloneable.h"

class IPosition2D : virtual public IPrintable, virtual public ICloneable {
public:
	virtual double computeDistance() const = 0;
	virtual bool compareDistance(const IPosition2D& other) const {
		if (this->computeDistance() > other.computeDistance())
			return true;

		return false;
	}
	virtual bool isDistanceEqual(const IPosition2D& other) const {
		if (this->computeDistance() == other.computeDistance())
			return true;

		return false;
	}

	virtual ~IPosition2D() = 0 {}
};