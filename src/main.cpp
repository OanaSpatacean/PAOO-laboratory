#include "FrenchBulldog.h"

int main() {
    //constructor normal
    FrenchBulldog bulldog1("Hera", true, true);
    bulldog1.display();
    
    FrenchBulldog bulldog2("Toby", false, false);
    bulldog2.display();

    //copiere folosind copy constructorul
    FrenchBulldog bulldog3 = bulldog1; //Hera
    bulldog3.display();

    bulldog1 = bulldog2; //copy assignment operator //Toby
    bulldog1.display();

    //mutare folosind move constructorul
    FrenchBulldog bulldog4 = std::move(bulldog2); //Toby
    bulldog4.display();

    bulldog2=std::move(bulldog3);//move assignment operator //Hera
    bulldog4.display();

    return 0;
}
