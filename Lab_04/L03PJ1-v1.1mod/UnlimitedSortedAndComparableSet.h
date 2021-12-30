#pragma once
#include "UnlimitedSortedSet.h"
#include "UnlimitedComparableSet.h"

class USCSet : virtual public UCSet, virtual public USSet {
private:
	bool sortByPerimeter;
public:
	USCSet(bool sortByPerimeter = true) : USSet(sortByPerimeter) {
		this->sortByPerimeter = sortByPerimeter;
	}

	USCSet(const USCSet&);
	USCSet(USCSet&& other);
	USCSet& operator=(const USCSet&);
	USCSet& operator=(USCSet&&);


	virtual void transformElements(std::function<IObject* (const IObject&)>f) override;
	virtual ICollection* transformToNewCollection(std::function<IObject* (const IObject&)>) const override;
	virtual ICollection* clone() const override;
};