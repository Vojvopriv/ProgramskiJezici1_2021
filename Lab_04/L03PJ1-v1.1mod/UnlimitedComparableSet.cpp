#include "UnlimitedComparableSet.h"

UCSet::UCSet() : UUSet() {
	//this->setSortElements = false;
}

UCSet::UCSet(const UCSet& other) {
	this->arrLen = other.arrLen;
	this->arr = new IObject * [other.arrLen];
	this->copy(other);
}

UCSet::UCSet(UCSet&& other) {
	this->arrLen = other.arrLen;
	this->arr = other.arr;
	other.arr = nullptr;
	other.arrLen = 0;
}

UCSet& UCSet::operator=(const UCSet& other) {
	if (this == &other)
		return *this;

	this->dispose();
	this->arr = new IObject * [other.arrLen];
	this->arrLen = other.arrLen;
	this->copy(other);
	return *this;
}

UCSet& UCSet::operator=(UCSet&& other) {
	if (this == &other)
		return *this;

	this->arr = other.arr;
	this->arrLen = other.arrLen;
	other.arr = nullptr;
	other.arrLen = 0;

	return *this;
}

/*bool UCSet::operator==(const UCSet& other) const {
	if (this->compareSets(other))
		return true;
	return false;
}

bool UCSet::operator<(const UCSet& other) const {
	return this->helpFunction(other);
}

bool UCSet::operator<=(const UCSet& other) const {
	if (*this == other)
		return true;
	
	return this->helpFunction(other);
}

bool UCSet::operator>=(const UCSet& other) const {
	return !(*this <= other);
}*/

bool UCSet::helpFunction(const UCSet& other) const {
	if (this->arrLen >= other.arrLen)
		return false;

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

//DA LI SE MOZE POREDITI SA BILO KOJIM DRUGIM SETOM?
bool UCSet::operator==(const IEquatable& other) const {
	const UCSet* set = dynamic_cast<const UCSet*>(&other);

	if (set == nullptr)
		return false;

	if (this->compareSets(*set))
		return true;
	return false;
}

bool UCSet::operator<=(const IEquatable& other) const {
	const UCSet* set = dynamic_cast<const UCSet*>(&other);

	if (set == nullptr)
		return false;

	if (this->compareSets(*set) || this->helpFunction(*set))
		return true;

	return false;
}

bool UCSet::operator<(const IEquatable& other) const {
	const UCSet* set = dynamic_cast<const UCSet*>(&other);

	if (set == nullptr)
		return false;

	return this->helpFunction(*set);
}

void UCSet::transformElements(std::function<IObject* (const IObject&)>f) {
	UCSet* other = new UCSet[1]();
	this->helpForTransform(f, other);
	*this = *other;
}

ICollection* UCSet::transformToNewCollection(std::function<IObject* (const IObject&)>f) const {
	UCSet* other = new UCSet[1]();
	this->helpForTransform(f, other);
	return other;
}

ICollection* UCSet::clone() const {
	return new UCSet(*this);
}