#ifndef __CAT_H
#define __CAT_H

#include "animal.h"

// List of cat breeds, conversion to/from string and stream, and iteration
enum class Cat_breed {
    PERSIAN,
    RUSSIAN,
    BENGAL,
    BRITISH,
    SIAMESE,
    MAINE,
    COON, 
    SPHYNX,
    RAGDOLL,
    MUNCHKIN,
    BIRMAN,
    SCOTTISH,
};
constexpr Cat_breed cat_breeds[] = {
    Cat_breed::PERSIAN,
    Cat_breed::RUSSIAN,
    Cat_breed::BENGAL,
    Cat_breed::BRITISH,
    Cat_breed::SIAMESE,
    Cat_breed::MAINE,
    Cat_breed::COON, 
    Cat_breed::SPHYNX,
    Cat_breed::RAGDOLL,
    Cat_breed::MUNCHKIN,
    Cat_breed::BIRMAN,
    Cat_breed::SCOTTISH,
};
std::string to_string(const Cat_breed& breed);
std::ostream& operator<<(std::ostream& ost, const Cat_breed& breed);

// Class Cat with overrides for family and breed
class Cat : public Animal {
  public:
    Cat(Cat_breed breed, std::string name, Gender gender, int age);
    virtual ~Cat();
    virtual std::string family() const override;
    virtual std::string breed() const override;
  private:
    Cat_breed _breed;
};

#endif
