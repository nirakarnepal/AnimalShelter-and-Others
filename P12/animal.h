#ifndef __ANIMAL_H
#define __ANIMAL_H

#include <iostream>

enum class Gender{FEMALE, MALE};
std::string to_string(Gender gender);
std::ostream& operator<<(std::ostream& ost, const Gender& gender);

class Animal {
  public:
    Animal(std::string name, Gender gender, int age);
    virtual ~Animal();
    Animal(std::istream& ist);
    virtual void save(std::ostream& ost);
    static Animal* make_animal(std::istream& ist);

    virtual std::string family() const = 0;
    virtual std::string breed() const = 0;
    std::string name() const;
    Gender gender() const;
    int age() const;

    virtual std::string to_string() const;
    friend std::ostream& operator<<(std::ostream& ost, const Animal& animal);
  protected:
    std::string _name;
    Gender _gender;
    int _age;
};

#endif

