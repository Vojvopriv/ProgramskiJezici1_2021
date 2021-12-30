#pragma once
#include "IObject.h"
#include "UnlimitedUnsortedSet.h"

class USSet : virtual public UUSet {
private:
	bool comparePerimeter = true;
public:
	USSet(bool comparePerimeter);
	virtual ~USSet() {}
	virtual bool compareSets(const ICollection& other) const override;
	//IObject* quickSearch(const IObject& find) const;
	virtual void transformElements(std::function<IObject* (const IObject&)>f) override;
	virtual ICollection* transformToNewCollection(std::function<IObject* (const IObject&)>) const override;
	virtual ICollection* clone() const override;
protected:
	//void copy(const USSet& other);
	//void sortElements() const;
};