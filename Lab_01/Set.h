#pragma once

namespace Numbers {
	class Set {

	private:
		int arraySize;
		int arrayCapacity;
		int* array;
	public:
		Set();
		Set(int, int*);
		~Set();

		int* getArray();
		int getArraySize();

		void addToArray(int);
		int deleteElement(int);
		void print() const;
		int isEqual(int*, int) const;
	private:
		int isThere(int) const;
		void reallocate();
		void reallocate(int);
	};

}