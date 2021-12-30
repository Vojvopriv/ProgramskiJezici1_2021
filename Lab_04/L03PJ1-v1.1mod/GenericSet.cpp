/*#include "GenericSet.h"
#include "IObject.h"

Set<IObject> set;

template<class T>
Set<T>::Set() : arrLen(0), arr(nullptr) { }

template<class T>
Set<T>::Set(const Set& other) : arrLen(other.arrLen), arr(new T* [other.arrLen]) {
	this->copy(other);
}

template<class T>
Set<T>::Set(Set&& other) : arrLen(other.arrLen), arr(other.arr) {
	other.arr = nullptr;
	other.arrLen = 0;
}

template<class T>
Set<T>& Set<T>::operator=(const Set& other) {
	if (this == &other)
		return *this;

	this->dispose();
	this->arr = new T * [other.arrLen];
	this->arrLen = other.arrLen;
	this->copy(other);
	return *this;
}

template<class T>
Set<T>& Set<T>::operator=(Set&& other) {
	if (this == &other)
		return *this;

	this->arr = other.arr;
	this->arrLen = other.arrLen;
	other.arr = nullptr;
	other.arrLen = 0;

	return *this;
}

template<class T>
Set<T>:: ~Set() {
	this->dispose();
}

template<class T>
void Set<T>::add(const T& other) noexcept(false) {
	if (checkForAdding(other)) {
		throw InvalidAdd();
	}

	if (this->arr == nullptr)
		this->arr = new T * [1];
	else
		realloc(this->arrLen + 1);

	this->arr[this->arrLen] = dynamic_cast<T*>(other.clone());
	this->arrLen++;
}

template<class T>
bool Set<T>::tryAdd(const T& other) noexcept {
	if (checkForAdding(other)) {
		std::cout << "Neuspjesno dodavanje!" << std::endl;
		return false;
	}

	if (this->arr == nullptr)
		this->arr = new T * [1];
	else
		realloc(this->arrLen + 1);

	this->arr[this->arrLen] = dynamic_cast<T*>(other.clone());
	this->arrLen++;

	return true;
}

template<class T>
void Set<T>::remove(const T& other) noexcept(false) {
	int i;
	for (i = 0; i < arrLen && *this->arr[i] != other; i++) {
		if (*this->arr[i] == other)
			break;
	}

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

template<class T>
bool Set<T>::tryRemove(const T& other) noexcept {
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

template<class T>
void Set<T>::dispose() {
	for (size_t i = 0; i < this->arrLen; i++)
		delete this->arr[i];

	delete[] this->arr;
}

template<class T>
void Set<T>::copy(const Set& other) {
	for (int i = 0; i < other.arrLen; i++) {
		this->arr[i] = dynamic_cast<T*>(other.arr[i]->clone());
	}
}

template<class T>
bool Set<T>::checkForAdding(const T& other) const {
	for (int i = 0; i < this->arrLen; i++)
		if (*this->arr[i] == other)
			return true;

	return false;
}

template<class T>
void Set<T>::realloc(size_t newCapacity) {
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
*/
/*template<class T>
void Set<T>::forEach(const std::function<void(T&)>&) {
	for (int i = 0; i < this->arrLen; i++) {
		f(*this->arr[i]);
	}
}

template<class T>
void Set<T>::forEach(const std::function<void(const T&)>& f) const {
	for (int i = 0; i < this->arrLen; i++) {
		f(*this->arr[i]);
	}
}*/

/*template<class T>
void Set<T>::print() const {
	//for (size_t i = 0; i < this->arrLen; i++)
		//std::cout << *this->arr[i];
}*/