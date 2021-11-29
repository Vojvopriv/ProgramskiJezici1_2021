#include "Set.h"
#include <iostream>

Set::Set() : arraySize(0), capacity(0), arr(nullptr) {}

Set::Set(int arrSize, int cap, Rectangle* arr)
{
    this->arraySize = arrSize;
    this->capacity = cap;
    for (int i = 0; i < this->arraySize; i++) {
        this->arr[i] = arr[i];
    }
}

Set::Set(const Set& origin)
{
    arraySize = origin.arraySize;
    capacity = origin.capacity;
    arr = new Rectangle[arraySize];
    for (int i = 0; i < arraySize; i++)
        arr[i] = origin.arr[i];
}

Set::~Set()
{
    delete[] this->arr;
}


//Dodavanje pravougaonika u set
Set& Set::operator+=(const Rectangle& r)
{
    if (isInSet(r)) {
        std::cout << "Nemoguce dodati u set, vec postoji dati pravougaonik!" << std::endl;
    }
    else {
        if (this->arraySize >= this->capacity) {
            this->realloc();
        }

        this->arr[this->arraySize] = r;
        this->arraySize++;
    }

    return *this;
}

//Brisanje pravougaonika
Set& Set::operator-=(const Rectangle& r) 
{
    int index;
    if (this->arraySize == 0 || !isInSet(r, &index)) {
        std::cout << "Nemoguce ukloniti jer nema pravougaonika u nizu ili je niz prazan!" << std::endl;
        return *this;
    }

    else {
        isInSet(r, &index); //da bi se dobio indeks
        for (int i = index; i < this->arraySize; i++) {
            this->arr[i] = this->arr[i + 1];
        }

        this->arraySize--;

        if (this->shouldShrink()) {
            this->realloc(this->arraySize);
        }
    }

    return *this;
}


//Provjere jednakosti
bool Set::operator==(const Set& s) const 
{
    if (this->arraySize != s.arraySize)
        return false;                         // Ako su razlicitih dimenzija, nisu jednaki

    int br = 0;
    for (int i = 0; i < this->arraySize; i++) {
        for (int j = 0; j < this->arraySize; j++) {
            if (   this->arr[i].getX() == s.arr[j].getX()
                && this->arr[i].getY() == s.arr[j].getY()
                && this->arr[i].getHeight() == s.arr[j].getHeight()
                && this->arr[i].getLength() == s.arr[j].getLength())
                br++;
        }
    }

    if (br == this->arraySize)
        return true;
    else
        return false;
}

bool Set::operator!=(const Set& s) const
{
    if (*this == s) return false;
    else return true;
}

bool Set::operator<(const Set& s) const
{
    if (this->arraySize < s.arraySize) return true;
    else return false;
}

bool Set::operator<=(const Set& s) const
{
    if (this->arraySize <= s.arraySize) return true;
    else return false;
}

bool Set::operator>(const Set& s) const
{
    if (this->arraySize > s.arraySize) return true;
    else return false;
}

bool Set::operator>=(const Set& s) const
{
    if (this->arraySize >= s.arraySize) return true;
    else return false;
}


void Set::realloc() 
{
    this->realloc(this->capacity > 0 ? this->capacity * 2 : 1);
}

void Set::realloc(int newCap)
{
    auto* newArray = new Rectangle[newCap]();
    this->capacity = newCap;
    this->arraySize = (this->arraySize > this->capacity) ? this->capacity : this->arraySize;
    for (int i = 0; i < this->arraySize; i++)
        newArray[i] = this->arr[i];
    
    delete this->arr;
    this->arr = newArray;
}


bool Set::isInSet(const Rectangle& r, int* index) const
{
    for (int i = 0; i < this->arraySize; i++) {
        if (this->arr[i].getX() == r.getX() && this->arr[i].getY() == r.getY()
            && this->arr[i].getHeight() == r.getHeight() &&
            this->arr[i].getLength() == r.getLength()) {
            *index = i;
            return true;
        }
    }

    return false;
}

bool Set::isInSet(const Rectangle& r) const
{
    for (int i = 0; i < this->arraySize; i++) {
        if (this->arr[i].getX() == r.getX() && this->arr[i].getY() == r.getY()
            && this->arr[i].getHeight() == r.getHeight() &&
            this->arr[i].getLength() == r.getLength()) {
            return true;
        }
    }

    return false;
}

bool Set::shouldShrink() const 
{
    return this->arraySize <= this->capacity / 2;
}

Set Set::copySet() const
{
    return Set(this->arraySize, this->capacity, this->arr);
}


//Ispisuje centar, duzinu i sirinu svakog pravougaonika u setu
std::ostream& operator<<(std::ostream& os, const Set& s)
{
    for (int i = 0; i < s.arraySize; i++) {
        os << "Ispis " << i + 1 << ".pravougaonika: " << std::endl;
        os << "((" << s.arr[i].getX() + (s.arr[i].getLength())/2 << ", "<< s.arr[i].getY() + (s.arr[i].getHeight())/2
           << "), " << s.arr[i].getLength() << ", " << s.arr[i].getHeight() << ")" << std::endl;
    }
    return os;
}

