#pragma once
#include "UnlimitedSortedSet.h"
#include "UnlimitedComparableSet.h"

class USCSet : virtual public UCSet {
private:
	bool comparePerimeter = true;
public:
	USCSet(bool comparePerimeter) : UCSet(comparePerimeter) {
		this->setSortElements = true;
		this->comparePerimeter = comparePerimeter;
	}

	virtual void transformElements(std::function<IObject* (const IObject&)>f) override;
	virtual ICollection* transformToNewCollection(std::function<IObject* (const IObject&)>) const override;
	virtual ICollection* clone() const override;
};