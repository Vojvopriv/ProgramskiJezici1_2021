#include <iostream>
#include "Coordinates.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include "Polygon.h"
/*#include "ICollection.h"
#include "UnlimitedUnsortedSet.h"
#include "UnlimitedSortedSet.h"
#include "UnlimitedComparableSet.h"
#include "UnlimitedSortedAndComparableSet.h"
#include "IObject.h"*/
#include "GenericSet.h"
#include "SortedSet.h"
#include "UnlimitedSortedSet.h"

/*IObject* tryTransform(const IObject& object) {
	const Circle* c = dynamic_cast<const Circle*>(&object);

	if (c != nullptr) {
		Coordinate A(c->getCenter().getXCoordinate() - c->getR(), c->getR() / 2);
		Coordinate D(c->getCenter().getXCoordinate() + c->getR(), c->getR() * 2);
		Rectangle *r = new Rectangle(A, D);
		return r;
	}
	IObject* clone = dynamic_cast<IObject*>(object.clone());
	return clone;
	//return &object;
}*/

int main() {
	Coordinate A(0, 0);
	Coordinate D(2, 2);
	Coordinate C(5, 5);
	Coordinate A1(2, 2);
	Coordinate D1(12, 12);

	Rectangle r(A, D);
	Rectangle r2(A1, D1);

	Coordinate F(6, 6); 
	Coordinate F1(0, 0);

	Square s(F1, F);
	Square s2(A, C);
	Square s3(A, D1);

	Circle c(A, 2.2);
	Circle c2(C, 5.5);

	Polygon p(0, nullptr);

	Rectangle r5(A, D);

	Coordinate A4(4, 1);
	Coordinate D4(3, 8);
	Coordinate C4(3, 4);
	Coordinate F4(7, 8);

	Coordinate* array = new Coordinate[4];
	array[0] = A4;
	array[1] = D4;
	array[2] = C4;
	array[3] = F4;

	Polygon pokusaj(4, array);

	Rectangle r3(A4, D4);

	Set<IObject> set;

	set.add(r);
	set.add(s);
	set.add(pokusaj);
	set.remove(s);


	set.print();

	SortedSet sortedSet(false);
	
	sortedSet.tryAdd(r);
	sortedSet.add(r2);
	sortedSet.add(r3);
	

	//sortedSet.print();

	/*USSet setr;
	setr.add(s);
	setr.add(r);
	setr.add(r2);
	setr.add(pokusaj);
	*/


	return 0;
}