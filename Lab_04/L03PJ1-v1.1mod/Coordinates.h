#pragma once

class Coordinate {
private:
	double x;
	double y;

public:
	Coordinate(double x = 0, double y = 0);
	bool operator==(Coordinate c) const;
	double getXCoordinate() const;
	double getYCoordinate() const;
	bool isXBigger(Coordinate c) const;
	bool isYBigger(Coordinate c) const;
};
