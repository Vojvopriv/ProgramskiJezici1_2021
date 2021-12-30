#pragma once

class ICloneable {
public:
	virtual ICloneable* clone() const = 0;
	virtual ~ICloneable() = 0 {}
};