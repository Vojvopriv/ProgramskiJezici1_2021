#pragma once
#include "IEnumerable.h"
#include "IPrintable.h"

class ICollection : virtual public IEnumerable, virtual public IPrintable {
public:
	virtual ICollection* operator+(const IObject& other) const final {
		ICollection* copy = dynamic_cast<ICollection*>(this->clone());
		copy->add(other);
		return copy;
	}

	/*virtual ICollection* operator+(const IObject& other) final {
		//ICollection* copy = dynamic_cast<ICollection*>(this->clone());
		this->add(other);
		return this;
	}*/

	virtual ICollection& operator+=(const IObject& other) final
	{
		this->add(other);
		return *this;
	};

	/*virtual ICollection* operator-(const IObject& other) const final {
		ICollection* copy = dynamic_cast<ICollection*>(this->clone());
		copy->remove(other);
		return copy;
	}*/

	virtual ICollection& operator-=(const IObject& other) final
	{
		this->remove(other);
		return *this;
	};

	virtual bool add(const IObject&) = 0;
	virtual bool remove(const IObject& other) = 0;
	virtual void print(std::ostream& os) const override = 0;
	virtual bool compareSets(const ICollection&) const = 0;
	virtual ICollection* filterElements(const std::string&) const = 0;
	virtual void transformElements(std::function<IObject* (const IObject&)>) = 0;
	virtual ICollection* transformToNewCollection(std::function<IObject* (const IObject&)>) const = 0;
	virtual size_t size() const = 0;
	virtual ICollection* clone() const = 0;
	virtual ~ICollection() = 0 {};
};