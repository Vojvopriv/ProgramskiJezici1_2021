#include <iostream>
#include "UnlimitedSortedSet.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Polygon.h"
#include "Square.h"
#include "IEquatable.h"
#include "IObject.h"
#include "IPosition2D.h"
#include "IShape2D.h"

USSet::USSet(bool sortByPerimeter) : UUSet() { 
	this->sortByPerimeter = sortByPerimeter;
}

USSet::USSet(const USSet& other) {
	this->arrLen = other.arrLen;
	this->sortByPerimeter = other.sortByPerimeter;
	this->arr = new IObject * [other.arrLen];
	this->copy(other);
}

USSet::USSet(USSet&& other) {
	this->arrLen = other.arrLen;
	this->arr = other.arr;
	this->sortByPerimeter = other.sortByPerimeter;
	other.arr = nullptr;
	other.arrLen = 0;
}

USSet& USSet::operator=(const USSet& other) {
	if (this == &other)
		return *this;

	this->dispose();
	this->arr = new IObject * [other.arrLen];
	this->arrLen = other.arrLen;
	this->sortByPerimeter = other.sortByPerimeter;
	this->copy(other);
	return *this;
}

USSet& USSet::operator=(USSet&& other) {
	if (this == &other)
		return *this;

	this->arr = other.arr;
	this->sortByPerimeter = other.sortByPerimeter;
	this->arrLen = other.arrLen;
	other.arr = nullptr;
	other.arrLen = 0;

	return *this;
}

bool USSet::add(const IObject& object) {
	bool didAdd = this->UUSet::add(object);

	if (didAdd)
		this->sortElements();

	return didAdd;
}

void USSet::copy(const USSet& other) {
	for (int i = 0; i < other.arrLen; i++) {
		this->arr[i] = dynamic_cast<IObject*>(other.arr[i]->clone());
	}
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
	USSet* other = new USSet[1](this->sortByPerimeter);
	this->helpForTransform(f, other);
	*this = *other;
}

ICollection* USSet::transformToNewCollection(std::function<IObject* (const IObject&)>f) const {
	USSet* other = new USSet[1](this->sortByPerimeter);
	this->helpForTransform(f, other);
	return other;
}

ICollection* USSet::clone() const {
	return new USSet(*this);
}

void USSet::sortElements() const {
	if (this->sortByPerimeter) {
		for (size_t i = 0; i < this->arrLen - 1; i++) {
			for (size_t j = i; j < this->arrLen; j++) {
				if (this->arr[i]->computePerimeter() > this->arr[j]->computePerimeter()) {
					IObject* temp = dynamic_cast<IObject*>(this->arr[i]);
					this->arr[i] = dynamic_cast<IObject*>(this->arr[j]);
					this->arr[j] = dynamic_cast<IObject*>(temp);
				}
			}
		}
	}
	else {
		for (size_t i = 0; i < this->arrLen - 1; i++) {
			for (size_t j = i; j < this->arrLen; j++) {
				if (this->arr[i]->computeDistance() > this->arr[j]->computeDistance()) {
					IObject* temp = dynamic_cast<IObject*>(this->arr[i]);
					this->arr[i] = dynamic_cast<IObject*>(this->arr[j]);
					this->arr[j] = dynamic_cast<IObject*>(temp);
				}
			}
		}
	}
}

/*IObject* USSet::quickSearch(const IObject& find) const {
	for (int i = 0; i < this->arrLen; i++) {
		if (*this->arr[i] == find) {
			return this->arr[i];
		}
	}

	std::cout << "Nije pronadjen ni jedan element" << std::endl;
	return nullptr;
}*/
