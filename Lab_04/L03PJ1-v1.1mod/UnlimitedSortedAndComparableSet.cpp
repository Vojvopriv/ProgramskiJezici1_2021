#include "UnlimitedSortedAndComparableSet.h"
#include <iostream>
#include <functional>

USCSet::USCSet(const USCSet& other) {
	this->sortByPerimeter = other.sortByPerimeter;
	this->arrLen = other.arrLen;
	this->arr = new IObject * [other.arrLen];
	this->copy(other);
}

USCSet::USCSet(USCSet&& other) {
	this->sortByPerimeter = other.sortByPerimeter;
	this->arrLen = other.arrLen;
	this->arr = other.arr;
	other.arr = nullptr;
	other.arrLen = 0;
}

USCSet& USCSet::operator=(const USCSet& other) {
	if (this == &other)
		return *this;

	this->dispose();
	this->arr = new IObject * [other.arrLen];
	this->arrLen = other.arrLen;
	this->copy(other);
	return *this;
}

USCSet& USCSet::operator=(USCSet&& other) {
	if (this == &other)
		return *this;

	this->arr = other.arr;
	this->arrLen = other.arrLen;
	other.arr = nullptr;
	other.arrLen = 0;

	return *this;
}

void USCSet::transformElements(std::function<IObject* (const IObject&)>f) {
	USCSet* other = new USCSet[1](this->sortByPerimeter);
	this->helpForTransform(f, other);
	*this = *other;
}

ICollection* USCSet::transformToNewCollection(std::function<IObject* (const IObject&)>f) const {
	USCSet* other = new USCSet[1](this->sortByPerimeter);
	this->helpForTransform(f, other);
	return other;
}

ICollection* USCSet::clone() const {
	return new USCSet(*this);
}