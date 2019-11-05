#ifndef __ANIMAL_H
#define __ANIMAL_H

#include <vector>
#include "animal.h"

enum Gender
{
     male, female
};

const std::vector<std::string> gender_string = {"male", "female"};


class  Animal{

    protected:
        std::string _name;
        Gender _gender;
        int _age;

    public:
        Animal(Dog_breed breed, std::string name, Gender gender, int age);
        ~Animal();
        std::string family();
        std::string breed();
        std::string name();    //getters
        Gender gender();   
        int age();
        std::string to_string();

};
//std::ostream& operator<<(std::ostream& ost, const Dog& dog);
#endif
