#include <iostream>
#include "UnlimitedUnsortedSet.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Polygon.h"
#include "Square.h"
#include "IEquatable.h"
#include <functional>

UUSet::UUSet(bool comparePerimeter) : arr(nullptr), arrLen(0) {
	this->comparePerimeter = comparePerimeter;
}

UUSet::UUSet(const UUSet& other) : arrLen(other.arrLen), arr(new IObject* [other.arrLen]) {
	this->copy(other);
}

UUSet::UUSet(UUSet&& other) : arrLen(other.arrLen), arr(other.arr) {
	other.arr = nullptr;
	other.arrLen = 0;
}

UUSet& UUSet::operator=(const UUSet& other) {
	if (this == &other)
		return *this;

	this->arrLen = other.arrLen;
	this->copy(other);
	return *this;
}

UUSet& UUSet::operator=(UUSet&& other) {
	if (this == &other)
		return *this;

	this->arr = other.arr;
	this->arrLen = other.arrLen;
	other.arr = nullptr;
	other.arrLen = 0;

	return *this;
}

UUSet::~UUSet() {
	this->dispose();

}

bool UUSet::add(const IObject& object) {
	if (checkForAdding(object)) {
		std::cout << "Neuspjesno dodavanje!" << std::endl;
		return false;
	}

	if (this->arr == nullptr)
		this->arr = new IObject * [1];
	else
		realloc(this->arrLen + 1);

	this->arr[this->arrLen] = dynamic_cast<IObject*>(object.clone());
	this->arr[this->arrLen]->perimeterComparisonFunc(this->comparePerimeter);
	this->arrLen++;

	if (setSortElements) {
		this->sortElements();
	}

	return true;
}

bool UUSet::remove(const IObject& object) {
	size_t i;
	for (i = 0; i < this->arrLen; i++) {
		if (*this->arr[i] == object)
			break;
	}

	if (this->arr[i] == nullptr)
		return false;

	for (size_t j = i; j < this->arrLen - 1; j++) {
		delete this->arr[j];
		this->arr[j] = dynamic_cast<IObject *>(this->arr[j + 1]->clone());
	}

	delete this->arr[this->arrLen - 1];
	this->arr[this->arrLen - 1] = nullptr;
	realloc(this->arrLen - 1);
	//this->arrLen--;

	return true;
}

void UUSet::forEach(const std::function<void(IObject&)>& f) {
	for (int i = 0; i < this->arrLen; i++) {
		f(*this->arr[i]);
	}
}

void UUSet::forEach(const std::function<void(const IObject&)>& f) const {
	for (int i = 0; i < this->arrLen; i++) {
		f(*this->arr[i]);
	}
}

void UUSet::print(std::ostream& os) const {
	this->forEach([](const IObject& object) {
		std::cout << object << std::endl;
		});
}

/*void UUSet::printObjects() const {
	this->forEach([](const IObject& object) {
		std::cout << object << std::endl;
		});
}*/

void UUSet::copy(const UUSet& other) {
	for (int i = 0; i < other.arrLen; i++) {
		this->arr[i] = dynamic_cast<IObject*>(other.arr[i]->clone());
	}
}

bool UUSet::compareSets(const ICollection& other) const {
	const UUSet* otherSet = dynamic_cast<const UUSet*>(&other);
	if (this->arrLen != otherSet->arrLen) {
		return false;
	}

	int numberOfSameElements = 0;
	for (int i = 0; i < this->arrLen; i++) {
		for (int j = 0; j < this->arrLen; j++) {
			if (*this->arr[i] == *this->arr[j])
				numberOfSameElements++;
			}
		}
	if (numberOfSameElements == this->arrLen)
		return true;

	return false;
}

size_t UUSet::size() const {
	return this->arrLen;
}

