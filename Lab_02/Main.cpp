#include "Set.h"
#include "Rectangle.h"

int main() {

    Rectangle r1(1, 1, 1, 1);
    Rectangle r2(2, 2, 2, 2);


    Rectangle rObuhvatni = r1 + r2;     // rObuhvatni je najmanji pravougaonik u koga staju r1 i r2
    r1 *= 16;                           // r1 skaliran sa 16 (Stranice izduzene 4 puta)
    Rectangle r4 = r2 * 4;              // Moze i 4 * r2
    Rectangle r5 = r2 & r2;             // r5 je presjek pravougaonika r2 i r3

    r2.printRectangle();


    Set s1;

    s1 += r1; s1 += r2; s1 -= r1;

    std::cout << s1;

    return 0;
}
