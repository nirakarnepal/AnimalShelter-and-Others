#ifndef __Rabbit_H
#define __Rabbit_H

#include "animal.h"

enum class Rabbit_breed {
    CALIFORNIA_WHITE,
    CHINCHILLA,
    FLEMISH_CHINCHILLA,
    GIANT_CHINCHILLA,
    HARLEQUIN,
    LIONHEAD,
    LOP,
    MIX,
    NEW_ZEALAND,
    POLISH,
    REX,
    SILVER_FOX, 
    VIENNA_WHITE,
};
constexpr Rabbit_breed rabbit_breeds[] = {
    Rabbit_breed::CALIFORNIA_WHITE,
    Rabbit_breed::CHINCHILLA,
    Rabbit_breed::FLEMISH_CHINCHILLA,
    Rabbit_breed::GIANT_CHINCHILLA,
    Rabbit_breed::HARLEQUIN,
    Rabbit_breed::LIONHEAD,
    Rabbit_breed::LOP,
    Rabbit_breed::MIX,
    Rabbit_breed::NEW_ZEALAND,
    Rabbit_breed::POLISH,
    Rabbit_breed::REX,
    Rabbit_breed::SILVER_FOX, 
    Rabbit_breed::VIENNA_WHITE,
};
// Rabbit implements to_string with a private std::map
std::string to_string(const Rabbit_breed& breed);
std::ostream& operator<<(std::ostream& ost, const Rabbit_breed& breed);

class Rabbit : public Animal {
  public:
    Rabbit(Rabbit_breed breed, std::string name, Gender gender, int age);
    virtual ~Rabbit();
    Rabbit(std::istream& ist);
    void save(std::ostream& ost) override;
    virtual std::string family() const override;
    virtual std::string breed() const override;
  private:
    Rabbit_breed _breed;
};

#endif
