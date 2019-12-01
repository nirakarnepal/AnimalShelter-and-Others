#include "animal.h"
#include "dog.h"
#include "cat.h"
#include "rabbit.h"

// Constructors / Destructors
Animal::Animal(std::string name, Gender gender, int age)
    : _name{name}, _gender{gender}, _age{age} { }

Animal::~Animal() { }

// File I/O
Animal::Animal(std::istream& ist) {
    std::getline(ist, _name);

    std::string s;
    std::getline(ist, s);
    _gender = ((s == "male") ? Gender::MALE: Gender::FEMALE);

    ist >> _age; ist.ignore(65535, '\n');
}
void Animal::save(std::ostream& ost) {
    ost << _name << '\n';
    ost << ((_gender == Gender::FEMALE) ? "female" : "male") << '\n';
    ost << _age << '\n';
}

Animal* Animal::make_animal(std::istream& ist) {
    std::string s;
    std::getline(ist, s);
    if(s == "Dog")    return new Dog{ist};
    if(s == "Cat")    return new Cat{ist};
    if(s == "Rabbit") return new Rabbit{ist};
    throw std::runtime_error{"Invalid animal family: " + s};
}

// Getters
std::string Animal::name() const {return _name;}
Gender Animal::gender() const {return _gender;}
int Animal::age() const {return _age;}

// Convert Animal and its derived classes to a string and stream representation
std::string Animal::to_string() const {
    return _name + " (" + ::to_string(this->gender()) + ' ' + this->breed() + ' ' + this->family()
                 + ", age " + std::to_string(this->age()) + ')';
}

// Streaming I/O
std::ostream& operator<<(std::ostream& ost, const Animal& animal) {
    ost << animal.to_string();
    return ost;
}

// Convert Gender to a string and stream representation
std::string to_string(Gender gender) {return ((gender == Gender::FEMALE) ? "female" : "male");}
std::ostream& operator<<(std::ostream& ost, const Gender& gender) {
    ost << to_string(gender);
    return ost;
}

