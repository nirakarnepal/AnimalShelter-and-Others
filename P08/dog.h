#ifndef __DOG_H
#define __DOG_H

#include <vector>
#include "animal.h"

enum Dog_breed
{
   labrador, retriever, shepeard , chihuahua, pug, huskey, bulldog, beagle, boxer, newfoundland
};

const std::vector<std::string> dog_breed_string = {"labrador", "retriever, "shepherd" , "chihuahua", "pug", "huskey", "bulldog", "beagle", "boxer", "newfoundland"};


class Dog: public animal{

    private:
        Dog_breed _breed;

    public:
        Dog(Dog_breed breed, std::string name, Gender gender, int age);
        ~Dog();
        std::string family();
        std::string breed();


};
//std::ostream& operator<<(std::ostream& ost, const Dog& dog);
#endif
