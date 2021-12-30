#include "UnlimitedSortedAndComparableSet.h"
#include <iostream>
#include <functional>

void USCSet::transformElements(std::function<IObject* (const IObject&)>f) {
	USCSet* other = new USCSet[1](this->comparePerimeter);
	this->helpForTransform(f, other);
	*this = *other;
}

ICollection* USCSet::transformToNewCollection(std::function<IObject* (const IObject&)>f) const {
	USCSet* other = new USCSet[1](this->comparePerimeter);
	this->helpForTransform(f, other);
	return other;
}

ICollection* USCSet::clone() const {
	return new USCSet(*this);
}