#pragma once
#include "IObject.h"

class IEquatable {
public:
	/*virtual bool equals(const IEquatable& other) const {
		if (this == &other)
			return true;

		return false;
	}*/

	virtual bool operator==(const IEquatable& other) const = 0;
	
	virtual bool operator!=(const IEquatable& other) const {
		return !(*this == other);
	}
	virtual bool operator<=(const IEquatable& other) const = 0;
	
	virtual bool operator>=(const IEquatable& other) const {
		return !(*this <= other);
	}
	
	virtual bool operator<(const IEquatable& other) const = 0;
	
	virtual bool operator>(const IEquatable& other) const {
		return !(*this < other);
	}

	virtual ~IEquatable() = 0 {}
};