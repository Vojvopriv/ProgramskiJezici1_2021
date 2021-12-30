#pragma once
#include "IObject.h"
#include "UnlimitedSortedSet.h"
#include "UnlimitedUnsortedSet.h"

class UCSet : public UUSet {
private:
	bool comparePerimeter = true;
public:
	UCSet(bool comparePerimeter);
	bool operator==(const UCSet& other) const;
	bool operator!=(const UCSet& other) const;
	bool operator>=(const UCSet& other) const;
	bool operator>(const UCSet& other) const;
	bool operator<=(const UCSet& other) const;
	bool operator<(const UCSet& other) const;

	virtual void transformElements(std::function<IObject* (const IObject&)>f) override;
	virtual ICollection* transformToNewCollection(std::function<IObject* (const IObject&)>) const override;
	virtual ICollection* clone() const override;
private:
	bool helpFunction(const UCSet& other) const;
};