#include "Set.h"
#include "Rectangle.h"

int main() {

    Rectangle r1(1, 1, 3, 2);
    Rectangle r2(2, 2, 2, 2);


    Rectangle rObuhvatni = r1 + r2;     // rObuhvatni je najmanji pravougaonik u koga staju r1 i r2   
    Rectangle r3 = r1 * 4;              // Moze i 4 * r1
    Rectangle r4 = r2 & r1;             // r4 je presjek pravougaonika r2 i r1

                                        // Definisano je i r1 += r2, r1 *= r2, r1 &= r2, r1 = r2

   
    
    Set s1;

    s1 += r1; s1 += r2; s1 -= r1;    
    std::cout << s1;
    

    return 0;
}
