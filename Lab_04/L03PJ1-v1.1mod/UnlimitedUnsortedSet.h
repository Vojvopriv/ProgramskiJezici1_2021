#pragma once
#include "ICollection.h"

class UUSet : virtual public ICollection {
protected:
	size_t arrLen;
	IObject **arr;
public:
	UUSet();
	UUSet(const UUSet&);
	UUSet(UUSet&& other);
	UUSet& operator=(const UUSet&);
	UUSet& operator=(UUSet&&);
	virtual ~UUSet();

	virtual bool add(const IObject&) override;
	virtual bool remove(const IObject&) override;
	virtual void forEach(const std::function<void(IObject&)>&) override;
	virtual void forEach(const std::function<void(const IObject&)>&) const override;
	virtual void print(std::ostream& os) const override;
	virtual bool compareSets(const ICollection& other) const override;
	//UUSet filterElementsUUSet(const std::string&) const;
	virtual ICollection* filterElements(const std::string&) const override;
	virtual size_t size() const override;
	IObject** getObjects() const;
	virtual void transformElements(std::function<IObject* (const IObject&)>f) override;
	virtual ICollection* transformToNewCollection(std::function<IObject* (const IObject&)>) const override;
	virtual ICollection* clone() const override;
protected:
	void helpForTransform(std::function<IObject* (const IObject&)>f, ICollection* other) const;
	void copy(const UUSet& other);
	void dispose();
private:
	bool helpForSort(const IObject&, const IObject&) const;
	void realloc(size_t newCapacity);
	bool checkForAdding(const IObject&);

};