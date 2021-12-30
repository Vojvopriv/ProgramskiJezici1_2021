#pragma once
#include "IObject.h"
#include "UnlimitedSortedSet.h"
#include "UnlimitedUnsortedSet.h"

class UCSet : virtual public UUSet, virtual public IEquatable {
public:
	UCSet();
	/*bool operator==(const UCSet& other) const;
	bool operator!=(const UCSet& other) const;
	bool operator>=(const UCSet& other) const;
	bool operator>(const UCSet& other) const;
	bool operator<=(const UCSet& other) const;
	bool operator<(const UCSet& other) const;*/

	UCSet(const UCSet&);
	UCSet(UCSet&& other);
	UCSet& operator=(const UCSet&);
	UCSet& operator=(UCSet&&);

	virtual bool operator==(const IEquatable& other) const override;
	virtual bool operator<=(const IEquatable& other) const override;
	virtual bool operator<(const IEquatable& other) const override;

	virtual void transformElements(std::function<IObject* (const IObject&)>f) override;
	virtual ICollection* transformToNewCollection(std::function<IObject* (const IObject&)>) const override;
	virtual ICollection* clone() const override;
private:
	bool helpFunction(const UCSet& other) const;
};