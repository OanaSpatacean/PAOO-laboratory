#ifndef FRENCHBULLDOG_H
#define FRENCHBULLDOG_H

#include <iostream>
#include <string>

class FrenchBulldog 
{
    private:
        std::string name;
        bool snore;
        bool goofy; //incapsulare -> toti membrii clasei FrenchBulldog sunt privati, ceea ce inseamna ca nu pot fi accesati direct din afara clasei

    public:
        //constructor pentru initializarea atributelor buldogului 
        FrenchBulldog(const std::string &name, bool snore, bool goofy)
            : name(name), snore(snore), goofy(goofy)  //initializarea membrilor din constructor
        {
            std::cout <<"French bulldog created: "<<name<<std::endl; //mesaj in constructor la iesirea standard, pt a verifica ca este creat un obiect de tip FrenchBuldog
        }

        //metoda pentru afisarea caracteristicilor buldogului, data ca exemplu de incapsulare
        //metoda permite accesul la atributele private printr-o metoda publica, fara a expune direct membrii interni ai clasei
        void display() const 
        {
            std::cout<<name<<"'s characteristics:\n";

            if (snore) 
            {
                std::cout<<" Snore: A lot\n";
            } 
            else 
            {
                std::cout<<" Snore: Only a little\n";
            }

            if (goofy) 
            {
                std::cout<<" Goofy: Very\n";
            } 
            else 
            {
                std::cout<<" Goofy: It's just a sleepy little dog\n";
            }

            std::cout<<std::endl;
        }
};

#endif 
