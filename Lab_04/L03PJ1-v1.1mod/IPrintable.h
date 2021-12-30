#pragma once
#include <ostream>

class IPrintable {
protected:
	virtual void print(std::ostream& os) const = 0;
public:
	friend std::ostream& operator<<(std::ostream& os, const IPrintable& other);
	virtual ~IPrintable() = 0 {}
};