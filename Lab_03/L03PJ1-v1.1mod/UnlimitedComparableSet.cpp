#include "UnlimitedComparableSet.h"

UCSet::UCSet(bool comparePerimeter) : UUSet(comparePerimeter) {
	this->setSortElements = false;
	this->comparePerimeter = comparePerimeter;
}

bool UCSet::operator==(const UCSet& other) const {
	if (this->compareSets(other))
		return true;
	return false;
}

bool UCSet::operator!=(const UCSet& other) const {
	return !(*this == other);
}

bool UCSet::operator<(const UCSet& other) const {
	return this->helpFunction(other);
}

bool UCSet::operator>(const UCSet& other) const {
	return !(*this < other);
}

bool UCSet::operator<=(const UCSet& other) const {
	if (*this == other)
		return true;
	
	return this->helpFunction(other);
}

bool UCSet::operator>=(const UCSet& other) const {
	return !(*this <= other);
}

bool UCSet::helpFunction(const UCSet& other) const {
	int elements = 0;
	for (int i = 0; i < this->arrLen; i++) {
		for (int j = 0; j < other.arrLen; j++) {
			if (*this->arr[i] == *other.arr[j]) {
				elements++;
			}
		}
	}

	if (elements == this->arrLen)
		return true;

	return false;
}

void UCSet::transformElements(std::function<IObject* (const IObject&)>f) {
	UCSet* other = new UCSet[1](this->comparePerimeter);
	this->helpForTransform(f, other);
	*this = *other;
}

ICollection* UCSet::transformToNewCollection(std::function<IObject* (const IObject&)>f) const {
	UCSet* other = new UCSet[1](this->comparePerimeter);
	this->helpForTransform(f, other);
	return other;
}

ICollection* UCSet::clone() const {
	return new UCSet(*this);
}