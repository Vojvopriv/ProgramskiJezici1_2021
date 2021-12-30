#pragma once
#include <iostream>
#include <functional>
#include "Exceptions.h"

template <class T>
class Set {
protected:
	size_t arrLen;
	T** arr;		
public:
	Set() : arrLen(0), arr(nullptr) {}

	Set(const Set& other) : arrLen(other.arrLen), arr(new T* [other.arrLen]) {
		this->copy(other);
	}

	Set(Set&& other) : arrLen(other.arrLen), arr(other.arr) {
		other.arr = nullptr;
		other.arrLen = 0;
	}

	Set& operator=(const Set& other) {
		if (this == &other)
			return *this;

		this->dispose();
		this->arr = new T * [other.arrLen];
		this->arrLen = other.arrLen;
		this->copy(other);
		return *this;
	}

	Set& operator=(Set&& other) {
		if (this == &other)
			return *this;

		this->arr = other.arr;
		this->arrLen = other.arrLen;
		other.arr = nullptr;
		other.arrLen = 0;

		return *this;
	}

	virtual ~Set() {
		this->dispose();
	}

	void add(const T& other) {
		try {
			if (checkForAdding(other)) {		// Provjera jedinstvenosti elementa
				throw InvalidAdd();
			}

			if (this->arr == nullptr)
				this->arr = new T * [1];
			else
				realloc(this->arrLen + 1);

			this->arr[this->arrLen] = dynamic_cast<T*>(other.clone());
			this->arrLen++;

		}

		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}	
	}

	bool tryAdd(const T& other) noexcept {
		try {
			add(other);
		}
		catch (InvalidAdd& e)
		{
			std::cout << e.what();
			return false;
		}

		return true;
	}

	void remove(const T& other) {
		int i;
		for (i = 0; i < arrLen && *this->arr[i] != other; i++) {
			if (*this->arr[i] == other)
				break;
		}

		try {
			if (i == this->arrLen) {
				throw InvalidRemove();
			}

			for (size_t j = i; j < this->arrLen - 1; j++) {
				delete this->arr[j];
				this->arr[j] = dynamic_cast<T*>(this->arr[j + 1]->clone());
			}

			delete this->arr[this->arrLen - 1];
			this->arr[this->arrLen - 1] = nullptr;
			realloc(this->arrLen - 1);
		}
		
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		
	}

	bool tryRemove(const T& other) noexcept {
		int i;
		for (i = 0; i < arrLen && *this->arr[i] != other; i++) {
			if (*this->arr[i] == other)
				break;
		}

		if (i == this->arrLen) {
			std::cout << "Nepostojeci element, ne moze se ukloniti iz seta!" << std::endl;
			return false;
		}

		for (size_t j = i; j < this->arrLen - 1; j++) {
			delete this->arr[j];
			this->arr[j] = dynamic_cast<T*>(this->arr[j + 1]->clone());
		}

		delete this->arr[this->arrLen - 1];
		this->arr[this->arrLen - 1] = nullptr;
		realloc(this->arrLen - 1);

		return true;
	}

	void print() const {
		this->forEach([](const T& object) {
			std::cout << object << std::endl;
			});
	}
	
	void forEach(const std::function<void(T&)>f) {
		for (int i = 0; i < this->arrLen; i++) {
			f(*this->arr[i]);
		}
	}

	void forEach(const std::function<void(const T&)>f) const {
		for (int i = 0; i < this->arrLen; i++) {
			f(*this->arr[i]);
		}
	}
protected:
	void dispose() {
		for (size_t i = 0; i < this->arrLen; i++)
			delete this->arr[i];

		delete[] this->arr;
	}

	void copy(const Set& other) {
		for (int i = 0; i < other.arrLen; i++) {
			this->arr[i] = dynamic_cast<T*>(other.arr[i]->clone());
		}
	}

	bool checkForAdding(const T& other) const {
		for (int i = 0; i < this->arrLen; i++)
			if (*this->arr[i] == other)
				return true;

		return false;
	}

	void realloc(size_t newCapacity) {
		T** newArr = new T * [newCapacity];
		size_t newLength = this->arrLen < newCapacity ? this->arrLen : newCapacity;
		this->arrLen = newLength;
		for (int i = 0; i < newLength; i++) {
			newArr[i] = dynamic_cast<T*>(this->arr[i]->clone());
			//newArr[i] = this->arr[i];
		}
		delete[] this->arr;
		this->arr = newArr;
	}
};