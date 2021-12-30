#pragma once
#include <iostream>
#include "IObject.h"
#include "GenericSet.h"

template <typename T>
concept Comparable = requires(const T& t1, const T& t2) {
	{t1 < t2} -> std::convertible_to<bool>;
	{t1 <= t2} -> std::convertible_to<bool>;
	{t1 > t2} -> std::convertible_to<bool>;
	{t1 >= t2} -> std::convertible_to<bool>;
};

/*template <class T>
requires Comparable<T>
class SortedSet : virtual public Set<T> {
public:

	void add(const T& other) {
		Set<T>::add(other);
	}


	bool tryAdd(const T& other) {
		return Set<T>::tryAdd(other);
	}
};*/


class SortedSet : virtual public Set<IObject> {
private:
	bool perimeterComparison;

public:
	SortedSet(bool perimeterComparison = true) : Set<IObject>() {
		this->perimeterComparison = perimeterComparison;
	}

	template <class T>
	requires Comparable<T>
	void add(const T& other) {
		this->Set::add(other);
		this->sortElements();
	}

	template <class T>
	requires Comparable<T>
	bool tryAdd(const T& other) {
		if (this->Set::tryAdd(other)) {
			this->sortElements();
			return true;
		}
		return false;
	}

private:
	void sortElements() const {
		if (this->perimeterComparison == true) {
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


};