#pragma once
#include <functional>
#include "IObject.h"

class IEnumerable {
public:
	virtual void forEach(const std::function<void(IObject&)>&) = 0;
	virtual void forEach(const std::function<void(const IObject&)>&) const = 0;
	virtual ~IEnumerable() = 0 {}
};
