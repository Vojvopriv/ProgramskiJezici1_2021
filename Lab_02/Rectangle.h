#pragma once

class Rectangle {
private:
    //Koordinate pocetne tacke pravougaonika (donja lijeva npr.), duzina i visina
    double x;
    double y;
    double length;
    double height;

public:
    Rectangle(double x = 0.0, double y = 0.0, double length = 0.0, double height = 0.0);

    double getX() const;
    double getY() const;
    double getLength() const;
    double getHeight() const;

    void printRectangle();

    friend Rectangle operator+ (const Rectangle&, const Rectangle&);
    Rectangle& operator+= (const Rectangle&);

    friend Rectangle operator* (double, const Rectangle&);
    friend Rectangle operator* (const Rectangle&, double);
    friend Rectangle& operator*= (Rectangle&, const double);
    
    friend Rectangle operator& (const Rectangle&, const Rectangle&);
    Rectangle& operator&= (const Rectangle&);

    Rectangle& operator= (const Rectangle&);   // const return value -- Vraca rvalue i time zabranjuje visestruke dodjele i neke slozene izraze 
                                                     // pri pozivu operatora


    bool operator== (const Rectangle&) const;
    bool operator!= (const Rectangle&) const;
    //bool operator> (const Rectangle&) const;
    //bool operator>= (const Rectangle&) const;
    //bool operator< (const Rectangle&) const;
    //bool operator<= (const Rectangle&) const;
};