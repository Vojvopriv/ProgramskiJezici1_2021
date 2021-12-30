#include <iostream>
#include "UnlimitedSortedSet.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Polygon.h"
#include "Square.h"
#include "IEquatable.h"

USSet::USSet(bool comparePerimeter) : UUSet(comparePerimeter) {
	this->setSortElements = true;
	this->comparePerimeter = comparePerimeter;
}

bool USSet::compareSets(const ICollection& other) const {
	const USSet* otherSet = dynamic_cast<const USSet*>(&other);
	if (this->arrLen != otherSet->arrLen) {
		return false;
	}
	for (int i = 0; i < this->arrLen; i++) {
		if (*this->arr[i] != *otherSet->arr[i])
			return false;
	}

	return true;
}

void USSet::transformElements(std::function<IObject* (const IObject&)>f) {
	USSet* other = new USSet[1](this->comparePerimeter);
	this->helpForTransform(f, other);
	*this = *other;
}

ICollection* USSet::transformToNewCollection(std::function<IObject* (const IObject&)>f) const {
	USSet* other = new USSet[1](this->comparePerimeter);
	this->helpForTransform(f, other);
	return other;
}

ICollection* USSet::clone() const {
	return new USSet(*this);
}

