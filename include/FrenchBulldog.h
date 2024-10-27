#ifndef FRENCHBULLDOG_H
#define FRENCHBULLDOG_H

#include <iostream>
#include <string>

class FrenchBulldog 
{
    private:
        std::string name;
        bool snore;
        bool goofy; 
        std::string *destr;

    public:
        //constructor pentru initializarea atributelor buldogului 
        FrenchBulldog(const std::string &name, bool snore, bool goofy)
            : name(name), snore(snore), goofy(goofy)  
        {
            destr = new std::string("Woof woof! I want to play!");
            std::cout<<"French bulldog is awake: "<<name<<std::endl;
        }

        //destructor pentru eliberarea memoriei de pe heap (memorie alocată dinamic)
        ~FrenchBulldog() 
        {
            delete destr; 
            std::cout<<"French bulldog feel asleep: "<<name<<std::endl;
        }

        //copy constructor pentru copierea atributelor și a resurselor alocate dinamic
        FrenchBulldog(const FrenchBulldog &exactCopyOfFrenchBulldog)
            : name(exactCopyOfFrenchBulldog.name), snore(exactCopyOfFrenchBulldog.snore), goofy(exactCopyOfFrenchBulldog.goofy) 
        {          
            destr = new std::string(*(exactCopyOfFrenchBulldog.destr));
            std::cout<<"French bulldog copied (because it is so cute): "<<name<<std::endl;
        }

        //move constructor pentru mutarea resurselor fără a crea duplicat
        FrenchBulldog(FrenchBulldog &&anotherFrenchBulldog) noexcept
            : name(std::move(anotherFrenchBulldog.name)), snore(anotherFrenchBulldog.snore), goofy(anotherFrenchBulldog.goofy), destr(anotherFrenchBulldog.destr) 
        { 
            anotherFrenchBulldog.destr = nullptr;
            std::cout<<"French bulldog moved: "<<name<<std::endl;
        }

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

            std::cout<<name<<" says: "<<*destr<<std::endl;

            std::cout<<std::endl;
        }
};

#endif 