UUSet UUSet::filterElementsUUSet(const std::string& s) const {
	UUSet result(this->comparePerimeter);

	if (s != "Rectangle" && s != "Square" && s != "Polygon" && s != "Circle") {
		std::cout << "Ne moze se pronaci element sa neispravnim nazivom!" << std::endl;
		return result;
	}

	for (int i = 0; i < this->arrLen; i++) {
		if (s == "Rectangle") {
			Rectangle* r = dynamic_cast<Rectangle*>(this->arr[i]);
			if (r != nullptr)
				result.add(*r);
		}
		else if (s == "Square") {
			Square* r = dynamic_cast<Square*>(this->arr[i]);
			if (r != nullptr)
				result.add(*r);
		}
		else if (s == "Polygon") {
			Polygon* r = dynamic_cast<Polygon*>(this->arr[i]);
			if (r != nullptr)
				result.add(*r);
		}
		else {
			Circle* r = dynamic_cast<Circle*>(this->arr[i]);
			if (r != nullptr)
				result.add(*r);
		}
	}

	return result;
}

ICollection* UUSet::filterElements(const std::string& s) const {
	UUSet *result = new UUSet(this->comparePerimeter);

	if (s != "Rectangle" && s != "Square" && s != "Polygon" && s != "Circle") {
		std::cout << "Ne moze se pronaci element sa neispravnim nazivom!" << std::endl;
		return result;
	}

	for (int i = 0; i < this->arrLen; i++) {
		if (s == "Rectangle") {
			Rectangle* r = dynamic_cast<Rectangle*>(this->arr[i]);
			if (r != nullptr)
				result->add(*r);
		}
		else if (s == "Square") {
			Square* r = dynamic_cast<Square*>(this->arr[i]);
			if (r != nullptr)
				result->add(*r);
		}
		else if (s == "Polygon") {
			Polygon* r = dynamic_cast<Polygon*>(this->arr[i]);
			if (r != nullptr)
				result->add(*r);
		}
		else {
			Circle* r = dynamic_cast<Circle*>(this->arr[i]);
			if (r != nullptr)
				result->add(*r);
		}
	}

	return result;
}

ICollection* UUSet::clone() const {
	return new UUSet(*this);
}

void UUSet::transformElements(std::function<IObject* (const IObject&)>f) {
	UUSet* other = new UUSet[1](this->comparePerimeter);
	this->helpForTransform(f, other);
	*this = *other;
}

ICollection* UUSet::transformToNewCollection(std::function<IObject* (const IObject&)>f) const {
	UUSet* other = new UUSet[1](this->comparePerimeter);
	this->helpForTransform(f, other);
	return other;
}

void UUSet::helpForTransform(std::function<IObject* (const IObject&)>f, ICollection *other) const {
	this->forEach([&f, other](const IObject& object) {
		IObject* temp;
		temp = f(object);
		other->add(*temp);
		});
}

void UUSet::realloc(size_t newCapacity) {
	IObject** newArr = new IObject * [newCapacity];
	size_t newLength = this->arrLen < newCapacity ? this->arrLen : newCapacity;
	this->arrLen = newLength;
	for (int i = 0; i < newLength; i++) {
		newArr[i] = this->arr[i];
	}
	delete[] this->arr;
	this->arr = newArr;
}

bool UUSet::checkForAdding(const IObject& other) {
	for (int i = 0; i < this->arrLen; i++)
		if (*this->arr[i] == other)
			return true;

	return false;
}

IObject** UUSet::getObjects() const {
	return this->arr;
}

void UUSet::dispose() {
	for (size_t i = 0; i < this->arrLen; i++)
		delete this->arr[i];

	delete[] this->arr;
}

void UUSet::sortElements() const {
	for (size_t i = 0; i < this->arrLen - 1; i++) {
		for (size_t j = i; j < this->arrLen; j++) {
			if (*this->arr[i] > *this->arr[j]) {
				IObject* temp = dynamic_cast<IObject *>(this->arr[i]);
				this->arr[i] = dynamic_cast<IObject *>(this->arr[j]);
				this->arr[j] = dynamic_cast<IObject *>(temp);
			}
		}
	}
}

IObject* UUSet::quickSearch(const IObject& find) const {
	if (this->setSortElements == true) {
		for (int i = 0; i < this->arrLen; i++) {
			if (*this->arr[i] == find) {
				return this->arr[i];
			}
		}
	}
	return nullptr;
}