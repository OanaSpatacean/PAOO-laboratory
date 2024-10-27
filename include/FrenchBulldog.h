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
        std::string *destr; //pointer alocat dinamic pe heap care va fi eliberat de destructor

    public:
        //constructor pentru initializarea atributelor buldogului 
        FrenchBulldog(const std::string &name, bool snore, bool goofy)
            : name(name), snore(snore), goofy(goofy)  //initializarea membrilor din constructor
        {
            //alocare memorie pe heap pentru destr și initializarea lui
            destr = new std::string("Woof woof! I want to play!");
            std::cout<<"French bulldog is awake: "<<name<<std::endl; //mesaj in constructor la iesirea standard, pt a verifica ca este creat un obiect de tip FrenchBuldog
        }

        //destructor pentru eliberarea memoriei de pe heap (memorie alocată dinamic)
        ~FrenchBulldog() 
        {
            delete destr; 
            std::cout<<"French bulldog feel asleep: "<<name<<std::endl; //obiectul a fost distrus si resursele sale au fost eliberate

            //la apelarea move constructorului, deoarece name a fost mutat, este posibil sa nu mai aiba continut valid, rezultand în faptul ca este gol sau inițializat implicit
        }

        //copy constructor pentru copierea atributelor și a resurselor alocate dinamic
        FrenchBulldog(const FrenchBulldog &exactCopyOfFrenchBulldog)
            : name(exactCopyOfFrenchBulldog.name), snore(exactCopyOfFrenchBulldog.snore), goofy(exactCopyOfFrenchBulldog.goofy) 
        {
            //alocare de memorie noua pe heap pentru destr pentru a evita folosirea aceluiași pointer în ambele obiecte
            destr = new std::string(*(exactCopyOfFrenchBulldog.destr));
            std::cout<<"French bulldog copied (because it is so cute): "<<name<<std::endl;
        }

        //move constructor pentru mutarea resurselor fără a crea duplicat
        FrenchBulldog(FrenchBulldog &&anotherFrenchBulldog) noexcept
            : name(std::move(anotherFrenchBulldog.name)), snore(anotherFrenchBulldog.snore), goofy(anotherFrenchBulldog.goofy), destr(anotherFrenchBulldog.destr) 
        { //std::move() transforma obiectul intr-o referinta rvalue
          //name în obiectul FrenchBulldog nou creat acum conține datele care erau în anotherFrenchBulldog.name
            anotherFrenchBulldog.destr = nullptr; //setez pointerul destr al sursei (anotherFrenchBulldog) pe nullptr pentru a preveni eliberarea duplicată
            std::cout<<"French bulldog moved: "<<name<<std::endl;
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

            std::cout<<name<<" says: "<<*destr<<std::endl;//afiseaza valoarea la care pointează destr

            std::cout<<std::endl;
        }
};

#endif 
