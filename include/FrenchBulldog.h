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
        std::string *talk;

    public:
        //constructor pentru initializarea atributelor buldogului 
        FrenchBulldog(const std::string &name, bool snore, bool goofy) 
        {
            this->name = name;
            this->snore = snore;
            this->goofy = goofy;

            this->talk = new std::string("Woof woof! I want to play!");
            std::cout<<"French bulldog is awake: "<<name<<std::endl;
        }

        //destructor pentru eliberarea memoriei de pe heap (memorie alocată dinamic)
        ~FrenchBulldog() 
        {
            delete talk; 
            std::cout<<"French bulldog feel asleep: "<<name<<std::endl;
        }

        //copy constructor pentru copierea atributelor și a resurselor alocate dinamic
        FrenchBulldog(const FrenchBulldog &exactCopyOfFrenchBulldog)
        {   
            this->name = exactCopyOfFrenchBulldog.name;
            this->snore = exactCopyOfFrenchBulldog.snore;
            this->goofy = exactCopyOfFrenchBulldog.goofy; 

            talk = new std::string(*(exactCopyOfFrenchBulldog.talk));
            
            std::cout<<"French bulldog copied (because it is so cute): "<<name<<std::endl;
        }

        //copy assignment operator
        FrenchBulldog& operator=(const FrenchBulldog &exactCopyOfFrenchBulldog)
        {
            if (this == &exactCopyOfFrenchBulldog) {
                return *this; 
            }

            delete talk; 

            this->name = exactCopyOfFrenchBulldog.name;
            this->snore = exactCopyOfFrenchBulldog.snore;
            this->goofy = exactCopyOfFrenchBulldog.goofy;

            talk = new std::string(*(exactCopyOfFrenchBulldog.talk)); 

            std::cout<<"Copy assignment operator was called: "<<name<<std::endl;
            return *this;
        }

        //move constructor pentru mutarea resurselor fără a crea duplicat
        FrenchBulldog(FrenchBulldog &&anotherFrenchBulldog) noexcept
        { 
            this->name = anotherFrenchBulldog.name;
            this->snore = anotherFrenchBulldog.snore;
            this->goofy = anotherFrenchBulldog.goofy;

            this->talk = anotherFrenchBulldog.talk;
            anotherFrenchBulldog.talk = nullptr;

            std::cout<<"French bulldog moved: "<<name<<std::endl;
        }

        //move assignment operator
        FrenchBulldog& operator=(FrenchBulldog &&anotherFrenchBulldog) noexcept
        {
            if (this == &anotherFrenchBulldog) 
            {
                return *this; 
            }

            delete talk;

            this->name = anotherFrenchBulldog.name;
            this->snore = anotherFrenchBulldog.snore;
            this->goofy = anotherFrenchBulldog.goofy;

            this->talk = anotherFrenchBulldog.talk; 
            anotherFrenchBulldog.talk = nullptr; 

            std::cout<<"Move assignment operator was called: "<<name<<std::endl;
            return *this;
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

            std::cout<<name<<" says: "<<*talk<<std::endl;

            std::cout<<std::endl;
        }
};

#endif 
