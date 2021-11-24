#pragma once

#include "Rectangle.h"
#include <iostream>

class Set {
private:
    int arraySize;
    int capacity;
    Rectangle* arr;

public:
    Set();
    Set(int arrSize, int cap, Rectangle* arr);
    Set(const Set&);
    ~Set();

    Set& operator+=(const Rectangle&);
    Set& operator-=(const Rectangle&);
    friend std::ostream& operator<<(std::ostream&, const Set&);
    
    bool operator==(const Set&) const;
    bool operator!=(const Set&) const;
    bool operator>(const Set&) const;
    bool operator>=(const Set&) const;
    bool operator<(const Set&) const;
    bool operator<=(const Set&) const;

private:
    void realloc();
    void realloc(int);
    bool isInSet(const Rectangle&, int*) const;
    bool isInSet(const Rectangle&) const;
    bool shouldShrink() const;
    Set copySet() const;
};