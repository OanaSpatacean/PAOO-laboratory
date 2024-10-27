#include "FrenchBulldog.h"

int main() {
    //constructor normal
    FrenchBulldog bulldog1("Hera", true, true);//crearea unui obiect de tip FrenchBulldog folosind constructorul pentru a initializa atributele name, snore si goofy
    bulldog1.display();
    
    FrenchBulldog bulldog2("Toby", false, false);
    bulldog2.display();

    //copiere folosind copy constructorul
    FrenchBulldog bulldog3 = bulldog1;
    bulldog3.display();

    //mutare folosind move constructorul
    FrenchBulldog bulldog4 = std::move(bulldog2);
    bulldog4.display();

    return 0;
}
