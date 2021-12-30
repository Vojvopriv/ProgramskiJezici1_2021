#pragma once
#include "IObject.h"
#include "UnlimitedUnsortedSet.h"

class USSet : virtual public UUSet {
protected:
	bool sortByPerimeter = true;
	//double (*pf)(void); PRISTUP FUNKCIJI TEZAK
public:
	USSet(bool sortByPerimeter = true);
	
	USSet(const USSet&);
	USSet(USSet&& other);
	USSet& operator=(const USSet&);
	USSet& operator=(USSet&&);

	virtual bool add(const IObject&) override;

	virtual bool compareSets(const ICollection& other) const override;
	virtual void transformElements(std::function<IObject* (const IObject&)>f) override;
	virtual ICollection* transformToNewCollection(std::function<IObject* (const IObject&)>) const override;
	virtual ICollection* clone() const override;

	IObject* quickSearch(const IObject& find) const;

protected:
	void copy(const USSet& other);
private:
	void sortElements() const;
	//void helpSorting(const IObject& o1, const IObject& o2) const;
};