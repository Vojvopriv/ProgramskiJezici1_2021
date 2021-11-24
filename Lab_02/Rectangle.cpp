#include "Rectangle.h"
#include <cmath>      //sqrt
#include <iostream>

Rectangle::Rectangle(double x, double y, double length, double height) : x(x), y(y), length(length), height(height) {}


double Rectangle::getX() const { return this->x; }
double Rectangle::getY() const { return this->y; }


//Globalna funkcija koja vraca manji od dva broja
inline const double min(const double x, const double y)
{
    return (x < y) ? x : y;
}

//Globalna funkcija koja vraca manji od dva broja
inline const double max(const double x, const double y)
{
    return (x > y) ? x : y;
}


double Rectangle::getLength() const {
    return this->length;
}

double Rectangle::getHeight() const {
    return this->height;
}


//Globalna funkcija (prijatelj klasi Rectangle) koja vraca najmanji pravougaonik koji obuhvata oba
Rectangle operator+(const Rectangle &a, const Rectangle &b) {
    Rectangle r;

    r.x = min(a.x, b.x);
    r.y = min(a.y, b.y);

    r.length = max(a.x + a.length, b.x + b.length) - r.x;
    r.height = max(a.y + a.height, b.y + b.height) - r.y;

    return r;
}

const Rectangle& Rectangle::operator+= (const Rectangle& r2)
{
    Rectangle r;

    r.x = min(this->x, r2.x);
    r.y = min(this->y, r2.y);

    r.length = max(this->x + this->length, r2.x + r2.length) - r.x;
    r.height = max(this->y + this->height, r2.y + r2.height) - r.y;

    *this = r;
    
    return *this;
}


//Globalna funkcija (prijatelj klasi Rectangle) koja skalira pravougaonik u odnosu na centar - definisana na 3 nacina
const Rectangle& operator*=(Rectangle &r, const double d) {

    double xcentar = r.x + r.length / 2;
    double ycentar = r.y + r.height / 2;


    r.length *= sqrt(d);
    r.height *= sqrt(d);

    
    r.x = xcentar - r.length / 2;
    r.y = ycentar - r.height / 2;
    
    return r;
}

Rectangle operator*(const Rectangle& r, double d) {
    Rectangle r1;

    r1.length = r.length * sqrt(d);
    r1.height = r.height * sqrt(d);

    double xcentar = r.x + r.length / 2;
    double ycentar = r.y + r.height / 2;

    r1.x = xcentar - r1.length / 2;
    r1.y = ycentar - r1.height / 2;

    return r1;
}

Rectangle operator*(double d, const Rectangle& r)
{
    return r * d;
}


//Globalna funkcija (Prijatelj klasi Rectangle) koja vraca presjek dva pravougaonika
Rectangle operator&(const Rectangle& r1, const Rectangle& r2) {
    Rectangle r;

    if (r2.x >= r1.x + r1.length || r2.x + r2.length <= r1.x)
    {
        std::cout << "Nema presjeka"; return r;
    }
    if (r2.y >= r1.y + r1.height || r2.y + r2.height <= r1.y)
    {
        std::cout << "Nema presjeka"; return r;
    }


    if (r2.x >= r1.x) {

        r.x = r2.x;
        if (r2.x + r2.length <= r1.x + r1.length)
            r.length = r2.length;
        else
            r.length = r1.x + r1.length - r2.x;
        //R.length i r.x su isti u oba ova dolje slucaja pa ih pisem prije


        if (r2.y >= r1.y) {
            r.y = r2.y;

            if (r2.y + r2.height <= r1.y + r1.height)
                r.height = r2.height;
            else
                r.height = r1.y + r1.height - r2.y;

        }
        else
        {
            r.y = r1.y;

            if (r2.y + r2.height <= r1.y + r1.height)
                r.height = r2.y + r2.height - r1.y;
            else
                r.height = r1.height;
        }
    }
    else
    {
        r.x = r1.x;
        if (r2.x + r2.length <= r1.x + r1.length)
            r.length = r2.x + r2.length - r1.x;
        else
            r.length = r1.length;
        //R.length i r.x su isti za ova dva slucaja dolje

        if (r2.y >= r1.y) {
            r.y = r2.y;

            if (r2.y + r2.height <= r1.y + r1.height)
                r.height = r2.height;
            else
                r.height = r1.y + r1.height - r2.y;
        }
        else
        {
            r.y = r1.y;

            if (r2.y + r2.height <= r1.y + r1.height)
                r.height = r2.y + r2.height - r1.y;
            else
                r.height = r1.height;
        }
    }
    return r;
}

const Rectangle& Rectangle::operator&=(const Rectangle& r)
{
    *this = *this & r;

    return *this;
}


//Funkcija clanica koja vrsi provjeru jednakosti dva pravougaonika
bool Rectangle::operator==(const Rectangle& r) const
{

    if (this->x == r.x && this->y == r.y && this->height == r.height && this->length == r.length)
        return true;
    else return false;
}

bool Rectangle::operator!=(const Rectangle& r) const
{
    if (*this == r) return false;
    else return true;
}


const Rectangle& Rectangle::operator=(const Rectangle& r)
{
    this->x = r.x;
    this->y = r.y;
    this->height = r.height;
    this->length = r.length;

    return *this;
}


//Ispis pravougaonika
void Rectangle::printRectangle()
{
    std::cout << "Pocetna koordinata: (x,y) = (" << this->x << ", " << this->y << ") " << std::endl;
    std::cout << "Duzina: " << this->length << "  Sirina: " << this->height << std::endl << std::endl;
}

