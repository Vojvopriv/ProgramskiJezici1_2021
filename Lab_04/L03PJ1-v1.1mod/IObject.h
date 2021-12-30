#pragma once
#include "IShape2D.h"
#include "IPosition2D.h"

class IObject : virtual public IShape2D, virtual public IPosition2D {
public:
	//SVI ELEMENTI TREBAJU IMATI NASLIJEDJENJE OSOBINE OVA DVA

	virtual bool operator==(const IObject& other) const = 0;
	/*virtual bool operator<(const IObject& other) const {
		return this->computePerimeter() < other.computePerimeter();
	}

	virtual bool operator<=(const IObject& other) const {
		return this->computePerimeter() <= other.computePerimeter();
	}

	virtual bool operator>(const IObject& other) const {
		if (this->computePerimeter() > other.computePerimeter())
			return true;

		return false;
	}

	virtual bool operator>=(const IObject& other) const;*/
};