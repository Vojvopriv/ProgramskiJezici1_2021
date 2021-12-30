#pragma once
#include "IObject.h"

class IEquatable {
public:
	virtual bool operator==(const IEquatable& other) const = 0;
	
	virtual bool operator!=(const IEquatable& other) const {
		return !(*this == other);
	}
	
	virtual bool operator>=(const IEquatable& other) const = 0;
	
	virtual bool operator<=(const IEquatable& other) const {
		return !(*this >= other);
	}
	
	virtual bool operator>(const IEquatable& other) const = 0;
	
	virtual bool operator<(const IEquatable& other) const {
		return !(*this > other);
	}
};